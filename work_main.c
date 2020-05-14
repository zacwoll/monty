#include "monty.h"

/**
 * open - opens a monty file and validates input
 * @argc: argument count
 * @filename: path of monty file
 */
void open(int argc, char *filename)
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty.file = fopen(filename, "r");
	if (!monty.file)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * read_lines - reads and executes each line of input from monty file
 */
void read_lines(void)
{
	size_t len = 0;
	ssize_t read;
	char *opcode, *data;

	while ((read = getline(&monty.line, &len, monty.file) != -1))
	{
		opcode = strtok(monty.line, " ");
		if (*opcode == '#' || *opcode == '\n')
		{}
		else if (strcmp(opcode, "push") == 0)
		{
			data = strtok(NULL, " \n");
			if (monty.is_queue)
				push_node_end(data);
			else
				push_node(data);
		}
		else
			op_switcher(&monty.stack, opcode);
		monty.line_number++;
	}
}

/**
 * op_switcher - calls the function that corresponds with the opcode
 * @stack: double ptr to head of stack
 * @opcode: opcode from current line of monty file
 */
void op_switcher(stack_t **stack, char *opcode)
{
	int i;
	char *op;
	instruction_t fncs[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_op},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", set_stack},
		{"queue", set_queue},
		{NULL, NULL}
	};

	op = strtok(opcode, "\n");
	for (i = 0; fncs[i].opcode; i++)
	{
		if (strcmp(op, fncs[i].opcode) == 0)
		{
			fncs[i].f(stack, monty.line_number);
			return;
		}
	}
	dprintf(STDERR_FILENO, "L%u: ", monty.line_number);
	dprintf(STDERR_FILENO, "unknown instruction %s\n", opcode);
	exit(EXIT_FAILURE);
}

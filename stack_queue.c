#include "monty.h"

/**
 * set_stack - sets the linked list to a stack format
 * @stack: double ptr to head of stack
 * @line_number: current line number of monty file
 */
void set_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	monty.is_queue = false;
}

/**
 * set_queue - sets the linked list to a queue format
 * @stack: double ptr to head of queue
 * @line_number: current line number of monty file
 */
void set_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	monty.is_queue = true;
}

/**
 * push_node_end - pushes a node onto the end of the linked list
 * @data: the data to be added to linked list
 */
void push_node_end(char *data)
{
	int n;
	stack_t *new, *a = monty.stack;

	if (!is_valid_input(data))
	{
		printf("invalid data: %s", data);
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", monty.line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(data);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	if (!a)
	{
		new->prev = NULL;
		monty.stack = new;
		return;
	}
	while (a->next)
	{
		a = a->next;
	}

	a->next = new;
	new->prev = a;
}

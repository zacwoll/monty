#include "monty.h"

monty_t monty;

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	init_monty();
	open(argc, argv[1]);
	read_lines();
	free_all();
	return (EXIT_SUCCESS);
}

/**
 * init_monty - initializes monty struct
 */
void init_monty(void)
{
	monty.file = NULL;
	monty.line = NULL;
	monty.stack = NULL;
	monty.line_number = 1;
	monty.is_queue = false;
}

#include "monty.h"

/**
 * free_stack - frees a stack_t stack
 * @h: ptr to the head of the stack
 */
void free_stack(stack_t *h)
{
	stack_t *temp, *current = h;

	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

/**
 * free_all - frees all mallocs and closes file
 */
void free_all(void)
{
	fclose(monty.file);
	free(monty.line);
	free_stack(monty.stack);
}

#include "monty.h"

/**
 * mod - takes the modulus of the second value from the top value of the stack
 * @stack: double ptr to the head of the stack
 * @ln: current line number of monty file
 */
void mod(stack_t **stack, unsigned int ln)
{
	stack_t *a;

	if (!(*stack) || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", ln);
		free_all();
		exit(EXIT_FAILURE);
	}
	a = (*stack)->next;
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", ln);
		free_all();
		exit(EXIT_FAILURE);
	}
	a->n = a->n % (*stack)->n;
	a = *stack;
	*stack = (*stack)->next;
	free(a);
}

/**
 * pchar - prints the data at the top of the stack as an ascii character
 * @stack: double ptr to the head of the stack
 * @ln: current line number of monty file
 */
void pchar(stack_t **stack, unsigned int ln)
{
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", ln);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n", ln);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the stack as a string, stopping at invalid values
 ** @stack: double ptr to the head of the stack
 * @ln: current line number of monty file
 */
void pstr(stack_t **stack, unsigned int ln)
{
	stack_t *current = *stack;

	(void)ln;
	while (current && current->n > 0 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}

/**
 * rotl - rotates the top of the stack to the bottom
 * @stack: double ptr to the head of the stack
 * @ln: current line number of monty file
 */
void rotl(stack_t **stack, unsigned int ln)
{
	stack_t *a = *stack, *b;

	(void)ln;
	if (!a || !(*stack)->next)
	{
		return;
	}
	b = (*stack)->next;
	*stack = b;
	b->prev = NULL;
	a->next = NULL;
	while (b->next)
	{
		b = b->next;
	}
	b->next = a;
	a->prev = b;
}

/**
 * rotr - rotates the bottom of the stack to the top
 * @stack: double ptr to the head of the stack
 * @ln: current line number of monty file
 */
void rotr(stack_t **stack, unsigned int ln)
{
	stack_t *a = *stack, *b;

	(void)ln;
	if (!a || !(*stack)->next)
	{
		return;
	}
	while (a->next->next)
	{
		a = a->next;
	}
	b = a->next;
	a->next = NULL;
	(*stack)->prev = b;
	b->next = *stack;
	b->prev = NULL;
	*stack = b;
}

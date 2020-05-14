#include "monty.h"

/**
 * add - adds the two top values of the stack
 * @stack: double pointer to head of stack
 * @ln: current line number of monty file
 */
void add(stack_t **stack, unsigned int ln)
{
	stack_t *a;

	if (!(*stack) || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", ln);
		free_all();
		exit(EXIT_FAILURE);
	}
	a = (*stack)->next;
	a->n = a->n + (*stack)->n;
	a = *stack;
	*stack = (*stack)->next;
	free(a);
}

/**
 * nop - does nothing
 * @stack: double pointer to head of stack
 * @ln: current line number of monty file
 */
void nop(stack_t **stack, unsigned int ln)
{
	(void)stack;
	(void)ln;
}

/**
 * sub - subtract the top value from the next value of the stack
 * @stack: double pointer to head of stack
 * @ln: current line number of monty file
 */
void sub(stack_t **stack, unsigned int ln)
{
	stack_t *a;

	if (!(*stack) || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", ln);
		free_all();
		exit(EXIT_FAILURE);
	}
	a = (*stack)->next;
	a->n = a->n - (*stack)->n;
	a = *stack;
	*stack = (*stack)->next;
	free(a);
}

/**
 * div_op - divide the top value from the next value in the stack
 * @stack: double pointer to head of stack
 * @ln: current line number of monty file
 */
void div_op(stack_t **stack, unsigned int ln)
{
	stack_t *a;

	if (!(*stack) || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", ln);
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
	a->n = a->n / (*stack)->n;
	a = *stack;
	*stack = (*stack)->next;
	free(a);
}

/**
 * mul - multiplies the top two values of the stack
 * @stack: double pointer to head of stack
 * @ln: current line number of monty file
 */
void mul(stack_t **stack, unsigned int ln)
{
	stack_t *a;

	if (!(*stack) || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", ln);
		free_all();
		exit(EXIT_FAILURE);
	}
	a = (*stack)->next;
	a->n = a->n * (*stack)->n;
	a = *stack;
	*stack = (*stack)->next;
	free(a);
}

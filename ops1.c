#include "monty.h"

/**
 * push_node - pushes data on top of the stack
 * @data: char * containing data (int)
 */
void push_node(char *data)
{
	int n;
	stack_t *new;

	if (!is_valid_input(data))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", monty.line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	n = atoi(data);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = monty.stack;
	new->prev = NULL;
	if (new->next)
		new->next->prev = new;
	monty.stack = new;
}

/**
 * pall - print all data in stack
 * @stack: double pointer to head of stack
 * @line_number: current line number of monty file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - print top of stack
 * @stack: double pointer to head of stack
 * @ln: current line number of monty file
 */
void pint(stack_t **stack, unsigned int ln)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", ln);
		free_all();
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - pop the top of the stack
 * @stack: double pointer to head of stack
 * @line_number: current line number of monty file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!(*stack))
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * swap - swap the top two values of the stack
 * @stack: double pointer to head of stack
 * @ln: current line number of monty file
 */
void swap(stack_t **stack, unsigned int ln)
{
	stack_t *a;

	if (!(*stack) || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", ln);
		free_all();
		exit(EXIT_FAILURE);
	}
	a = (*stack)->next;
	(*stack)->prev = a;
	(*stack)->next = a->next;
	a->prev = NULL;
	a->next = *stack;
	*stack = a;
}

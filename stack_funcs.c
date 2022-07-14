#include "monty.h"

/**
 * push - adds a new element to the stack
 * @stack: address of the pointer to top of stack
 * @l: current line
 */
extern int value;
void push(stack_t **stack, unsigned int l)
{
	stack_t *new = (stack_t *) malloc(sizeof(stack_t));

	if (new == NULL)
	{
		free(new);
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (value == -486796987)
	{
		fprintf(stderr, "L%u: usage: push integer\n", l);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
	return;
}
/**
 * pop - removes element at top of stack
 * @stack: address to pointer to top of stack
 * @l: current line number
 */
void pop(stack_t **stack, unsigned int l)
{
	stack_t *tmp;
	(void) l;

	if (*stack == NULL)
	{
		return;
	}
	tmp = *stack;
	*stack = tmp->next;
	(*stack)->prev = NULL;
	free(tmp);
}
/**
 * pall - prints all elements in a stack
 * @stack: address to pointer to top of stack
 * @l: current line number
 */
void pall(stack_t **stack, unsigned int l)
{
	stack_t *tmp = *stack;
	(void) l;

	if (*stack == NULL)
		return;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * pint - prints the lement at top of stack
 * @stack: address to pointer to top of stack
 * @l: current line number
 */
void pint(stack_t **stack, unsigned int l)
{
     if (*stack == NULL)
     {
	     fprintf(stderr, "L%u: can't pint, stack empty", l);
	     fclose(c.f);
	     exit(EXIT_FAILURE);
     }
     printf("%d\n", (*stack)->n);
}
/**
 * nop - does nothing
 * @stack: address of pointer to stack top
 * @l: current line in file being read
 */
void nop(stack_t **stack, unsigned int l)
{
	(void) l;
	(void) stack;
	return;
}


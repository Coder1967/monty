#include "monty.h"

/**
 * push - adds a new element to the stack
 * @stack: address of the pointer to top of stack
 * @l: current line
 */
void push(stack_t **stack, unsigned int l)
{
	stack_t *new = (stack_t *) malloc(sizeof(stack_t));

	new->prev = NULL;
	new->n = info.value;

	if (new == NULL)
	{
		fclose(info.file_ptr);
		free_stack(stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (info.isnum == 0)
	{
		fclose(info.file_ptr);
		free_stack(stack);
		fprintf(stderr, "L%u: usage: push integer\n", l);
		exit(EXIT_FAILURE);
	}

	if (*stack == NULL)
	{
		*stack = new;
		new->next = NULL;
	}
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}
/**
 * pop - removes element at top of stack
 * @stack: address to pointer to top of stack
 * @l: current line number
 */
void pop(stack_t **stack, unsigned int l)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fclose(info.file_ptr);
		fprintf(stderr, "L%u: can't pop an empty stack\n", l);
		exit(EXIT_FAILURE);
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
	     fclose(info.file_ptr);
	     fprintf(stderr, "L%u: can't pint, stack empty", l);
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


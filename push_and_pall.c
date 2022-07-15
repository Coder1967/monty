#include "monty.h"
/**
 * push - adds an element to the stack
 * @stack: address of pointer to top of stack
 * @line_number: current line in file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (info.is_digit == false)
	{
		free_stack(stack);
		fclose(info.fileo);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = (stack_t *) malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free_stack(stack);
		fclose(info.fileo);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = info.value;
	new->prev = NULL;
	if (*stack == NULL)
	{
		new->next = NULL;
		*stack = new;
	}
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}

}
/**
 * pall - prints all number on stack
 * @stack: address of pointer to top of stack
 * @line_number: current line in file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void) line_number;
	if (*stack == NULL)
		return;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

#include "monty.h"
/**
 * pint - prints out number at top of stack
 * @stack: address of pointer to top of stack
 * @line_num: current line number
 */
void pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr,"L%u: can't pint, stack empty\n", line_num);
		fclose(info.fileo);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - removes element at top of stack
 * @stack: address of pointer to top of stack
 * @line_num: current line number
 */

void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		fclose(info.fileo);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	free(*stack);
	if (tmp != NULL)
		tmp->prev = NULL;
	*stack = tmp;
}

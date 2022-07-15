#include "monty.h"
/**
 * swap - swaps the top of stack with the second top of stack
 * @stack: address to pointer to top of stack
 * @line_num: current line number
 */
void swap(stack_t **stack, unsigned int line_num)
{
	int num;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		fclose(info.fileo);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	num = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = num;
}
/**
 * add - add the top of stack with the second top of stack
 * @stack: address to pointer to top of stack
 * @line_num: current line number
 */

void add(stack_t **stack, unsigned int line_num)
{
	int sum = 0;
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		fclose(info.fileo);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	sum = tmp->n + tmp->next->n;
	pop(stack, line_num);
	(*stack)->n = sum;
}

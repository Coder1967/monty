#include "monty.h"
/**
 * mod - mod of dividing the top of stack by the second top of stack
 * @stack: address to pointer to top of stack
 * @line_num: current line number
 */
void mod(stack_t **stack, unsigned int line_num)
{
	int result = 0;
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_num);
		fclose(info.fileo);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		fclose(info.fileo);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	result = tmp->next->n % tmp->n;
	pop(stack, line_num);
	(*stack)->n = result;
}

/**
 * pchar - prints ascii character of number on top of stack
 * @stack: address to pointer to top of stack
 * @line_num: current line number
 */

void pchar(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_num);
		fclose(info.fileo);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if ((tmp->n < 0) || (tmp->n > 127))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_num);
		fclose(info.fileo);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", tmp->n);
}

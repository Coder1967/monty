#include "monty.h"
/**
 * rotr - puts the last element of the stack at the last
 * @stack: address of pointer to top of stack
 * @line_num: current line number
 */
void rotr(stack_t **stack, unsigned int line_num)
{
	int tmp1 = 0;
	stack_t *tmp2 = *stack;

	(void)line_num;
	if (*stack == NULL)
		return;
	while (tmp2->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	tmp1 = tmp2->n;
	while (tmp2->prev != NULL)
	{
		tmp2->n = tmp2->prev->n;
		tmp2 = tmp2->prev;
	}
	tmp2->n = tmp1;
}

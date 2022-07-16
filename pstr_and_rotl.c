#include "monty.h"
/**
 * pstr - prints out string using ascci chars of the numbers in stack
 * @stack: address of pointer to top of stack
 * @line_num: current line number
 */
void pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	(void)line_num;
	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->n == 0 || tmp->n < 0 || tmp->n > 127)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}
/**
 * rotl - puts the top of stack at the last and the second at the top
 * @stack: address of pointer to top of stack
 * @line_num: current line number
 */

void rotl(stack_t **stack, unsigned int line_num)
{
	int tmp1 = 0;
	stack_t *tmp2 = *stack;

	(void)line_num;
	if (*stack == NULL)
		return;
	tmp1 = tmp2->n;
	while (tmp2->next != NULL)
	{
		tmp2->n = tmp2->next->n;
		tmp2 = tmp2->next;
	}
	tmp2->n = tmp1;
}

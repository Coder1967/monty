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

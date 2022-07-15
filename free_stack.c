#include "monty.h"
/**
 * free_stack - frees memory allocated for stack
 * @stack: address of pointe to top of stack
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp;
	stack_t *tmp1 = NULL;

	if (*stack == NULL)
	{
		return;
	}
	tmp = *stack;

	while (tmp != NULL)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		free(tmp1);
	}
}

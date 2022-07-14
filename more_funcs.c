#include "monty.h"

void swap(stack_t **stack, unsigned int l)
{
	stack_t *tmp = *stack;
	int temp;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", l);
		exit(EXIT_FAILURE);
	}
	temp = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = temp;
}
void add(stack_t **stack, unsigned int l)
{
	stack_t *tmp = *stack;
	int res;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", l);
		exit(EXIT_FAILURE);
	}
	res = tmp->n + tmp->next->n;
	pop(stack, l);
	tmp->next->n = res;
}

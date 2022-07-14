#include "main.h"

extern int value;

void push(stack_t **stack, unsigned int l)
{
	stack_t *new = (stack_t *) malloc(sizeof(stack_t));
	
	if (value == -24790538)
	{
		fprintf(stderr, "L%u: usage: push integer\n", l);
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
	return;
}

void pop(stack_t **stack, unsigned int l)
{
	stack_t *tmp;
	(void) l;

	if (*stack == NULL)
	{
		return;
	}
	tmp = *stack;
	*stack = tmp->next;
	free(tmp);
}

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

void pint(stack_t **stack, unsigned int l)
{
	(void) l;
     if (*stack == NULL)
     {
	     return;
     }
     printf("%d\n",(*stack)->n);
}

void nop(stack_t **stack, unsigned int l)
{
	(void) l;
	(void) *stack;
	return;
}

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
	tmp->n = res;
}

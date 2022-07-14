#include "monty.h"
/**
 * swap - swaps the position of the two on top of stack
 * @stack: address of the pointer to top of the stack
 * @l: current line number
 */
void swap(stack_t **stack, unsigned int l)
{
	stack_t *tmp = *stack;
	int temp;

	if (tmp == NULL || tmp->next == NULL)
	{
		fclose(info.file_ptr);
		fprintf(stderr, "L%u: can't swap, stack too short\n", l);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	temp = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = temp;
}
/**
 * add - adds up the value of the two uppermost on stack
 * @stack: address of the pointer to top of stack
 * @l: current line number
 */
void add(stack_t **stack, unsigned int l)
{
	stack_t *tmp = *stack;
	int res;

	if (tmp == NULL || tmp->next == NULL)
	{
		fclose(info.file_ptr);
		fprintf(stderr, "L%u: can't add, stack too short\n", l);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	res = tmp->n + tmp->next->n;
	pop(stack, l);
	tmp->next->n = res;
}
/**
 * free_stack - frees memory allocated to stack
 * @stack: address to the pointer to the top of stack
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;
	stack_t *tmp1;

	if (*stack == NULL)
		return;

	while (tmp != NULL)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		free(tmp1);
	}
}

#include "monty.h"
/**
 * sub - subtracts top of stack from second top of stack
 * @stack: address of pointer to top of stack
 * @l: current line of file
 */
void sub(stack_t **stack, unsigned int l)
{
	stack_t *tmp = *stack;
	int res;
	
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", l);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	res = tmp->next->n - tmp->n;
	pop(stack, l);
	tmp->next->n = res;
}
/**
 * mul - multiplies top of stack with second element from top
 * @stack: address to pointer to top of stack
 * @l: current line number
 */
void mul(stack_t **stack, unsigned int l)
{
	 stack_t *tmp = *stack;
	 int res;
	 
	 if (tmp == NULL || tmp->next == NULL)
	 {
		 fprintf(stderr, "L%u: can't mul, stack too short\n", l);
		 free_stack(stack);
		 exit(EXIT_FAILURE);
	 }
	 res = tmp->n * tmp->next->n;
	 pop(stack, l);
	 tmp->next->n = res;
}
/**
 * div - divides second top element by top element of stack
 * @stack: address to pointer to top of stack
 * @l: current line in file
 */
void fdiv(stack_t **stack, unsigned int l)
{
	stack_t *tmp = *stack;
	int res;
	
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", l);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	res = tmp->next->n / tmp->n;
	pop(stack, l);
	tmp->next->n = res;
}

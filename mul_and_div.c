#include "monty.h"
/**
 * mul - multiplies the top of by from the second top of stack
 * @stack: address to pointer to top of stack
 * @line_num: current line number
 */

void mul(stack_t **stack, unsigned int line_num)
{
        int result = 0;
        stack_t *tmp = *stack;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't mul, stack too short\n", line_num);
                fclose(info.fileo);
                free_stack(stack);
                exit(EXIT_FAILURE);
        }
        result = tmp->next->n * tmp->n;
        pop(stack, line_num);
        (*stack)->n = result;
}
/**
 * divide - divides the top of stack by the second top of stack
 * @stack: address to pointer to top of stack
 * @line_num: current line number
 */

void divide(stack_t **stack, unsigned int line_num)
{
        int result = 0;
        stack_t *tmp = *stack;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
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
        result = tmp->next->n / tmp->n;
        pop(stack, line_num);
        (*stack)->n = result;
}


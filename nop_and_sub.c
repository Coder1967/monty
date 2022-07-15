#include "monty.h"

/**
 * sub - subtracts the top of stack from the second top of stack
 * @stack: address to pointer to top of stack
 * @line_num: current line number
 */

void sub(stack_t **stack, unsigned int line_num)
{
        int result = 0;
        stack_t *tmp = *stack;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't sub, stack too short\n", line_num);
                fclose(info.fileo);
                free_stack(stack);
                exit(EXIT_FAILURE);
        }
        result = tmp->next->n - tmp->n;
        pop(stack, line_num);
        (*stack)->n = result;
}
/**
 * nop - does nothing
 * @stack: address to pointer to top of stack
 * @line_num: current line number
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}

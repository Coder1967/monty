#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/**
 * struct figures - a bunch of necessary infos
 * @is_digit: checks if string are digits
 * @value: the number to be pushed(works only if is_digit is true)
 * @fileo: stores pointer to opened file
 */
typedef struct figures
{
	bool is_digit;
	int value;
	FILE *fileo;
} infos;

extern infos info;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */


typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

void push(stack_t **stack, unsigned int l);
void pall(stack_t **stack, unsigned int l);
void file_reader(void);
void arg_sort(char *buf, unsigned int line_number, stack_t **stack);
void func_caller(char *argument1, unsigned int line_number, stack_t **stack);
void is_a_num(char *argument2);
void free_stack(stack_t **stack);

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{         char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#endif

#include "monty.h"

/**
 * info - varaible of type struct infos
 */

infos info = {0, 0, NULL};

/**
 * main - main function
 * @argc: number of arguments passed when executing file
 * @argv: arguments passed during file's execution
 * Return: 0(on success)
 */
int main(int argc, char **argv)
{
	FILE *file;

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	info.fileo = file;
	file_reader();
	return (0);
}
/**
 * file_reader - reads file passed during file execution
 */
void file_reader(void)
{
	stack_t *stack = NULL;
	unsigned int line_number = 1;
	char buffer[1024];

	while (fgets(buffer, 1024, info.fileo))
	{
		arg_sort(buffer, line_number, &stack);
		line_number++;
	}
	free_stack(&stack);
	fclose(info.fileo);
}
/**
 * arg_sort - organizes the opcodes
 * @buf: line of string from file
 * @line_number: current line number in file
 * @stack: address to pointer to top of stack
 */
void arg_sort(char buf[], unsigned int line_number, stack_t **stack)
{
	char delim[] = " \n\t";
	char buffer[1024];
	char *arg1;

	strcpy(buffer, buf);
	arg1 = strtok(buffer, delim);
	if (strcmp(arg1, "push") == 0)
	{
		is_a_num(buf);
	}
	func_caller(arg1, line_number, stack);
}
/**
 * func_caller - scans the opcode from the
 * file and calls the appropriate function
 * @stack: address to pointer to top of stack
 * @argument1: opcode from file
 * @line_number: current line number in file
 */
void func_caller(char *argument1, unsigned int line_number, stack_t **stack)
{
	int i = 0;
	instruction_t instructs[] = {
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"add", add},
		{"swap", swap},
		{"push", push},
		{"nop", nop},
		{"sub", sub},
		{"mul", mul},
		{"div", divide},
		{"mod", mod},
		{"pchar", pchar},
		{"rotl", rotl},
		{"pstr", pstr}
	};
	if (*argument1 == '#')
		return;
	while (i < 14)
	{
		if (strcmp(argument1, instructs[i].opcode) == 0)
		{
			instructs[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, argument1);
	free_stack(stack);
	fclose(info.fileo);
	exit(EXIT_FAILURE);
}

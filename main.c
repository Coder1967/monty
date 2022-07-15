#include "monty.h"

/**
 * infos info - varaible of type struct info
 */

infos info;

/**
 * main - main function
 * @argc: number of arguments passed when executing file
 * @argv: arguments passed during file's execution
 * Return: 0(on success)
 */
int main(int argc, char **argv)
{
	FILE *file;

	if (argc == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	info.fileo = file;
	file_reader();
	return (0);
}
/**
 * file_reader - reads file passed during file execution
 */
void file_reader()
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
 */
void arg_sort(char buf[], unsigned int line_number, stack_t **stack)
{
	char delim[] = " \n";
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
 * @argument1: opcode from file
 * @line_number: current line number in file
 */
void func_caller(char *argument1, unsigned int line_number, stack_t **stack)
{
	int i = 0;
	instruction_t instructs[] = {
		{"pall", pall},
		{"push", push}
	};

	while (i < 2)
	{
		if (strcmp(argument1, instructs[i].opcode) == 0)
		{
			instructs[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s", line_number, argument1);
	free_stack(stack);
	fclose(info.fileo);
	exit(EXIT_FAILURE);
}

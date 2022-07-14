#include "monty.h"
#include <stddef.h>
#include <string.h>

int value;
/**
 * main - the main function
 * @argc: counts arguments passed from terminal
 * @argv: an array of strings passed to the terminal
 * Return: 0(on success)
 */
int main(int argc, char *argv[])
{
	char *buffer = (char *) malloc(80 * sizeof(char));
	stack_t *stack = NULL;
	FILE *file = fopen(argv[1], "r");

	if (argc == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	funct_caller(file, buffer, stack);
	free(buffer);
	free_stack(&stack);
	return (0);
}
/**
 * funct_caller - reads contents of file for
 * monty codes then passes it to the copare function
 * @file: pointer to the file stream
 * @buffer: dynamically allocated memory
 * @stack: pointer to the op of the stack
 */
void funct_caller(FILE *file, char *buffer, stack_t *stack)
{
	unsigned int i, j, k, check, check1, check2, l = 1;
	char str[25], st[28];

	while (fgets(buffer, 40, file))
	{
		i = check = check1 = check2 = j = k = 0;
		while (i < strlen(buffer))
		{
			if (buffer[i] != ' ' && check1 == 0)
			{
				str[j] = buffer[i];
				str[j + 1] = '\0';
				if (buffer[i + 1] == ' ')
				{
					check1 = 1;
				}
				j++;
			}
			if (buffer[i] >= 48 && buffer[i] <= 57 && check2 == 0)
			{
				st[k] = buffer[i];
				st[k + 1] = '\0';
				if (buffer[i + 1] == ' ')
				{
					check2 = 1;
				}
				check++;
				k++;
			}
			i++;
		}
		if (check == 0)
			value = -24790538;
		else
		{
			value = atoi(st);
		}
		compare(str, l, &stack);
		l++;
	}
}

/**
 * compare - checks if the string from the file matches any function
 * @str: string from file
 * @l: current line
 * @stack: pointer to top node on the stack
 */
void compare(char *str, unsigned int l, stack_t **stack)
{
	 int i;
	 unsigned int len = strlen(str);
	 instruction_t inst[] = {
		 {"nop", nop},
		 {"push", push},
		 {"pall", pall},
		 {"pint", pint},
		 {"sub", sub},
		 {"div", div},
		 {"mul", mul},
	{"pop", pop},
		 {"swap", swap},
		 {"add", add}
	 };

	 i = 0;
	 if (str[0] == '\n' || str[0] == '#' || str[0] == '\0')
		 return;

	while (i < 7)
	{
		if (strncmp(str, inst[i].opcode, len) == 0)
		{
			inst[i].f(stack, l);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", l, str);
	exit(EXIT_FAILURE);
}



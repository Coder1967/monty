#include "monty.h"
/**
 * is_a_num - checks if the second argument from file is a number
 * @argument2: second argument from file
 */
void is_a_num(char *argument2)
{
	char str[25];
	int i = 0;
	int check_for_num = 0, j = 0;

	while (argument2[i] != '\0')
	{
		if (isdigit(argument2[i]))
		{
			str[j] = argument2[i];
			check_for_num++;
			j++;
		}
		i++;
	}
	str[j] = '\0';

	if (check_for_num > 0)
	{
		info.is_digit = true;
		info.value = atoi(str);
	}

	else
	{
		info.is_digit = false;
	}
}

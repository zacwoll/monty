#include "monty.h"

/**
 * is_valid_input - checks if input data is valid
 * @str: str to be checked
 * Return: true if int, else false
 */
bool is_valid_input(char *str)
{
	int i = 0;

	if (!str || strlen(str) <= 0)
		return (false);
	if (str[0] != '-' && !isdigit(str[0]))
		return (false);
	for (i = 1; str[i]; i++)
	{
		if (!isdigit(str[i]))
		{
			return (false);
		}
	}
	return (true);
}

#include "monty.h"

void (*get_of_opcode_func(char *opcode))(stack_t **, unsigned int);
char *get_int(int num);

/**
 * get_of_opcode_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */

void (*get_of_opcode_func(char *opcode))(stack_t **, unsigned int)
{

	instruction_t op_funcs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL},
	};

	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * get_int - gets a character pointer to new string containing int
 * @num: number to convert to string
 *
 * Return: character pointer to newly created string. NULL if malloc fails.
 */
char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	length = get_numbase_len(temp, 10);

	if (num < 0 || num_l < 0)
		length++;			  /* negative sign */
	ret = malloc(length + 1); /* create new string */
	if (!ret)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

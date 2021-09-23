#include "monty.h"

void free_tokens(void);
int empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t **, unsigned int);
int run_monty(FILE *script_fd);

/**
 * free_tokens - Frees the global op_toks array of strings.
 */
void free_tokens(void)
{
	size_t i = 0;

	if (op_token == NULL)
		return;

	for (i = 0; op_token[i]; i++)
		free(op_token[i]);

	free(op_token);
}

/**
 * empty_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * run_monty - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */

int run_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, _status_err_ = EXIT_SUCCESS;
	unsigned int num_line = 0, prev_tok_len = 0;
	void (*op_func)(stack_t **, unsigned int);

	if (stack_init(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (-1 != getline(&line, &len, script_fd))
	{
		num_line++;
		op_token = strtow(line, DELIMITS);
		if (op_token == NULL)
		{
			if (empty_line(line, DELIMITS))
				continue;
			free_stack(&stack);
			return (malloc_err());
		}
		else if (op_token[0][0] == '#')
		{
			free_tokens();
			continue;
		}
		op_func = get_of_opcode_func(op_token[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			_status_err_ = Uknw_op_err(op_token[0], num_line);
			free_tokens();
			break;
		}
		prev_tok_len = token_arr_len();
		op_func(&stack, num_line);
		if (token_arr_len() != prev_tok_len)
		{
			if (op_token && op_token[prev_tok_len])
				_status_err_ = atoi(op_token[prev_tok_len]);
			else
				_status_err_ = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_err());
	}

	free(line);
	return (_status_err_);
}

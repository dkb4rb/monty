#include "monty.h"

int Bad_usage(void);
int malloc_err(void);
int fd_open_err(char *fd);
int Uknw_op_err(char *code, unsigned int line_number);
int no_int_err(unsigned int line_number);
int div_error(unsigned int line_number);

/**
 * Bad_usage - Prints usage error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */

int Bad_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * fd_open_err - Prints file opening error messages w/ file name.
 * @fd: Name of file failed to open
 *
 * Return: (EXIT_FAILURE) always.
 */

int fd_open_err(char *fd)
{
	fprintf(stderr, "Error: Can't open file %s\n", fd);
	return (EXIT_FAILURE);
}

/**
 * Uknw_op_err - Prints unknown instruction error messages.
 * @code: Opcode where error occurred.
 * @line_number: Line number in Monty bytecodes file where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */

int Uknw_op_err(char *code, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, code);
	return (EXIT_FAILURE);
}

/**
 * malloc_err - Prints malloc error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */

int malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * no_int_err - Prints invalid monty_push argument error messages.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int no_int_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * div_error - Prints division error messages for division by 0.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

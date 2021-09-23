#ifndef MONTY_H
#define MONTY_H

#define _PRINT(c) write(STDOUT_FILENO, (c), strlen(c))
#define BUFFSIZE 1024
#define DELIMITS " \n\t\a\b"

#define STACK 0
#define QUEUE 1

/** GLOBAL OPCODE TOKEN */
extern char **op_token;

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* ERRORS CASES */
int Bad_usage(void);
int malloc_err(void);
int fd_open_err(char *fd);
int Uknw_op_err(char *code, unsigned int line_number);
int no_int_err(unsigned int line_number);

/* ERRNOS */
void set_op_tok_error(int error_code);
int pop_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int pint_error(unsigned int line_number);
int div_error(unsigned int line_number);

/* OPCODES MONTY FUNTIONS */
void _push(stack_t **stack, unsigned int num_line);
void _pall(stack_t **stack, unsigned int num_line);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);

/* ARITMETIC FUNCS */
void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);

/* FUNCTIONS STACKS */
int run_monty(FILE *script_fd);
int stack_init(stack_t **stack);
int get_mode(stack_t *stack);
int free_stack(stack_t **stack);

unsigned int token_arr_len(void);
char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

int empty_line(char *line, char *delims);

void (*get_of_opcode_func(char *opcode))(stack_t **, unsigned int);

void free_tokens(void);
void set_op_tok_error(int error_code);
char *get_int(int n);

/* STRINGS FUNCTIONS */
unsigned int _abs(int i);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
					   char *buff, int buff_size);
#endif /* MONTY_H */
#include "monty.h"

int stack_init(stack_t **stack);
int get_mode(stack_t *stack);
void free_stack(stack_t **stack);

/**
 * stack_init - Initializes a stack_t stack with beginning
 *              stack and ending queue nodes.
 * @stack: A pointer to an unitialized stack_t stack.
 *
 * Return: If an error occurs - EXIT_FAILURE.
 *         Otherwise - EXIT_SUCCESS.
 */

int stack_init(stack_t **stack)
{
	stack_t *str;

	str = malloc(sizeof(stack_t));
	if (str == NULL)
		return (malloc_err());

	str->n = STACK;
	str->prev = NULL;
	str->next = NULL;

	*stack = str;
	return (EXIT_SUCCESS);
}
/**
 * get_mode - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - STACK (0).
 *         If the stack_t is in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */

int get_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}

/**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
 * Return: void
 */

void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

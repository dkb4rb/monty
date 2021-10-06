#include "monty.h"

/**
 * main - the entry point for Monty Interp
 *
 * @argc: the count of arguments passed to the program
 * @argv: pointer to an array of char pointers to arguments
 *
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */

int main(int argc, char **argv)
{
    /** ESTA ES EL CONTADOR PARA SABER VALOR DE ARGUMENTOS*/
    if (argv[1] == NULL)
    {
        printf("USAGE: monty file\n");
        return (EXIT_FAILURE);
    }
    printf("%d\n", argc);
    return 0;
}
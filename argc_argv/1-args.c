#include "main.h"

/**
 * main - prints the number of arguments passed into it
 * @argc: argument count
 * @argv: argument vector (unused)
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
    (void)argv; /* unused parameter */
    printf("%d\n", argc - 1);
    return (0);
}

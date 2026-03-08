#include "main.h"
#include <stdio.h>

/**
 * main - prints the name of the program
 * @argc: number of command line arguments (not used)
 * @argv: array of command line arguments
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
    (void)argc; /* argc is unused */
    printf("%s\n", argv[0]);
    return (0);
}

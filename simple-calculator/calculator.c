#include <stdio.h>

/**
 * show_menu - displays the calculator menu
 */
void show_menu(void)
{
	printf("\n=== Simple Calculator ===\n");
	printf("1. Add\n");
	printf("2. Subtract\n");
	printf("3. Multiply\n");
	printf("4. Divide\n");
	printf("0. Quit\n");
	printf("Choice: ");
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int choice;
	float num1, num2;

	do {
		show_menu();
		scanf("%d", &choice);

		if (choice >= 1 && choice <= 4)
		{
			printf("Enter first number: ");
			scanf("%f", &num1);
			printf("Enter second number: ");
			scanf("%f", &num2);
			calculate(choice, num1, num2);
		}
		else if (choice == 0)
		{
			printf("Bye!\n");
		}
		else
		{
			printf("Invalid choice! Please try again.\n");
		}

	} while (choice != 0);

	return (0);
}


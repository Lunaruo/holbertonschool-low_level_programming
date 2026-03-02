#include <stdio.h>
int main() {
	int choice;
	float num1, num2;

do{

	printf("\n=== Simple Calculator ===\n");
	printf("1. Add\n");
	printf("2. Subtract\n");
	printf("3. Multiply\n");
	printf("4. Divide\n");
	printf("0. Quit\n");
	printf("Choice: ");
	scanf("%d", &choice);
	if (choice >= 1 && choice <= 4) {
           printf("Enter first number: ");
           scanf("%f", &num1);
           printf("Enter second number: ");
           scanf("%f", &num2);
		}
       switch (choice) {
           case 1:
               printf("Result: %.2f\n", num1 + num2);
               break;
           case 2:
               printf("Result: %.2f\n", num1 - num2);
               break;
           case 3:
               printf("Result: %.2f\n", num1 * num2);
               break;
           case 4:
               if (num2 != 0) {
                   printf("Result: %.2f\n", num1 / num2);
			}
               else {
                   printf("Error: Division by zero!\n");
			}
               break;
           case 0:
               printf("Bye!\n");
               break;
           default:
               printf("Invalid choice! Please try again.\n");
       }
   }while (choice != 0);
   return 0;
}

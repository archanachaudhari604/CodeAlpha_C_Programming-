#include <stdio.h>
#include <stdlib.h>
int main()
{
    float num1=0, num2=0, result=0;
    int choice=0;

    printf("===== BASIC CALCULATOR =====\n");

    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter second number: ");
    scanf("%f", &num2);

    printf("\nSelect an operation:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            result = num1 + num2;
            printf("\nResult = %.2f\n", result);
            break;

        case 2:
            result = num1 - num2;
            printf("\nResult = %.2f\n", result);
            break;

        case 3:
            result = num1 * num2;
            printf("\nResult = %.2f\n", result);
            break;

        case 4:
            if (num2 == 0)
            {
                printf("\nError: Division by zero is not allowed.\n");
            }
            else
            {
                result = num1 / num2;
                printf("\nResult = %.2f\n", result);
            }
            break;

        default:
            printf("\nInvalid choice! Please select between 1 and 4.\n");
    }

    return 0;
}

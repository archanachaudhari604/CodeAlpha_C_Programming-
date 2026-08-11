#include <stdio.h>

void addition();
void multiplication();
void transpose();

int main()
{
    int choice = 0;

    printf("\n===== MATRIX OPERATION =====\n");
    printf("1. ADDITION\n");
    printf("2. MULTIPLICATION\n");
    printf("3. TRANSPOSE\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            addition();
            break;

        case 2:
            multiplication();
            break;

        case 3:
            transpose();
            break;

        default:
            printf("\nInvalid choice!");
    }

    return 0;
}


// ================= ADDITION =================

void addition()
{
    int arr1[3][3], arr2[3][3], arr3[3][3];
    int i, j;

    printf("\nEnter elements of first matrix:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("\nEnter elements of second matrix:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("\nMatrix Addition:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            arr3[i][j] = arr1[i][j] + arr2[i][j];

            printf("%d\t", arr3[i][j]);
        }

        printf("\n");
    }
}


// ================= MULTIPLICATION =================

void multiplication()
{
    int arr1[3][3], arr2[3][3], arr3[3][3];
    int i, j, k;

    printf("\nEnter elements of first matrix:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("\nEnter elements of second matrix:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }

    // Initialize and calculate multiplication
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            arr3[i][j] = 0;

            for (k = 0; k < 3; k++)
            {
                arr3[i][j] = arr3[i][j] +
                             arr1[i][k] * arr2[k][j];
            }
        }
    }

    printf("\nMatrix Multiplication:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", arr3[i][j]);
        }

        printf("\n");
    }
}


// ================= TRANSPOSE =================

void transpose()
{
    int arr[3][3];
    int i, j;

    printf("\nEnter elements of matrix:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nMatrix Transpose:\n");

    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < 3; i++)
        {
            printf("%d\t", arr[i][j]);
        }

        printf("\n");
    }
}

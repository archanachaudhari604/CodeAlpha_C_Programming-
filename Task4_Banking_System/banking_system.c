#include <stdio.h>

struct Account
{
    int accountNo;
    char name[50];
    float balance;
};

void createAccount();
void deposit();
void withdraw();
void balanceEnquiry();

int main()
{
    int choice;

    do
    {
        printf("\n===== BANK ACCOUNT MANAGEMENT SYSTEM =====");
        printf("\n1. Create Account");
        printf("\n2. Deposit");
        printf("\n3. Withdraw");
        printf("\n4. Balance Enquiry");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createAccount();
                break;

            case 2:
                deposit();
                break;

            case 3:
                withdraw();
                break;

            case 4:
                balanceEnquiry();
                break;

            case 5:
                printf("\nThank you for using the Banking System.\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}


// Create Account
void createAccount()
{
    struct Account a;
    FILE *fp;

    fp = fopen("accounts.dat", "ab");

    if (fp == NULL)
    {
        printf("\nFile cannot be opened.\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &a.accountNo);

    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", a.name);

    printf("Enter Initial Balance: ");
    scanf("%f", &a.balance);

    fwrite(&a, sizeof(a), 1, fp);

    fclose(fp);

    printf("\nAccount created successfully.\n");
}


// Deposit
void deposit()
{
    struct Account a;
    FILE *fp;
    int accountNo;
    float amount;
    int found = 0;

    fp = fopen("accounts.dat", "rb+");

    if (fp == NULL)
    {
        printf("\nNo account records found.\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &accountNo);

    while (fread(&a, sizeof(a), 1, fp))
    {
        if (a.accountNo == accountNo)
        {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            if (amount > 0)
            {
                a.balance = a.balance + amount;

                fseek(fp, -sizeof(a), SEEK_CUR);
                fwrite(&a, sizeof(a), 1, fp);

                printf("\nAmount deposited successfully.\n");
                printf("New Balance: %.2f\n", a.balance);

                found = 1;
            }
            else
            {
                printf("\nInvalid amount.\n");
            }

            break;
        }
    }

    if (found == 0)
    {
        printf("\nAccount not found.\n");
    }

    fclose(fp);
}


// Withdraw
void withdraw()
{
    struct Account a;
    FILE *fp;
    int accountNo;
    float amount;
    int found = 0;

    fp = fopen("accounts.dat", "rb+");

    if (fp == NULL)
    {
        printf("\nNo account records found.\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &accountNo);

    while (fread(&a, sizeof(a), 1, fp))
    {
        if (a.accountNo == accountNo)
        {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount <= 0)
            {
                printf("\nInvalid amount.\n");
            }
            else if (amount > a.balance)
            {
                printf("\nInsufficient balance.\n");
            }
            else
            {
                a.balance = a.balance - amount;

                fseek(fp, -sizeof(a), SEEK_CUR);
                fwrite(&a, sizeof(a), 1, fp);

                printf("\nAmount withdrawn successfully.\n");
                printf("Remaining Balance: %.2f\n", a.balance);
            }

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nAccount not found.\n");
    }

    fclose(fp);
}


// Balance Enquiry
void balanceEnquiry()
{
    struct Account a;
    FILE *fp;
    int accountNo;
    int found = 0;

    fp = fopen("accounts.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNo account records found.\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &accountNo);

    while (fread(&a, sizeof(a), 1, fp))
    {
        if (a.accountNo == accountNo)
        {
            printf("\n===== ACCOUNT DETAILS =====");
            printf("\nAccount Number : %d", a.accountNo);
            printf("\nAccount Holder : %s", a.name);
            printf("\nBalance        : %.2f\n", a.balance);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nAccount not found.\n");
    }

    fclose(fp);
}


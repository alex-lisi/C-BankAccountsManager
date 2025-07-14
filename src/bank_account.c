#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createAccount();
void listAccounts();
void getBalance();
void deposit();
void withdraw();
int findAccount(char *username);

struct BankAccount {
    char username[50];
    float balance;
};

// Global array to store accounts and count
struct BankAccount accounts[100];
int accountCount = 0;

int main() {
    int userChoice;

    printf("\n--- Bank Program ---\n\n");

    do {
        printf("Options:\n");
        printf("0: Create Bank Account\n");
        printf("1: List Bank Accounts\n");
        printf("2: Get Balance\n");
        printf("3: Deposit\n");
        printf("4: Withdraw\n");
        printf("5: Exit\n\n");
        printf("Your Choice: ");
        scanf("%d", &userChoice);
        getchar(); // consume leftover newline

        switch (userChoice) {
        case 0:
            createAccount();
            break;
        case 1:
            listAccounts();
            break;
        case 2:
            getBalance();
            break;
        case 3:
            deposit();
            break;
        case 4:
            withdraw();
            break;
        case 5:
            printf("\nExiting the Program\n");
            break;
        default:
            printf("\nInvalid Choice");
        }

    } while (userChoice != 5);
  

    return 0;
}

void createAccount() {
    if (accountCount >= 100) {
        printf("\nError: Maximum number of accounts reached.\n\n");
        return;
    }

    struct BankAccount account;

    printf("\n--- Create Bank Account---\n\n");
    printf("Username: ");
    fgets(account.username, sizeof(account.username), stdin);
    account.username[strlen(account.username) - 1] = '\0'; // remove newline created by fgets()

    // check username availabiity
    if (findAccount(account.username) != -1) {
        printf("\nError: Username already exists\n\n");
        return;
    }

    printf("Initial Balance: ");
    scanf("%f", &account.balance);

    if (account.balance < 0) {
        printf("\nError: Initial balance cannot be negative!\n\n");
        return;
    }

    // add account to the accounts array
    accounts[accountCount] = account;
    accountCount++;

    printf("\nAccount Created Successfully\n\n");
}

void listAccounts() {
    printf("\n--- List of Bank Accounts ---\n\n");

    if (accountCount == 0) {
        printf("Error: No accounts found\n\n");
        return;
    }

    printf("%-20s %s\n", "Username", "Balance");
    printf("%-20s %s\n", "-------", "-------");

    // loop through accounts array
    for (int i = 0; i < accountCount; i++) {
        printf("%-20s $%.2f\n", accounts[i].username, accounts[i].balance);
    }
    printf("\n");

}

void getBalance() {
    char username[50];

    printf("\n--- Get Balance ---\n\n");
    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strlen(username) - 1] = '\0';

    // find index of account with the specified username
    int index = findAccount(username);

    if (index == -1) {
        printf("\nError: Account not found\n\n");
        return;
    }

    printf("Balance for account %s is $%.2f\n\n", username, accounts[index].balance);
}

void deposit() {
    char username[50];
    float amount;

    printf("\n--- Deposit ---\n\n");
    printf("Account name: ");
    fgets(username, sizeof(username), stdin);
    username[strlen(username) -1] = '\0';

    int index = findAccount(username);

    if (index == -1) {
        printf("\nError: Account not found\n\n");
        return;
    }

    printf("Enter deposit amount: $");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("\nError: Deposit must be positive\n\n");
        return;
    }

    accounts[index].balance += amount;
    printf("\nDeposit successful. New account balance for %s is $%.2f\n\n", username, accounts[index].balance);
}

void withdraw() {
    char username[50];
    float amount;

    printf("\n--- Withdraw ---\n\n");
    printf("Account name: ");
    fgets(username, sizeof(username), stdin);
    username[strlen(username) - 1] = '\0';

    int index = findAccount(username);

    if (index == -1) {
        printf("\nError: Account not found\n\n");
        return;
    }

    printf("Current balance: $%.2f\n", accounts[index].balance);
    printf("Enter withdrawal amount: $");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("\nError: Withdrawal must be positive\n\n");
        return;
    }

    if (amount > accounts[index].balance) {
        printf("\nError: Insufficient funds\n\n");
        return;
    }

    accounts[index].balance -= amount;
    printf("\nWithdrawal successful. New account balance for %s is %.2f\n\n", username, accounts[index].balance);
}

// Helper function to find an account index by username
int findAccount(char *username) {
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            return i;
        }
    }
    return -1; // Account not found
}
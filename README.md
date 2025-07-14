# Bank Account Management System

A simple command-line bank account management system written in C that allows users to create accounts, manage balances, and perform basic banking operations.

## Features

- **Create Bank Account**: Register new accounts with unique usernames and initial balance
- **List Accounts**: View all existing accounts with their balances
- **Check Balance**: Look up the balance of a specific account
- **Deposit Money**: Add funds to an existing account
- **Withdraw Money**: Remove funds from an account (with insufficient funds protection)
- **Input Validation**: Prevents negative balances and duplicate usernames

## Project Structure

```
bank_account/
├── src/
│   └── bank_account.c    # Main source code
├── bin/                  # Compiled executables (ignored by git)
├── .gitignore           # Git ignore file
├── makefile             # Build automation
└── README.md            # This file
```

## Requirements

- GCC compiler
- Make utility (optional, for using makefile)

## Building and Running

### Using Make (Recommended)

```bash
# Compile the program
make

# Compile and run in one step
make run

# Clean up compiled files
make clean
```

### Manual Compilation

```bash
# Create bin directory if it doesn't exist
mkdir bin

# Compile manually
gcc src/bank_account.c -o bin/bank_account.exe

# Run the program
./bin/bank_account.exe
```

## Usage

1. Run the program
2. Choose from the menu options (0-5):
   - **0**: Create a new bank account
   - **1**: List all existing accounts
   - **2**: Check balance of a specific account
   - **3**: Deposit money to an account
   - **4**: Withdraw money from an account
   - **5**: Exit the program

### Example Usage

```
--- Bank Program ---

Options:
0: Create Bank Account
1: List Bank Accounts
2: Get Balance
3: Deposit
4: Withdraw
5: Exit

Your Choice: 0

--- Create Bank Account---

Username: john_doe
Initial Balance: 500.00

Account Created Successfully
```

## Limitations

- Accounts are stored in memory only (data is lost when program exits)
- Maximum of 100 accounts supported
- No persistent storage (no file saving)
- Basic error handling for invalid inputs

## Future Enhancements

- File-based storage for persistent data
- Account deletion functionality
- Transaction history tracking
- Password protection for accounts
- More robust input validation
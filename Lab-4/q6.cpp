// Scenario: A bank wants to develop a system for managing customer accounts. The system
// should allow customers to:
// 1. Create a new account with an account number, owner’s name, and initial balance
// (default balance is 0 if not provided).
// 2. Deposit money into their account.
// 3. Withdraw money from their account, ensuring they cannot withdraw more than the
// available balance.
// 4. Display account details including account number, owner’s name, and current balance.
// Your task is to implement a C++ program that fulfills these requirements.

#include <iostream>
using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    Account() {
         this->accountNumber = "Not Attempted";
        this->accountHolderName = "Not Attempted";
        this->balance = 0.0;
    }

    Account(string accountHolderName, string accountNumber, double balance) {
        this->accountHolderName = accountHolderName;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    void deposit(double amount) {
       if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
        } else {
            cout << "Invalid amount" << endl;
        }
    }

     bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) { 
            balance -= amount;
            cout << "Withdrawn: " << amount << " | Remaining Balance: " << balance << endl;
            return true;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
            return false;
        }
    }

    void checkBalance() {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
     string accNum, accHolder;
    double initialBalance;
    
    cout << "Enter Account Number: ";
    cin >> accNum;
    cout << "Enter Account Holder Name: ";
    cin.ignore();
    getline(cin, accHolder);
    cout << "Enter Initial Balance: ";
    cin >> initialBalance;
    
    Account userAccount(accNum, accHolder, initialBalance);
    int choice;
    do {
        cout << "\nBank Account Menu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                double depositAmount;
                cout << "Enter amount to deposit: ";
                cin >> depositAmount;
                userAccount.deposit(depositAmount);
                break;
            case 2:
                double withdrawAmount;
                cout << "Enter amount to withdraw: ";
                cin >> withdrawAmount;
                userAccount.withdraw(withdrawAmount);
                break;
            case 3:
                userAccount.checkBalance();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
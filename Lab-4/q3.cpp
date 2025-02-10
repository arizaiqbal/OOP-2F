#include <iostream>
using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    Account() {
        this->balance = 0.0;
    }

    Account(string accountHolderName, string accountNumber, double balance) {
        this->accountHolderName = accountHolderName;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful. New balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds in account." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        }
    }

    void checkBalance() {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    Account a1("Ariza Iqbal", "344ER687-AA", 200625);
    Account a2("Armeen Azam", "789TY555-YD", 24500);

    int choice;
    double amount;

    cout << "------Bank Management System------" << endl;

    while (true) {
        cout << "1. Deposit Amount" << endl;
        cout << "2. Withdraw Amount" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the amount you want to deposit: ";
                cin >> amount;
                a1.deposit(amount);
                a2.deposit(amount);
                break;

            case 2:
                cout << "Enter the amount you want to withdraw: ";
                cin >> amount;
                a1.withdraw(amount);
                a2.deposit(amount);
                break;

            case 3:
                cout << "---Checking Balance---" << endl;
                a1.checkBalance();
                a2.deposit(amount);
                break;

            case 4:
                cout << "Exiting......." << endl;
                return 0;

            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    }

    return 0;
}
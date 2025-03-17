#include <iostream>
#include <string>

using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

public:
    Account(string accNumber, string holderName, double initialBalance, string type = "General")
        : accountNumber(accNumber), accountHolderName(holderName), balance(initialBalance), accountType(type) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    virtual void calculateInterest() {
        cout << "Interest Calculation for General Account is not applicable." << endl;
    }

    virtual void printStatement() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: $" << balance << endl;
    }

    void getAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(string accNumber, string holderName, double initialBalance, double rate, double minBalance)
        : Account(accNumber, holderName, initialBalance, "Savings"), interestRate(rate), minimumBalance(minBalance) {}

    void calculateInterest() override {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest added: $" << interest << endl;
    }

    void withdraw(double amount) override {
        if (balance - amount >= minimumBalance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        } else {
            cout << "Withdrawal failed. Minimum balance of $" << minimumBalance << " required." << endl;
        }
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Minimum Balance: $" << minimumBalance << endl;
    }
};

class CheckingAccount : public Account {
private:
    double transactionFee;

public:
    CheckingAccount(string accNumber, string holderName, double initialBalance, double fee)
        : Account(accNumber, holderName, initialBalance, "Checking"), transactionFee(fee) {}

    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= (amount + transactionFee);
            cout << "Withdrawn: $" << amount << " with a transaction fee of $" << transactionFee << endl;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Transaction Fee: $" << transactionFee << endl;
    }
};

int main() {
    Account *account1 = new Account("1234567890", "John Doe", 1000.0);
    SavingsAccount *savingsAccount = new SavingsAccount("9876543210", "Alice Smith", 1500.0, 3.5, 500.0);
    CheckingAccount *checkingAccount = new CheckingAccount("1112223333", "Bob Johnson", 2000.0, 2.0);

    cout << "Account 1:" << endl;
    account1->printStatement();
    cout << endl;

    cout << "Savings Account:" << endl;
    savingsAccount->printStatement();
    cout << endl;

    cout << "Checking Account:" << endl;
    checkingAccount->printStatement();
    cout << endl;

    account1->deposit(500);
    account1->withdraw(200);
    account1->getAccountInfo();
    cout << endl;

    savingsAccount->deposit(200);
    savingsAccount->withdraw(1000);
    savingsAccount->calculateInterest();
    savingsAccount->printStatement();
    cout << endl;

    checkingAccount->deposit(300);
    checkingAccount->withdraw(500);
    checkingAccount->printStatement();
    cout << endl;

    delete account1;
    delete savingsAccount;
    delete checkingAccount;

    return 0;
}

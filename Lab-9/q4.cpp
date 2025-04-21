#include<iostream>
using namespace std;
#include<string>

class PaymentMethod {
public:
    virtual bool processPayment(double amount) = 0; 
    virtual ~PaymentMethod() {}
 };


class CreditCard : public PaymentMethod {
private:
    string cardNumber;
public:
    CreditCard(string number) : cardNumber(number) {}
    bool processPayment(double amount) override {
        cout << "Processing credit card payment of $" << amount << " using card: " << cardNumber << endl;
        return true; 
    }
};


class DigitalWallet : public PaymentMethod {
private:
    double balance;
public:
    DigitalWallet(double initialBalance) : balance(initialBalance) {}
    bool processPayment(double amount) override {
        if (amount <= balance) {
            balance -= amount;
            cout << "Processing digital wallet payment of $" << amount << ". Remaining balance: $" << balance << endl;
            return true; 
        } else {
            cout << "Insufficient funds in digital wallet for payment of $" << amount << endl;
            return false; 
        }
    }
};
int main(){
    CreditCard myCard("1234-5678-9012-3456");
    DigitalWallet myWallet(100.0);  
    return 0;
}


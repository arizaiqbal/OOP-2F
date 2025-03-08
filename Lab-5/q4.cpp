#include <iostream>
using namespace std;

class BankAccount{
    private:
    string accountNumber;
    string accountHolderName;
    double balance;

    public: 
    BankAccount(string accNum = "123", string accHolder = "abc", double b = 0): accountNumber(accNum),accountHolderName(accHolder),balance(b){}

    void deposit (double amount){
        if(amount > 0)
        balance +=amount;
        cout << "insufficient amount" << endl;
    }

    void withdraw (double amount){
        if(amount > 0 && amount < balance)
                balance -=amount;
        else
        cout << "insufficient amount" << endl;
    }
   
    void display(){
    cout << "Account Number: "<< accountNumber <<endl;
    cout << "Account Holder Name: "<< accountHolderName <<endl;
    cout << "Balance: "<< balance <<endl;
    }
    
};


int main(){
    BankAccount acc[3]{

         {"H-24K0854" , "Ariza Iqbal" , 20000},
         {"H-24K1021" , "Fatima Salman" , 26000},
         {"F-24K0654" , "Armeen Azam" , 50000}
        
        };

    for(int i = 0 ; i < 3 ; i++){
        acc[i].display();
        acc[i].deposit(5000.0);
        acc[i].withdraw(400.0);
        acc[i].display();
    }
    
    return 0;
}
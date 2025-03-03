#include <iostream>
 
using namespace std;

class LoanHelper {
private:
    static const float interestRate;
    float loanAmount;
    int months;

public:
    LoanHelper(float amount, int m) {
        loanAmount = amount;
        months = m;
    }


    float calculateMonthlyPayment() {
        float monthlyPayment = loanAmount / months;
        float interest = monthlyPayment * interestRate; 
        return monthlyPayment + interest; 
    }

    float getLoanAmount() {
        return loanAmount;
    }

    int getMonths() {
        return months;
    }
};

const float LoanHelper::interestRate = 0.05; 

int main() {

    float loanAmount;
    int months;


    cout << "Enter the loan amount: ";
    cin >> loanAmount;
    cout << "Enter the number of months for repayment: ";
    cin >> months;

    LoanHelper loan(loanAmount, months);

    float monthlyRepayment = loan.calculateMonthlyPayment();

    cout << fixed; 
    cout << "You have to pay " << monthlyRepayment << " every month for " 
         << months << " months to repay your loan." << endl;

    return 0;
}

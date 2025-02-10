// <!-- You are building an employee management system. Create a class `Employee` to manage employee
// records.
// Requirements:
// 1. Attributes:
//  `employeeID` (int)
//  `name` (string)
//  `department` (string)
//  `salary` (double)
// 2. Define a default constructor that initializes `salary` to `0.0`.
// 3. Define a parameterized constructor to initialize all attributes.
// 4. Add methods:
//  `giveBonus(double amount)`: Adds the bonus amount to the employee's salary.
//  `isManager()`: Returns `true` if the employee's department is "Management".
//  `displayDetails()`: Displays the employee's details.
// 5. Create a few `Employee` objects and test the methods. -->

#include <iostream>
using namespace std;

class Employee{
    private:
    int employeeID;
    string name;
    string department;
    double salary;

public:
    Employee(){
    this->salary = 0.0;
    }

    Employee(int employeeID, string name, string department, double salary){
    this->employeeID = employeeID;
    this->name = name;
    this->department = department;
    this->salary = salary;
    }

void giveBonus(double amount) {
        salary += amount;
        cout << "Bonus of " << amount << " added. New salary: " << salary << endl;
    }


bool isManager(){
    if (department == "Management"){
    return true; 
    }
    else{
        return false;
    }
}

void displayDetails(){
    cout << "Employee ID: " << employeeID << endl;
    cout << "Employee Name: " << name << endl;
    cout << "Employee's Department: " << department << endl;
    cout << "Employee's Salary: " << salary << endl;
    cout << "-------------------------" << endl;

}
};

int main(){
    Employee e1(2122, "Ariza Iqbal", "Management", 450000);
    Employee e2(1442, "Armeen Azam", "Product Design", 250000);

    double amount;

    cout << "Initial Employee Details:" << endl;
    e1.displayDetails();
    e2.displayDetails();

    cout << "----Bonus----" << endl;
    cout << "Enter the amount of bonus: ";
    cin >> amount;
    e1.giveBonus(amount);
    e2.giveBonus(amount);

    cout << "Checking which employee is a manager:" << endl;
    cout << "Employee 1 is Manager: " << (e1.isManager() ? "Yes" : "No") << endl;
    cout << "Employee 2 is Manager: " << (e2.isManager() ? "Yes" : "No") << endl;

    cout << "Final Employee Details:" << endl;
    e1.displayDetails();
    e2.displayDetails();

    return 0;
}
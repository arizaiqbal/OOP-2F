// You are building a student management system. Create a class `Student` to manage student records.
// Requirements:
// 1. Attributes:
//  `studentID` (int)
//  `name` (string)
//  `age` (int)
//  `grade` (char)
// 2. Define a default constructor that initializes `grade` to `'N'` (Not Assigned).
// 3. Define a parameterized constructor to initialize all attributes.
// 4. Add methods:
//  `promoteStudent()`: Upgrades the student's grade (e.g., from 'A' to 'B').
//  `isEligibleForScholarship()`: Returns `true` if the student's grade is 'A'.
//  `displayDetails()`: Displays the student's details.
// 5. Create a few `Student` objects and test the methods.

#include <iostream>
using namespace std;

class Student{
    private:
    int studentID;
    string name;
    int age;
    char grade;

public:
Student(){
    this->grade = 'N';

}

Student(int studentID, string name, int age, char grade){
    this->studentID = studentID;
    this->name = name;
    this->age = age;
    this->grade = grade;
}

char promoteStudent(){
   if ((grade > 'A' || grade > 'a') && (grade <'F' || grade < 'f')){
    grade--;
    return grade;
   }
   else{
    cout << "Already an A-star student no need for promotion. \n \n";
    return grade;
   }
}

bool isEligibleForScholarship(){
    return grade == 'A';
    }

void displayDetails(){
    cout << "Student ID:" << studentID << endl;
    cout << "Name:" << name << endl;
    cout << "Age:" << age << endl;
    cout << "Grade:" << grade << endl;
}
};



int main(){
    Student s1(5154, "Ariza", 22, 'C');
    Student s2(0654, "Armeen", 20, 'A');
    cout << "Student details before grade promotion: \n";
    s1.displayDetails();
    s2.displayDetails();

    cout << "\nPromoting Grades....\n";
    s1.promoteStudent();
    s2.promoteStudent();

    cout << "\nStudent details after grade promotion: \n";
    s1.displayDetails();
    s2.displayDetails();
        

    cout << " \nScholarShip Details:\n";
    cout << "Is Ariza eligible for scholarship?"<< (s1.isEligibleForScholarship() ? "Yes" : "No") << endl;
    cout << "Is Armeen eligible for scholarship?" << (s2.isEligibleForScholarship() ? "Yes" : "No")<< endl;

    return 0;
}
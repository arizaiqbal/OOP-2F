#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name, id, address, phoneNumber, email;
public:
    Person(string n, string i, string a, string p, string e) : name(n), id(i), address(a), phoneNumber(p), email(e) {}
    virtual void displayInfo() {
        cout << "Name: " << name << "\nID: " << id << "\nAddress: " << address << "\nPhone: " << phoneNumber << "\nEmail: " << email << "\n";
    }
};

class Student : public Person {
private:
    int coursesEnrolled;
    float GPA;
    int enrollmentYear;
public:
    Student(string n, string i, string a, string p, string e, int c, float g, int y) : 
        Person(n, i, a, p, e), coursesEnrolled(c), GPA(g), enrollmentYear(y) {}
    void displayInfo() override {
        Person::displayInfo();
        cout << "Courses Enrolled: " << coursesEnrolled << "\nGPA: " << GPA << "\nEnrollment Year: " << enrollmentYear << "\n";
    }
};

class Professor : public Person {
private:
    string department;
    int coursesTaught;
    double salary;
public:
    Professor(string n, string i, string a, string p, string e, string d, int c, double s) : 
        Person(n, i, a, p, e), department(d), coursesTaught(c), salary(s) {}
    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << "\nCourses Taught: " << coursesTaught << "\nSalary: $" << salary << "\n";
    }
};

class Staff : public Person {
private:
    string department;
    string position;
    double salary;
public:
    Staff(string n, string i, string a, string p, string e, string d, string pos, double s) : 
        Person(n, i, a, p, e), department(d), position(pos), salary(s) {}
    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << "\nPosition: " << position << "\nSalary: $" << salary << "\n";
    }
};

class Course {
private:
    string courseId, courseName, instructor;
    int credits;
    string schedule;
public:
    Course(string id, string name, string instr, int c, string sched) : 
        courseId(id), courseName(name), instructor(instr), credits(c), schedule(sched) {}
    void displayCourse() {
        cout << "Course ID: " << courseId << "\nCourse Name: " << courseName << "\nInstructor: " << instructor 
             << "\nCredits: " << credits << "\nSchedule: " << schedule << "\n";
    }
};

int main() {
    Student s("Alice Brown", "S123", "123 Main St", "555-1234", "alice@email.com", 5, 3.8, 2022);
    Professor p("Dr. Smith", "P456", "456 Elm St", "555-5678", "smith@email.com", "Computer Science", 3, 75000);
    Staff st("John Doe", "ST789", "789 Oak St", "555-9012", "john@email.com", "HR", "Manager", 50000);
    Course c("CS101", "Intro to Programming", "Dr. Smith", 4, "MWF 9:00-10:30 AM");

    cout << "--- Student Information ---\n";
    s.displayInfo();
    
    cout << "\n--- Professor Information ---\n";
    p.displayInfo();
    
    cout << "\n--- Staff Information ---\n";
    st.displayInfo();
    
    cout << "\n--- Course Information ---\n";
    c.displayCourse();

    return 0;
}

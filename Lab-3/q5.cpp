#include <iostream>
using namespace std;

class Calendar {
private:
    int currentYear;
    string months[12][31]; 

public:
    Calendar(int year) : currentYear(year) {
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 31; ++j) {
                months[i][j] = "";
            }
        }
    }

    void addTask(const string& taskDetails, int date, int month) {
        if (month < 1 || month > 12 || date < 1 || date > 31) {
            cout << "Invalid date or month!" << endl;
            return;
        }
        months[month - 1][date - 1] = taskDetails;
        cout << "Task added successfully!" << endl;
    }

    void removeTask(int date, int month) {
        if (month < 1 || month > 12 || date < 1 || date > 31) {
            cout << "Invalid date or month!" << endl;
            return;
        }
        months[month - 1][date - 1] = ""; 
        cout << "Task removed successfully!" << endl;
    }

    void showTasks() const {
        cout << "Tasks for the year " << currentYear << ":" << endl;
        for (int i = 0; i < 12; ++i) {
            cout << "Month " << (i + 1) << ":" << endl;
            for (int j = 0; j < 31; ++j) {
                if (!months[i][j].empty()) {
                    cout << "  Day " << (j + 1) << ": " << months[i][j] << endl;
                }
            }
        }
    }
};

int main() {

    Calendar myCalendar(2025);

    myCalendar.addTask("Complete OOP assignment", 22, 2);  
    myCalendar.addTask("Buy groceries", 5, 3);           
    myCalendar.addTask("Evaluation of project", 10, 4);               
    myCalendar.addTask("Dentist appointment", 20, 5);    
    myCalendar.addTask("Plan vacation", 1, 6);           
    myCalendar.addTask("Learn a new skill", 30, 7);     

   
    myCalendar.showTasks();


    myCalendar.removeTask(5, 2);        

  
    myCalendar.showTasks();

    return 0;
}
// Create a class called time that has separate int member data for hours, minutes, and seconds. One constructor
// should initialize this data to 0, and another should initialize it to fixed values. Another member function should
// display it, in 11:59:59 format. The final member function should add two objects of type time passed as
// arguments.
// A main() program should create two initialized time objects (should they be const?) and one that isn’t initialized.
// Then it should add the two initialized values together, leaving the result in the third time variable. Finally it should
// display the value of this third variable. Make appropriate member functions const.

#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:

    Time() : hours(0), minutes(0), seconds(0) {}

    
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
      
    }

   
    void display() const {
    
        if (hours < 10) cout << "0";
        cout << hours << ":";
        if (minutes < 10) cout << "0";
        cout << minutes << ":";
        if (seconds < 10)cout << "0";
        cout << seconds;
    }

  
    Time add(const Time& t1, const Time& t2) const {
        Time result;
        result.seconds = t1.seconds + t2.seconds;
        result.minutes = t1.minutes + t2.minutes;
        result.hours = t1.hours + t2.hours;


        return result;
    }


};

int main() {
   
    const Time t1(11, 59, 59); 
    const Time t2(0, 0, 1);    


    Time t3;

 
    t3 = t3.add(t1, t2);


    cout << "Time 1: ";
    t1.display();
    
    cout << "\nTime 2: ";
    t2.display();
    cout << "\nSum of Time 1 and Time 2: ";
    t3.display();

    return 0;
}
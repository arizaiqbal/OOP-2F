// Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a 50 cent toll. Mostly they do, but
// sometimes a car goes by without paying. The tollbooth keeps track of the number of cars that have gone by, and of
// the total amount of money collected.
// Model this tollbooth with a class called tollBooth. The two data items are a type unsigned int to hold the total
// number of cars, and a type double to hold the total amount of money collected. A constructor initializes both of
// these to 0. A member function called payingCar() increments the car total and adds 0.50 to the cash total. Another
// function,
// called nopayCar(), increments the car total but adds nothing to the cash total. Finally, a member function called
// display() displays the two totals. Make appropriate member functions const.
// Include a program to test this class. This program should allow the user to push one key to count a paying car, and
// another to count a nonpaying car. Pushing the Esc key should cause the program to print out the total cars and
// total cash and then exit.

#include <iostream>
#include <conio.h>
using namespace std;


class tollBooth{
    unsigned int car;
    double amount;


public:
    tollBooth() : car(0), amount(0){};

void payingCar(){
    car++;
    amount += 0.50;
}


void nopayCar(){
    car++;
}

void display() const {
        cout << "Total cars: " << car << endl;
        cout << "Total cash: $" << amount << endl;
    }

};



int main(){
    tollBooth c1;
    string choice;
    cout << "Car Counting Program \n";
    cout << "Press 'P' to count a paying car \n";
    cout << "Press 'N' to count a non-paying car \n";
    cout << "Press ESC to exit \n";



    while (true){
    if(_kbhit()){
        char ch = _getch();

        if (ch == 27){
            cout << "Exiting program..." << endl;
                break;
        }

        else if (ch == 'P' || ch == 'p'){
            cout << "Paying Car Counted\n";
            c1.payingCar();
        }
    
        else if (ch == 'N' || ch == 'n'){
            cout << "Non-Paying Car Counted\n";
            c1.nopayCar();
        }

        else{
            cout << "Invalid input \n";

        }

    }
}
  
    c1.display();

    return 0;
}
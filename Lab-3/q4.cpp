#include <iostream>
#include <iomanip>
using namespace std;

class Angle {
private:
    int degrees;
    float minutes;
    char direction;

public:
    Angle(int deg, float min, char dir) : degrees(deg), minutes(min), direction(dir) {}

    void obtainAngle() {
        cout << "Enter degrees: ";
        cin >> degrees;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter direction (N, S, E, W): ";
        cin >> direction;
        direction = toupper(direction);
    }

    void displayAngle() const {
        cout << degrees << "\xF8" << fixed << setprecision(1) << minutes << "' " << direction << endl;
    }
};

int main() {
    Angle initialAngle(149, 34.8, 'W');
    cout << "Initial angle: ";
    initialAngle.displayAngle();

    Angle userAngle(0, 0.0, 'N');
    char choice;
    do {
        userAngle.obtainAngle();
        cout << "You entered: ";
        userAngle.displayAngle();

        cout << "Do you want to enter another angle? (y/n): ";
        cin >> choice;
    } while (tolower(choice) == 'y');

    return 0;
}
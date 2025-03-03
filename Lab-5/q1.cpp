#include <iostream>
using namespace std;

class Square {
private:
    float sideLength;
    float area;
    static float allareas;

public:
    Square() {
        sideLength = 0;
        area = 0;
    }

    Square(float length) {
        sideLength = length;
        area = 0;
    }

    float getLength() {
        return sideLength;
    }

    float getArea() {
        return area;
    }

    static float getAllArea() {
        return allareas;
    }

 
    float calcArea() {
        area = sideLength * sideLength;
        allareas += area; 
        return area;
    }

    void setLength(float length) {
        sideLength = length;
    }

    void setArea(float a) {
        area = a;
    }
};

float Square::allareas = 0;

int main() {
    Square s1(45.5), s2(50.0), s3(25.5);

    s1.calcArea();
    s2.calcArea();
    s3.calcArea();

    cout << "Area of Square 1: " << s1.getArea() << endl;
    cout << "Area of Square 2: " << s2.getArea() << endl;
    cout << "Area of Square 3: " << s3.getArea() << endl;
    cout << "Total area of all squares: " << Square::getAllArea() << endl;

    return 0;
}

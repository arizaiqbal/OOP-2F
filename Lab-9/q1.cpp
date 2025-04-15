#include <iostream>
using namespace std;

class Vehicle{
    protected:
    string model;
    double rate;

    public:

    Vehicle(string m, double r){
        model = m;
        rate = r;
    }

    virtual double getDailyRate () const = 0;
    virtual void displayDetails () const = 0;

    virtual ~Vehicle() {}

};

class Car : public Vehicle{
    public:
    
    Car(string m, double r) : Vehicle(m,r){}

    double getDailyRate() const override{
        return rate;
    }

    void displayDetails() const override{
        cout << "Model: " << model << endl;
        cout << "Rate: $" << rate << endl;
    }


};

class Bike : public Vehicle{
    public:

    Bike(string m, double r) : Vehicle(m,r){}

    double getDailyRate() const override{
        return rate;
    }

    void displayDetails() const override{
        cout << "Model: " << model << endl;
        cout << "Rate: $" << rate << endl;
    }

};


int main(){
    const int totalVehicles = 2;
    Vehicle* vehicles[totalVehicles];

    vehicles[0] = new Car("Sportage", 5500.0);
    vehicles[1] = new Bike("Yamaha FZ", 200.0);

    cout << "Vehicle Rental Options:\n\n";

    for (int i = 0; i < totalVehicles; ++i) {
        vehicles[i]->displayDetails();
        cout << "-------------------------\n";
    }

     for (int i = 0; i < totalVehicles; ++i) {
        delete vehicles[i];
    }


    
    return 0;
}
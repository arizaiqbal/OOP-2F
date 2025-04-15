#include <iostream>
using namespace std;

class SmartDevice{
    public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus() = 0;

     virtual ~SmartDevice() {}


};

class LightBulb : public SmartDevice{
    private:
    bool isOn;
    int brightness;

    public:
    LightBulb(int b) : isOn(false), brightness(b) {}

    void turnOn() override{
        isOn = true;
        cout << "LightBulb turned ON.\n";
    }

    void turnOff() override{
        isOn = false;
        cout << "LightBulb turned OFF.\n";
    }

    void getStatus() override{
        cout << "LightBulb Status: " << (isOn ? "ON" : "OFF") << ", Brightness: " << brightness << "%" << endl;
    }
    

};

class Thermostat : public SmartDevice{
    private:
    bool isOn;
    double temperature;

    public:
    Thermostat(double t) : isOn(false), temperature(t){}

    void turnOn() override{
        isOn = true;
        cout << "Thermostat turned ON.\n";
    }

    void turnOff() override{
        isOn = false;
        cout << "Thermostat turned OFF.\n";
    }

    void getStatus() override{
        cout << "Thermostat Status: " << (isOn ? "ON" : "OFF") << ", Temperature: " << temperature << "C" << endl;
    }
    
};

int main(){
    const int totalDevices = 2;
    SmartDevice* devices[totalDevices];

    devices[0] = new LightBulb(50);
    devices[1] = new Thermostat(25);

     cout << "\nTurning on all devices...\n";
    for (int i = 0; i < totalDevices; ++i) {
        devices[i]->turnOn();
    }

    cout << "\nDevice Statuses:\n";
    for (int i = 0; i < totalDevices; ++i) {
        devices[i]->getStatus();
    }

    cout << "\nTurning off all devices...\n";
    for (int i = 0; i < totalDevices; ++i) {
        devices[i]->turnOff();
    }

    cout << "\nDevice Statuses:\n";
    for (int i = 0; i < totalDevices; ++i) {
        devices[i]->getStatus();
    }

    for (int i = 0; i < totalDevices; ++i) {
        delete devices[i];
    }


    return 0;
}
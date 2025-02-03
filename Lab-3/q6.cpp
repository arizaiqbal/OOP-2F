// Create a class called Smartphone with the following attributes:
//  Company
//  Model
//  Display Resolution
//  RAM
//  ROM
//  Storage

// Create getter and setter methods for your attributes. A smartphone has some specific actions that it can perform.
// For example:
// 1. Make a phone call
// 2. Send a message
// 3. Connect to the wifi
// 4. Browse the internet

// Create different smartphone objects. Set their attributes

#include <iostream>
#include <string>
using namespace std;

class Smartphone {
private:
    string company;
    string model;
    string displayResolution;
    int ram; 
    int rom;  
    int storage;  

public:
    
    void setCompany(const string &company) {
        this->company = company;
    }
    string getCompany() const {
        return company;
    }

    void setModel(const string &model) {
        this->model = model;
    }
    string getModel() const {
        return model;
    }

    void setDisplayResolution(const string &resolution) {
        this->displayResolution = resolution;
    }
    string getDisplayResolution() const {
        return displayResolution;
    }

    void setRam(int ram) {
        this->ram = ram;
    }
    int getRam() const {
        return ram;
    }

    void setRom(int rom) {
        this->rom = rom;
    }
    int getRom() const {
        return rom;
    }

    void setStorage(int storage) {
        this->storage = storage;
    }
    int getStorage() const {
        return storage;
    }

  
    void makePhoneCall(const string &contact) {
        cout << "Making a phone call to " << contact << "...\n";
    }

    void sendMessage(const string &contact, const string &message) {
        cout << "Sending message to " << contact << ": " << message << endl;
    }

    void connectToWifi(const string &wifiName) {
        cout << "Connecting to WiFi network: " << wifiName << "...\n";
    }

    void browseInternet(const string &website) {
        cout << "Browsing the internet at: " << website << "...\n";
    }
};

int main() {
    
    Smartphone phone1, phone2;


    phone1.setCompany("Apple");
    phone1.setModel("iPhone 14");
    phone1.setDisplayResolution("2532 x 1170");
    phone1.setRam(6);
    phone1.setRom(128);
    phone1.setStorage(256);

    
    phone2.setCompany("Samsung");
    phone2.setModel("Galaxy S21");
    phone2.setDisplayResolution("2400 x 1080");
    phone2.setRam(8);
    phone2.setRom(128);
    phone2.setStorage(512);


    cout << "Phone 1 Details: \n";
    cout << "Company: " << phone1.getCompany() << endl;
    cout << "Model: " << phone1.getModel() << endl;
    cout << "Display Resolution: " << phone1.getDisplayResolution() << endl;
    cout << "RAM: " << phone1.getRam() << " GB\n";
    cout << "ROM: " << phone1.getRom() << " GB\n";
    cout << "Storage: " << phone1.getStorage() << " GB\n";


    phone1.makePhoneCall("Mariam");
    phone1.sendMessage("Mariam", "Hey, how are you?");
    phone1.connectToWifi("PTCL-BB");
    phone1.browseInternet("www.chatgpt.com");

    cout << "\nPhone 2 Details: \n";
    cout << "Company: " << phone2.getCompany() << endl;
    cout << "Model: " << phone2.getModel() << endl;
    cout << "Display Resolution: " << phone2.getDisplayResolution() << endl;
    cout << "RAM: " << phone2.getRam() << " GB\n";
    cout << "ROM: " << phone2.getRom() << " GB\n";
    cout << "Storage: " << phone2.getStorage() << " GB\n";

    phone2.makePhoneCall("Hafsa");
    phone2.sendMessage("Hafsa", "Let's meet up tomorrow!");
    phone2.connectToWifi("FASTKHI");
    phone2.browseInternet("www.samsung.com");

    return 0;
}

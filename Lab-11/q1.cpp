#include <iostream>
#include <exception>
class invalidexception : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid exception occurred";
    }
};
void validAge(int age){
    if (age < 0 || age > 120) {
        throw invalidexception();
    } else {
        std::cout << "Valid age: " << age << std::endl;
    }
}
using namespace std;
 int main(){
    int age;
    cout << "Enter age: ";
    cin >> age;
    try {
        validAge(age);
    } catch (const invalidexception& e) {
        cout << e.what() << std::endl;
    } 
    return 0;
 }
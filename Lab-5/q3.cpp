#include <iostream>
using namespace std;

class ValidateString {
    string test;

public:
    ValidateString(string s = "abc") : test(s) {}

   
    bool checkString() const {
        for (char c : test) {
            if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    ValidateString S1("ari"), S2("b67"), S3("12-55");

    cout << "S1 is " << (S1.checkString() ? "valid" : "invalid") << endl;
    cout << "S2 is " << (S2.checkString() ? "valid" : "invalid") << endl;
    cout << "S3 is " << (S3.checkString() ? "valid" : "invalid") << endl;

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

class Message {
private:
    string msg;

public:
    Message(string text = "") {
        msg = text;  
    }

    void setMsg(string text) {
        msg = text;
    }

    string toString() const {
        return msg;
    }
};

class SMS : public Message {
private:
    string recipientContactNo;

public:
    SMS(string text = "", string contactNo = "") : Message(text) {
        recipientContactNo = contactNo;
    }

    void setRecipientContactNo(string phoneNum) {
        recipientContactNo = phoneNum;
    }

    string getRecipientContactNo() {
        return recipientContactNo;
    }

    string toString() {
        return "To: " + recipientContactNo + " Message: " + Message::toString();
    }
};

class Email : public Message {
private:
    string sender;
    string receiver;
    string subject;

public:
    Email() {}

    Email(string msg = "", string s = "", string r = "", string sub = "") : Message(msg) {
        sender = s;
        receiver = r;
        subject = sub;
    }

    void setSender(string s) {
        sender = s;
    }

    void setReceiver(string r) {
        receiver = r;
    }

    void setSubject(string sub) {
        subject = sub;
    }

    string getSender() {
        return sender;
    }

    string getReceiver() {
        return receiver;
    }

    string getSubject() {
        return subject;
    }

    string toString() {
        return "From: " + sender + "\nTo: " + receiver + "\nSubject: " + subject + "\nMessage: " + Message::toString();
    }
};

bool ContainsKeyword(const Message &msg, const string &keyword) {
    return msg.toString().find(keyword) != string::npos;
}

string EncodeMessage(const string &message) {
    string encodedMessage = message;

    for (char &ch : encodedMessage) {
        if (isalpha(ch)) {
            if (ch == 'Z') ch = 'A';
            else if (ch == 'z') ch = 'a';
            else ch += 1;
        }
    }

    return encodedMessage;
}

int main() {
    SMS sms("Hello, how are you?", "123-456-7890");
    cout << "SMS Details:\n" << sms.toString() << endl;

    Email email("This is Java", "alice@example.com", "bob@example.com", "Greetings");
    cout << "\nEmail Details:\n" << email.toString() << endl;

    string keyword = "Java";
    if (ContainsKeyword(email, keyword)) {
        cout << "\nKeyword '" << keyword << "' found in the email!" << endl;
    } else {
        cout << "\nKeyword '" << keyword << "' NOT found in the email!" << endl;
    }

    string originalMsg = email.toString();
    string encodedMsg = EncodeMessage(originalMsg);

    cout << "\nEncoded Email Message:\n" << encodedMsg << endl;

    return 0;
}

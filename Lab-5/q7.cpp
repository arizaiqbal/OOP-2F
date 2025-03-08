#include <iostream>
using namespace std;

class Menu {
    string* items;
    double* prices;
    int itemsNum;

public:
    Menu(int itemNum = 0, double* pricesArr = nullptr, string* itemsArr = nullptr): itemsNum(itemNum) {

        items = new string[itemsNum];
        prices = new double[itemsNum];

        if (pricesArr && itemsArr) {
            for (int i = 0; i < itemsNum; i++) {
                items[i] = itemsArr[i];
                prices[i] = pricesArr[i];
            }
        }
    }

    ~Menu() {
        delete[] items;
        delete[] prices;
    }

    void display_menu() {
        for (int i = 0; i < itemsNum; i++) {
            cout << i + 1 << ". " << items[i] << " : " << prices[i] << endl;
        }
    }
};

class Payment {
    double amount;

public:
    Payment(double amt) : amount(amt) {}

    void processPayment() {
        cout << "Payment of $" << amount << " processed." << endl;
    }
};

class Order {
    string* orderedItems;
    double* orderedPrices;
    int itemCount;
    double totalAmount;

public:
    Order(int count = 0) : itemCount(count), totalAmount(0) {
        orderedItems = new string[itemCount];
        orderedPrices = new double[itemCount];
    }

    ~Order() {
        delete[] orderedItems;
        delete[] orderedPrices;
    }

    void addItem(string item, double price, int index) {
        if (index < itemCount) {
            orderedItems[index] = item;
            orderedPrices[index] = price;
            totalAmount += price;
        }
    }

    void displayOrder() {
        cout << "\nOrder Summary:" << endl;
        for (int i = 0; i < itemCount; i++) {
            cout << orderedItems[i] << " - $" << orderedPrices[i] << endl;
        }
        cout << "Total: $" << totalAmount << endl;
    }

    void makePayment() {
        Payment payment(totalAmount);
        payment.processPayment();
    }
};

int main() {
    string foodItems[] = {"Burger", "Lasagne", "Pasta"};
    double foodPrices[] = {5.99, 12.55, 13.99};
    Menu restaurantMenu(3, foodPrices, foodItems);
    restaurantMenu.display_menu();

    Order myOrder(2);
    myOrder.addItem("Burger", 5.99, 0);
    myOrder.addItem("Pasta", 13.99, 1);
    myOrder.displayOrder();
    myOrder.makePayment();

    return 0;
}
// Create a class for a stationary shop. The stationary shop maintains a list for all the items that it sells (hint: array of
// strings), and another list with the prices of the items (hint: array of prices).
// Create a menu-driven program to:
// 1. Allow the shop owner to add the items and their prices.
// 2. Fetch the list of items
// 3. Edit the prices of the items
// 4. View all the items and their prices
// Create a receipt that the shopkeeper can share with their customers. The receipt can only be created after the
// shopkeeper inputs the items and their amounts bought by the customer.

#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

class StationaryShop {
private:
    string items[100];           
    double prices[100];         
    int itemCount;               
public:
  
    StationaryShop() {
        itemCount = 0;
    }

    void addItem() {
        if (itemCount < 100) {
            cout << "Enter item name: ";
            cin >> items[itemCount];
            cout << "Enter price of " << items[itemCount] << ": ";
            cin >> prices[itemCount];
            itemCount++;
            cout << "Item added successfully!\n";
        } else {
            cout << "Item limit reached!\n";
        }
    }

    
    void fetchItems() {
        cout << "Items available in the shop:\n";
        for (int i = 0; i < itemCount; i++) {
            cout << i + 1 << ". " << items[i] << " - $" << fixed << setprecision(2) << prices[i] << endl;
        }
    }

  
    void editPrice() {
        int index;
        cout << "Enter the item number you want to edit the price of: ";
        cin >> index;
        if (index >= 1 && index <= itemCount) {
            cout << "Enter new price for " << items[index - 1] << ": ";
            cin >> prices[index - 1];
            cout << "Price updated successfully!\n";
        } else {
            cout << "Invalid item number!\n";
        }
    }

    
    void viewItems() {
        cout << "All items and their prices:\n";
        for (int i = 0; i < itemCount; i++) {
            cout << i + 1 << ". " << items[i] << " - $" << prices[i] << endl;
        }
    }


    void generateReceipt() {
        string purchasedItems[100];
        int quantities[100];
        double totalAmount = 0.0;
        int itemIndex, quantity, numItems;

        cout << "Enter number of items the customer bought: ";
        cin >> numItems;

        for (int i = 0; i < numItems; i++) {
            cout << "Enter item number: ";
            cin >> itemIndex;
            if (itemIndex >= 1 && itemIndex <= itemCount) {
                purchasedItems[i] = items[itemIndex - 1];
                cout << "Enter quantity of " << purchasedItems[i] << ": ";
                cin >> quantities[i];
                totalAmount += prices[itemIndex - 1] * quantities[i];
            } else {
                cout << "Invalid item number! Please try again.\n";
                i--;
            }
        }

   
        cout << "\n--- Receipt ---\n";
        cout << left << setw(20) << "Item" << setw(10) << "Quantity" << "Price" << setw(10) << "Total" << endl;
        
        for (int i = 0; i < numItems; i++) {
            cout << left << setw(20) << purchasedItems[i]
                 << setw(10) << quantities[i]
                 << "$" << fixed << setprecision(2) << prices[itemIndex - 1]
                 << setw(10) << "$" << prices[itemIndex - 1] * quantities[i] << endl;
        }
        
        cout << "Total Amount: $" << fixed << setprecision(2) << totalAmount << endl;
    }
};

int main() {
    StationaryShop shop;
    int choice;

    do {
        cout << "Stationary Shop Menu\n";
        cout << "1. Add Item\n";
        cout << "2. Fetch List of Items\n";
        cout << "3. Edit Price of Item\n";
        cout << "4. View All Items and Prices\n";
        cout << "5. Generate Receipt\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                shop.addItem();
                break;
            case 2:
                shop.fetchItems();
                break;
            case 3:
                shop.editPrice();
                break;
            case 4:
                shop.viewItems();
                break;
            case 5:
                shop.generateReceipt();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

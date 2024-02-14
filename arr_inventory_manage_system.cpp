#include <iostream>
#include <string>
using namespace std;

// Maximum number of products
const int MAX_PRODUCTS = 100;
// Structure to represent a product
struct Product {
    string name;
    int quantity;
};
// Inventory management class
class InventoryManager {
private:
    Product products[MAX_PRODUCTS];
    int numProducts;

public:
    // Constructor
    InventoryManager() : numProducts(0) {}

    // Function to add a product
    void addProduct() {
        if (numProducts < MAX_PRODUCTS) {
            string name;
            int quantity;
            cout << "Enter product name: ";
            cin >> name;
            cout << "Enter quantity: ";
            cin >> quantity;

            products[numProducts].name = name;
            products[numProducts].quantity = quantity;
            numProducts++;
            cout << "Product added successfully.\n";
        } else {
            cout << "Inventory full. Cannot add more products.\n";
        }
    }

    // Function to update quantity of a product
    void updateQuantity() {
        string name;
        int quantityChange;
        cout << "Enter product name: ";
        cin >> name;
        cout << "Enter quantity change (+ for addition, - for subtraction): ";
        cin >> quantityChange;

        for (int i = 0; i < numProducts; ++i) {
            if (products[i].name == name) {
                products[i].quantity += quantityChange;
                cout << "Quantity updated successfully.\n";
                return;
            }
        }
        cout << "Product not found.\n";
    }

    // Function to display current inventory
    void displayInventory() {
        cout << "Current Inventory:\n";
        for (int i = 0; i < numProducts; ++i) {
            cout << products[i].name << ": " << products[i].quantity << "\n";
        }
    }

    // Function to alert when a product is running low on stock
    void alertLowStock(int threshold) {
        cout << "Products running low on stock:\n";
        for (int i = 0; i < numProducts; ++i) {
            if (products[i].quantity < threshold) {
                cout << products[i].name << ": " << products[i].quantity << "\n";
            }
        }
    }
};

int main() {
    InventoryManager manager;
    int choice;
    int threshold;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add product\n";
        cout << "2. Update quantity\n";
        cout << "3. Display inventory\n";
        cout << "4. Alert low stock\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addProduct();
                break;
            case 2:
                manager.updateQuantity();
                break;
            case 3:
                manager.displayInventory();
                break;
            case 4:
                cout << "Enter threshold for low stock alert: ";
                cin >> threshold;
                manager.alertLowStock(threshold);
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

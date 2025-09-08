#include <iostream>
#include <string>
using namespace std;

// Base class: Product
class Product {
protected:
    string productName;
    int productID;
    float price;
public:
    void inputProduct() {
        cout << "Enter product name: ";
        cin.ignore();
        getline(cin, productName);
        cout << "Enter product ID: ";
        cin >> productID;
        cout << "Enter price: ";
        cin >> price;
    }
    void displayProduct() {
        cout << "Product Name: " << productName << endl;
        cout << "Product ID: " << productID << endl;
        cout << "Price: " << price << endl;
    }
};

// Derived class: Order
class Order : public Product {
protected:
    int quantity;
    string customerName;
public:
    void inputOrder() {
        inputProduct();
        cout << "Enter quantity: ";
        cin >> quantity;
        cin.ignore();
        cout << "Enter customer name: ";
        getline(cin, customerName);
    }
    void displayOrder() {
        displayProduct();
        cout << "Quantity: " << quantity << endl;
        cout << "Customer Name: " << customerName << endl;
    }
};

// Further derived class: Invoice
class Invoice : public Order {
    float taxRate = 0.18;      // defalt 18% GST
    float discountRate = 0.10; // defalt 10% discount
    float total, tax, discount, finalAmount;
public:
    void generateInvoice() {
        total = price * quantity;
        tax = total * taxRate;
        discount = total * discountRate;
        finalAmount = total + tax - discount;
    }
    void displayInvoice() {
        displayOrder();
        cout << "Total: " << total << endl;
        cout << "Tax (18%): " << tax << endl;
        cout << "Discount (10%): " << discount << endl;
        cout << "Final Amount: " << finalAmount << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of orders: ";
    cin >> n;
    Invoice invoices[n];

    for(int i=0; i<n; ++i) {
        cout << "\n--- Enter details for Order " << (i+1) << " ---\n";
        invoices[i].inputOrder();
        invoices[i].generateInvoice();
    }

    cout << "\n--- Invoices ---\n";
    for(int i=0; i<n; ++i) {
        cout << "\nInvoice " << (i+1) << ":\n";
        invoices[i].displayInvoice();
    }
    return 0;
}
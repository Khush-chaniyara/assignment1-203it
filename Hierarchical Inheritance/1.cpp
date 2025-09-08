/*
Name : Chaniyara KhushKumar Hematbhai 
Id:24IT472
Hierarchical Inheritance
Q-1
*/

#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string model;
    string company;
    float price;
public:
    void input() {
        cout << "Enter model: ";
        cin >> model;
        cout << "Enter company: ";
        cin >> company;
        cout << "Enter price: ";
        cin >> price;
    }
    virtual void display() {
        cout << "Model: " << model << endl;
        cout << "Company: " << company << endl;
        cout << "Price: " << price << endl;
    }
};

class Car : public Vehicle {
    int seats;
public:
    void input() {
        Vehicle::input();
        cout << "Enter seating capacity: ";
        cin >> seats;
    }
    void display() {
        Vehicle::display();
        cout << "Seating Capacity: " << seats << endl;
    }
};

class Bike : public Vehicle {
    string type;
public:
    void input() {
        Vehicle::input();
        cout << "Enter bike type (Sports/Cruiser/normal): ";
        cin >> type;
    }
    void display() {
        Vehicle::display();
        cout << "Bike Type: " << type << endl;
    }
};

class Truck : public Vehicle {
    float loadCapacity;
public:
    void input() {
        Vehicle::input();
        cout << "Enter load capacity of truch (in tons): ";
        cin >> loadCapacity;
    }
    void display() {
        Vehicle::display();
        cout << "Load Capacity: " << loadCapacity << " tons" << endl;
    }
};

int main() {
    int nC, nB, nT;

    cout << "Enter number of Cars: ";
    cin >> nC;
    Car cars[nC];
    for (int i = 0; i < nC; i++) {
        cout << "\nEnter details for Car " << (i+1) << ":\n";
        cars[i].input();
    }

    cout << "\nEnter number of Bikes: ";
    cin >> nB;
    Bike bikes[nB];
    for (int i = 0; i < nB; i++) {
        cout << "\nEnter details for Bike " << (i+1) << ":\n";
        bikes[i].input();
    }

    cout << "\nEnter number of Trucks: ";
    cin >> nT;
    Truck trucks[nT];
    for (int i = 0; i < nT; i++) {
        cout << "\nEnter details for Truck " << (i+1) << ":\n";
        trucks[i].input();
    }

    cout << "\n Vehicle Details :\n";

    for (int i = 0; i < nC; i++) {
        cout << "\nCar " << (i+1) << ":\n";
        cars[i].display();
    }
    for (int i = 0; i < nB; i++) {
        cout << "\nBike " << (i+1) << ":\n";
        bikes[i].display();
    }
    for (int i = 0; i < nT; i++) {
        cout << "\nTruck " << (i+1) << ":\n";
        trucks[i].display();
    }

    return 0;
}
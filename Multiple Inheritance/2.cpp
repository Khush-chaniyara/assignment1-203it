

#include <iostream>
#include <string>
using namespace std;

class Passenger {
protected:
    string name;
    int age;
public:
    void inputPassenger() {
        cout << "Enter passenger name: ";
        getline(cin, name);
        cout << "Enter passenger age: ";
        cin >> age;
        cin.ignore();
    }
    void displayPassenger() {
        cout << "Passenger Name: " << name << endl;
        cout << "Passenger Age: " << age << endl;
    }
};

class Flight {
protected:
    string flightNumber;
    string source;
    string destination;
    string time;
public:
    void inputFlight() {
        cout << "Enter flight number: ";
        getline(cin, flightNumber);
        cout << "Enter source: ";
        getline(cin, source);
        cout << "Enter destination: ";
        getline(cin, destination);
        cout << "Enter departure time: ";
        getline(cin, time);
    }
    void displayFlight()  {
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Departure Time: " << time << endl;
    }
};

class Reservation : public Passenger, public Flight {
public:
    void confirmTicket(){
        cout << "Ticket Confirmed!\n";
        cout << "\nReservation Ticket details\n";
        displayPassenger();
        displayFlight();
        }
};

int main() {
    Reservation res;
    res.inputPassenger();
    res.inputFlight();
    res.confirmTicket();
    return 0;
}
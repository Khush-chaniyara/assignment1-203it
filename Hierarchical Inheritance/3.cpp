/*
Name : Chaniyara KhushKumar Hematbhai 
Id:24IT472
Hierarchical Inheritance
Q-3
*/

#include <iostream>
#include <string>
using namespace std;

// Base class
class Tournament {
protected:
    string tname;
    string location;
    int year;
public:
    void inputTournament() {
        cout << "Enter Tournament Name: ";
        getline(cin, tname);
        cout << "Enter Location: ";
        getline(cin, location);
        cout << "Enter Year: ";
        cin >> year;
        cin.ignore();
    }
    void displayTournament() {
        cout << "Tournament: " << tname 
             << ", Location: " << location 
             << ", Year: " << year << endl;
    }
};

// Derived class: Cricket
class Cricket : public Tournament {
    int teams;
    int matches;
    string winner;
public:
    void inputCricket() {
        inputTournament();
        cout << "Enter number of teams: ";
        cin >> teams;
        cout << "Enter number of matches: ";
        cin >> matches;
        cin.ignore();
        cout << "Enter winner team: ";
        getline(cin, winner);
    }
    void displayCricket() {
        displayTournament();
        cout << "Teams: " << teams 
             << ", Matches: " << matches 
             << ", Winner: " << winner << endl;
    }
};

// Derived class: Football
class Football : public Tournament {
    int teams;
    int matches;
    string winner;
public:
    void inputFootball() {
        inputTournament();
        cout << "Enter number of teams: ";
        cin >> teams;
        cout << "Enter number of matches: ";
        cin >> matches;
        cin.ignore();
        cout << "Enter winner team: ";
        getline(cin, winner);
    }
    void displayFootball() {
        displayTournament();
        cout << "Teams: " << teams 
             << ", Matches: " << matches 
             << ", Winner: " << winner << endl;
    }
};

// Derived class: Hockey
class Hockey : public Tournament {
    int teams;
    int matches;
    string winner;
public:
    void inputHockey() {
        inputTournament();
        cout << "Enter number of teams: ";
        cin >> teams;
        cout << "Enter number of matches: ";
        cin >> matches;
        cin.ignore();
        cout << "Enter winner team: ";
        getline(cin, winner);
    }
    void displayHockey() {
        displayTournament();
        cout << "Teams: " << teams 
             << ", Matches: " << matches 
             << ", Winner: " << winner << endl;
    }
};

int main() {
    Cricket c;
    Football f;
    Hockey h;

    cout << "\n Enter Cricket Tournament Details \n";
    c.inputCricket();

    cout << "\n Enter Football Tournament Details \n";
    f.inputFootball();

    cout << "\n Enter Hockey Tournament Details \n";
    h.inputHockey();

    cout << "\n Tournament Details :\n";
    cout << "\nCricket:\n";
    c.displayCricket();

    cout << "\nFootball:\n";
    f.displayFootball();

    cout << "\nHockey:\n";
    h.displayHockey();

    return 0;
}
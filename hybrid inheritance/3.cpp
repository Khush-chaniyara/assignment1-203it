/*
Name : Chaniyara KhushKumar Hematbhai 
Id:24IT472
Hybrid Inheritance
Q-3
*/

#include <iostream>
#include <string>
using namespace std;

// Base Class
class Person {
protected:
    string name;
    int age;
public:
    void getData() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived Class: Student
class Student : virtual public Person {
protected:
    string studentID;
    string course;
public:
    void getData() {
        Person::getData();
        cout << "Enter Student ID: ";
        cin >> studentID;
        cin.ignore();
        cout << "Enter Course: ";
        getline(cin, course);
    }

    void display() {
        Person::display();
        cout << "Student ID: " << studentID << ", Course: " << course << endl;
    }
};

// Derived Class: Faculty
class Faculty : virtual public Person {
protected:
    string facultyID;
    string department;
public:
    void getData() {
        Person::getData();
        cout << "Enter Faculty ID: ";
        cin >> facultyID;
        cin.ignore();
        cout << "Enter Department: ";
        getline(cin, department);
    }

    void display() {
        Person::display();
        cout << "Faculty ID: " << facultyID << ", Department: " << department << endl;
    }
};

// Derived Class: TeachingAssistant
class TeachingAssistant : public Student, public Faculty {
    string role;
public:
    void getData() {
        Person::getData();

        cout << "Enter Student ID: ";
        cin >> studentID;
        cin.ignore();
        cout << "Enter Course: ";
        getline(cin, course);

        cout << "Enter Faculty ID: ";
        cin >> facultyID;
        cin.ignore();
        cout << "Enter Department: ";
        getline(cin, department);

        cout << "Enter Role (Grader/Lab Assistant/etc): ";
        getline(cin, role);
    }

    void display() {
        Person::display();
        cout << "Student ID: " << studentID << ", Course: " << course << endl;
        cout << "Faculty ID: " << facultyID << ", Department: " << department << endl;
        cout << "Role: " << role << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore();
    int m;
    cout << "Enter number of faculty: ";
    cin >> m;
    cin.ignore();
    int t;
    cout << "Enter number of teaching assistants: ";
    cin >> t;
    cin.ignore();

    Student s[n];
    for(int i = 0; i < n; ++i){
        cout << "\nEntering details for student " << (i+1) << ":\n";
        s[i].getData();
    }

    Faculty f[m];
    for(int i = 0; i < m; ++i){
        cout << "\nEntering details for faculty " << (i+1) << ":\n";
        f[i].getData();
    }

    TeachingAssistant ta[t];
    for(int i = 0; i < t; ++i){
        cout << "\nEntering details for teaching assistant " << (i+1) << ":\n";
        ta[i].getData();
    }

    for(int i = 0; i < n; ++i){
        cout << "\n--- Displaying Student " << (i+1) << " ---\n";
        s[i].display();
    }

    for(int i = 0; i < m; ++i){
        cout << "\n--- Displaying Faculty " << (i+1) << " ---\n";
        f[i].display();
    }

    for(int i = 0; i < t; ++i){
        cout << "\n--- Displaying Teaching Assistant " << (i+1) << " ---\n";
        ta[i].display();
    }
    return 0;
}
/*
Name : Chaniyara KhushKumar Hematbhai 
Id:24IT472
Hierarchical Inheritance
Q-2
*/

#include <iostream>
#include <string>
using namespace std;

// Base class
class University {
protected:
    string univercity_name;
    string location;
public:
    void inputUniversity() {
        cout << "Enter University Name: ";
        getline(cin, univercity_name);
        cout << "Enter University Location: ";
        getline(cin, location);
    }
    void displayUniversity() {
        cout << "University: " << univercity_name << ", Location: " << location << endl;
    }
};

// Derived class college
class College : public University {
    string collegeName;
public:
    void inputCollege() {
        cout << "Enter College Name: ";
        getline(cin, collegeName);
    }
    void displayCollege() {
        cout << "College: " << collegeName << endl;
    }
};

// Derived class department
class Department : public University {
    string deptName;
public:
    void inputDepartment() {
        cout << "Enter Department Name: ";
        getline(cin, deptName);
    }
    void displayDepartment() {
        cout << "Department: " << deptName << endl;
    }
    string getDeptName() { return deptName; }
};

// Derived class faculty
class Faculty : public University {
    string facultyName;
    string subject;
public:
    void inputFaculty() {
        cout << "Enter Faculty Name: ";
        getline(cin, facultyName);
        cout << "Enter Subject: ";
        getline(cin, subject);
    }
    void displayFaculty() {
        cout << "Faculty: " << facultyName << ", Subject: " << subject << endl;
    }
};

int main() {
    College col;
    Department dept;
    cout << "\n Enter College Details \n";
    col.University::inputUniversity();
    col.inputCollege();

    cout << "\n Enter Department Details \n";
    dept.inputDepartment();

    int n;
    cout << "\nEnter number of Faculties in this Department: ";
    cin >> n;
    cin.ignore(); 
    Faculty fac[n];
    for (int i = 0; i < n; i++) {
        cout << "\nEnter Faculty " << (i+1) << " details:\n";
        fac[i].inputFaculty();
    }

    cout << "\nDisplaying Details :\n";
    col.University::displayUniversity();
    col.displayCollege();
    dept.displayDepartment();

    for (int i = 0; i < n; i++) {
        cout << "\nFaculty " << (i+1) << ":\n";
        col.University::displayUniversity();
        fac[i].displayFaculty();
    }

    return 0;
}
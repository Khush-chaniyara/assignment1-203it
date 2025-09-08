/*
Name : Chaniyara KhushKumar Hematbhai 
Id:24IT472
Multiple Inheritance
Q-1
*/

#include <iostream>
#include <string>
using namespace std;

class PersonalInfo {
protected:
    string name;
    int age;
public:
    void inputPersonal() {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
    }
    void displayPersonal() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class JobInfo {
protected:
    int empID;
    string designation;
    float basicSalary;
    float allowance;
    float deduction;
public:
    void inputJob() {
        cout << "Enter employee ID: ";
        cin >> empID;
        cin.ignore(); 
        cout << "Enter designation: ";
        getline(cin, designation);
        cout << "Enter basic salary: ";
        cin >> basicSalary;
        cout << "Enter allowance: ";
        cin >> allowance;
        cout << "Enter deduction: ";
        cin >> deduction;
    }
    void displayJob() {
        cout << "Employee ID: " << empID << ", Designation: " << designation << endl;
        cout << "Basic Salary: " << basicSalary << ", Allowance: " << allowance << ", Deduction: " << deduction << endl;
    }
};

class Employee : public PersonalInfo, public JobInfo {
    float netSalary;
public:
    void inputEmployee() {
        inputPersonal();
        inputJob();
    }
    void calculateNetSalary() {
        netSalary = basicSalary + allowance - deduction;
    }
    void displayEmployee() {
        displayPersonal();
        displayJob();
        cout << "Net Salary: " << netSalary << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    Employee employees[n];

    for (int i = 0; i < n; ++i) {
        cout << "\n--- Enter details for Employee " << (i + 1) << " ---\n";
        employees[i].inputEmployee();
        employees[i].calculateNetSalary();
    }

    cout << "\n--- Employee Details ---\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nEmployee " << (i + 1) << ":\n";
        employees[i].displayEmployee();
    }


    return 0;
}
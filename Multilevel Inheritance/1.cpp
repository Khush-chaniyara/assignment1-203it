/*
Name : Chaniyara KhushKumar Hematbhai 
Id:24IT472
Multilevel Inheritance
Q-1
*/

#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
	string name;
	int rollNo;
public:
	void inputStudent() {
		cout << "Enter student name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter roll number: ";
		cin >> rollNo;
	}
	void displayStudent() {
		cout << "Name: " << name << ", Roll No: " << rollNo << endl;
	}
};

class Exam : public Student {
protected:
	int marks[5];
public:
	void inputMarks() {
		cout << "Enter marks for 5 subjects:\n";
		for(int i=0; i<5; ++i) {
			cout << "Subject " << (i+1) << ": ";
			cin >> marks[i];
		}
	}
	void displayMarks() {
		cout << "Marks: ";
		for(int i=0; i<5; ++i) {
			cout << marks[i] << " ";
		}
		cout << endl;
	}
};

class Result : public Exam {
	int total;
	float percentage;
	char grade;
public:
	void calculateResult() {
		total = 0;
		for(int i=0; i<5; ++i) total += marks[i];
		percentage = total / 5;
		if(percentage >= 90) grade = 'A';
		else if(percentage >= 75) grade = 'B';
		else if(percentage >= 60) grade = 'C';
		else if(percentage >= 40) grade = 'D';
		else grade = 'F';
	}
	void displayResult() {
		displayStudent();
		displayMarks();
		cout << "Total: " << total << endl;
		cout << "Percentage: " << percentage << "%" << endl;
		cout << "Grade: " << grade << endl;
	}
};

int main() {
	int n;
	cout << "Enter number of students: ";
	cin >> n;
	Result students[n];
	for(int i=0; i<n; ++i) {
		cout << "\n--- Enter details for student " << (i+1) << " ---\n";
		students[i].inputStudent();
		students[i].inputMarks();
		students[i].calculateResult();
	}
	cout << "\n--- Results ---\n";
	for(int i=0; i<n; ++i) {
		cout << "\nStudent " << (i+1) << ":\n";
		students[i].displayResult();
	}
	return 0;
}

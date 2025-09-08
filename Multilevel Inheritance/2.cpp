/*
Name : Chaniyara KhushKumar Hematbhai 
Id:24IT472
Multilevel Inheritance
Q-2
*/
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
	std::string name;
	int age;
	std::string gender;
public:
	void inputPerson() {
		cout << "Enter name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter age: ";
		cin >> age;
		cin.ignore();
		cout << "Enter gender: ";
		getline(cin, gender);
	}
	void displayPerson() {
		cout << "Name: " << name << ", Age: " << age << ", Gender: " << gender << endl;
	}
};

class Patient : public Person {
protected:
	std::string patientID;
	std::string disease;
public:
	void inputPatient() {
		inputPerson();
		cout << "Enter patient ID: ";
		getline(cin, patientID);
		cout << "Enter disease: ";
		getline(cin, disease);
	}

	void displayPatient() {
		displayPerson();
		cout << "Patient ID: " << patientID << ", Disease: " << disease << endl;
	}
};

class Inpatient : public Patient {
	int daysAdmitted;
	float roomChargePerDay = 1000;
	float medicineCharges;
	float doctorFees = 5000;
	float totalBill;
public:
	void inputInpatient() {
		inputPatient();
		cout << "room charge per day is Rs. 1000.\n";
		cout << "doctor fees is Rs. 5000.\n";
		cout << "Enter number of days admitted: ";
		cin >> daysAdmitted;
		cout << "Enter medicine charges: ";
		cin >> medicineCharges;
		cin.ignore();
	}
	void generateBill() {
		totalBill = daysAdmitted * roomChargePerDay + medicineCharges + doctorFees;
	}
	void displayInpatient() {
		displayPatient();
		cout << "Days Admitted: " << daysAdmitted << endl;
		cout << "Room Charge/Day: " << roomChargePerDay << endl;
		cout << "Medicine Charges: " << medicineCharges << endl;
		cout << "Doctor Fees: " << doctorFees << endl;
		cout << "Total Bill: " << totalBill << endl;
	}
};

class Outpatient : public Patient {
	float consultationFee = 800;
	float medicineCharges;
	float totalBill;
public:
	void inputOutpatient() {
		inputPatient();
		cout << "consultation fee is Rs. 800.\n";
		cout << "Enter medicine charges: ";
		cin >> medicineCharges;
		cin.ignore();
	}
    void generateBill() {
        totalBill = consultationFee + medicineCharges;
    }
	void displayOutpatient() {
		displayPatient();
		cout << "Consultation Fee: " << consultationFee << endl;
		cout << "Medicine Charges: " << medicineCharges << endl;
		cout << "Total Bill: " << totalBill << endl;
	}
};

int main() {
	int n, m;
	cout << "Enter number of inpatients: ";
	cin >> n;
	cout << "Enter number of outpatients: ";
	cin >> m;
	Inpatient inpatients[n];
	Outpatient outpatients[m];

	for(int i=0; i<n; ++i) {
		cout << "\n--- Enter details for Inpatient " << (i+1) << " ---\n";
		inpatients[i].inputInpatient();
		inpatients[i].generateBill();
	}
	for(int i=0; i<m; ++i) {
		cout << "\n--- Enter details for Outpatient " << (i+1) << " ---\n";
		outpatients[i].inputOutpatient();
		outpatients[i].generateBill();
	}

	cout << "\n--- Inpatient Bills ---\n";
	for(int i=0; i<n; ++i) {
		cout << "\nInpatient " << (i+1) << ":\n";
		inpatients[i].displayInpatient();
	}
	cout << "\n--- Outpatient Bills ---\n";
	for(int i=0; i<m; ++i) {
		cout << "\nOutpatient " << (i+1) << ":\n";
		outpatients[i].displayOutpatient();
	}
	return 0;
}

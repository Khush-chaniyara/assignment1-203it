/*
Name : Chaniyara KhushKumar Hematbhai 
Id:24IT472
Hybrid Inheritance
Q-1
*/

#include <iostream>
#include <string>
using namespace std;

class Account { // base class delaration
protected:
    int accountNumber;
    string accountHolderName;
    float balance;
public:
    void adddata(){
        cout<<"enter account number , name , balance";
        cin>>accountNumber>>accountHolderName>>balance;
    }

    void printdata(){
        cout<<"account number : "<<accountNumber<<endl;
        cout<<"account holder name : "<<accountHolderName<<endl;
        cout<<"balance : "<<balance<<endl;
    }

    virtual void deposit() {
        float amount;
        cout<<"enter amount to be deposited : ";
        cin>>amount;
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void showDetails() {
        cout << "\nAccount Details:\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name   : " << accountHolderName << endl;
        cout << "Balance       : " << balance << endl;
    }
};

// Derived Class: Savings
class Savings : virtual public Account { 
protected:
        float interestRate=8.0; //default value of interest rate
        float minimumBalance=1000.0; //default value of minimum balance
};

// Derived Class: Current
class Current : virtual public Account {
protected:
    float overdraftLimit=5000.0; //default value of overdraft limit
    float serviceCharge=100.0; //default value of service charge    
};

class Loan : public Savings, public Current {
    
    private:
    float loanAmount=0.0; //default value of loan amount
    float loanInterestRate=3.0; //default value of loan interest rate
    int loanDurationYears=5; //default value of loan duration in years
    
    public:
        void  add_loan_data(){
            cout<<"enter your loan details "<<endl;
            cout << "by default loan interest rate is 3 percentage and duration is 5 years"<<endl;
            cout << "if you want to change it then say yes otherwise no"<<endl;
            string ans;
            cin>>ans;
            if(ans=="yes" || ans=="YES" || ans=="Yes"){
                cout<<"enter loan interest rate";
                cin>>loanInterestRate;
                cout<<"enter loan duration in years";
                cin>>loanDurationYears;
                cout<<"enter loan amount";
                cin>>loanAmount;

            }
            else if(ans=="no" || ans=="NO" || ans=="No"){
                cout<<"keeping default values loan interest rate is 3 percentage and duration is 5 years"<<endl;
                cout<<"enter loan amount";
                cin>>loanAmount;
            }
    }

        void withdraw(){
        float amount;
        cout<<"enter amount to be withdrawn : ";
        cin>>amount;
        if (amount <= 0) { cout << "Invalid amount!\n"; return; }
        if (balance - amount >= minimumBalance) {
            balance -= amount;
            cout << "Withdrawn using Savings rules. New Balance: " << balance << endl;
            return;
        }
        if (balance + overdraftLimit >= amount) {
            balance -= amount; 
            cout << "Withdrawn using Current rules (overdraft). New Balance: " << balance << endl;
            return;
        }
        cout << "Withdrawal denied: would breach minimum balance and exceed overdraft limit.\n";
    }
        void checkLoanEligibility() {
        cout << "\n--- Loan Eligibility Check ---" << endl;
        if (balance >= minimumBalance && loanAmount <= (balance + overdraftLimit) * 5) {
            cout << "Eligible for Loan of amount: " << loanAmount << endl;
        } else {
            cout << "Not eligible for requested loan!" << endl;
        }
    }

        void calculateTotalInterest() {
        float totalInterest = (loanAmount * loanInterestRate * loanDurationYears) / 100.0;
        cout << "Total Interest Payable: " << totalInterest << endl;
    }

        void showLoanDetails() {
        cout << "\n--- Loan Details ---" << endl;
        cout << "Loan Amount         : " << loanAmount << endl;
        cout << "Loan Interest Rate  : " << loanInterestRate << "%" << endl;
        cout << "Loan Duration       : " << loanDurationYears << " years" << endl;
    }
};

int main() {
    Loan customer;
    customer.adddata();
    customer.printdata();

    int choice;
    do {
        cout << "\n--- Banking Menu ---\n";
        cout << "1. Show Account Details\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money (Loan policy)\n";
        cout << "4. Check Loan Eligibility\n";
        cout << "5. Show Loan Details\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:{
                customer.showDetails();
                break;
            }
            case 2: {
                customer.deposit();
                break;
            }
            case 3: {
                customer.withdraw();
                break;
            }
            case 4:{
                customer.add_loan_data();
                customer.checkLoanEligibility();
                break;
            }   
                case 5:{
                customer.showLoanDetails();
                customer.calculateTotalInterest();
                break;
            }
            case 0:{
                cout << "Exiting Banking System... Thank you!\n";
                break;
            }
                default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);
    return 0;
}
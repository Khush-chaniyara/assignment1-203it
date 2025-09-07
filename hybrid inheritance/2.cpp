/*
Name : Chaniyara KhushKumar Hematbhai 
Id:24IT472
hybrid Inheritance
Q-2
*/

#include<iostream>
#include<string>
using namespace std;

class Publication {
protected:
	string title;
	string author;
public:
	void input() {
		cout << "Enter title: ";
        cin>> title;
		cout << "Enter author: ";
        cin>> author;
	}
	void showDetails() {
		cout << "Title: " << title << endl 
            << "\nAuthor: " << author << endl;
	}
	string getTitle() {
         return title; 
    }
};

class Book : virtual public Publication {
protected:
	int pages;
public:
	void input() {
		Publication::input();
		cout << "Enter number of pages: ";
		cin >> pages;
		cin.ignore();
	}
	void showDetails() {
		Publication::showDetails();
		cout << "Pages: " << pages << endl;
	}
};

class Journal : public Publication {
protected:
	int issueNumber;
public:
	void input() {
		Publication::input();
		cout << "Enter issue number: ";
		cin >> issueNumber;
		cin.ignore();
	}
	void showDetails() {
		Publication::showDetails();
		cout << "Issue Number: " << issueNumber << endl;
	}
};

class EBook : virtual public Publication {
protected:
	string fileFormat;
public:
	void input() {
		Publication::input();
		cout << "Enter file format: ";
		getline(cin, fileFormat);
	}
	void showDetails() {
		Publication::showDetails();
		cout << "File Format: " << fileFormat << endl;
	}
};

class DigitalLibrary : public Book, public EBook {
public:
	void input() {
		Publication::input();
		cout << "Enter number of pages: ";
		cin >> pages;
		cout << "Enter file format: ";
        cin>> fileFormat;
	}
	void showDetails() {
		Publication::showDetails();
		cout << "Pages: " << pages << endl;
		cout << "File Format: " << fileFormat << endl;
	}
};

int main() {
    int n;
    cout << "Enter number of publications for each type: ";
    cin >> n;
	Book book[n];
	Journal journal[n];
	EBook ebook[n];
	DigitalLibrary dl[n];

for (int i = 0; i < n; ++i) {
    cout << "\nEnter Book details " << (i+1) << ":\n";
    book[i].input();
}

for (int i = 0; i < n; ++i) {
    cout << "\nEnter Journal details " << (i+1) << ":\n";
    journal[i].input();
}

for (int i = 0; i < n; ++i) {
    cout << "\nEnter EBook details " << (i+1) << ":\n";
    ebook[i].input();
}

for (int i = 0; i < n; ++i) {
    cout << "\nEnter Digital Library Book details " << (i+1) << ":\n";
    dl[i].input();
}   
string searchTitle;
cout << "\nEnter title to search and issue: ";
cin >> searchTitle; 

bool found = false;
for (int i = 0; i < n; ++i) {
    if (book[i].getTitle() == searchTitle) {
        cout << "\nBook found and issued:\n";
        book[i].showDetails();
        found = true;
        break;
    }
}
for (int i = 0; i < n; ++i) {
    if (journal[i].getTitle() == searchTitle) {
        cout << "\nJournal found and issued:\n";
        journal[i].showDetails();
        found = true;
        break;
    }
}
for (int i = 0; i < n; ++i) {
    if (ebook[i].getTitle() == searchTitle) {
        cout << "\nEBook found and issued:\n";
        ebook[i].showDetails();
        found = true;
        break;
    }
}
for (int i = 0; i < n; ++i) {
    if (dl[i].getTitle() == searchTitle) {
        cout << "\nDigital Library Book found and issued:\n";
        dl[i].showDetails();
        found = true;
        break;
    }
}
	if (!found) {
		cout << "\nPublication not found." << endl;
	}
	return 0;
}


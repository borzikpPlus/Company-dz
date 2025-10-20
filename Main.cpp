#include <iostream>
#include <string>
using namespace std;

class Company {
    string name;
    string owner;
    string phone;
    string address;
    string activity;

public:
    void input() {
        cout << "Enter company name: ";
        getline(cin, name);
        cout << "Enter owner: ";
        getline(cin, owner);
        cout << "Enter phone: ";
        getline(cin, phone);
        cout << "Enter address: ";
        getline(cin, address);
        cout << "Enter activity type: ";
        getline(cin, activity);
    }

    void show() const {
        cout << "Company: " << name << endl;
        cout << "Owner: " << owner << endl;
        cout << "Phone: " << phone << endl;
        cout << "Address: " << address << endl;
        cout << "Activity: " << activity << endl;
    }

    string getName() const { return name; }
    string getOwner() const { return owner; }
    string getPhone() const { return phone; }
    string getActivity() const { return activity; }
};

const int MAX_RECORDS = 100;

int main() {
    Company list[MAX_RECORDS];
    int count = 0;
    int choice;

    do {
        cout << "\nCOMPANY DIRECTORY=\n";
        cout << "1. Add record\n";
        cout << "2. Show all records\n";
        cout << "3. Search by company name\n";
        cout << "4. Search by owner\n";
        cout << "5. Search by phone\n";
        cout << "6. Search by activity\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            if (count >= MAX_RECORDS) {
                cout << "Directory is full.\n";
                continue;
            }
            list[count].input();
            count++;
        }
        else if (choice == 2) {
            if (count == 0) {
                cout << "No records yet.\n";
            } else {
                for (int i = 0; i < count; ++i)
                    list[i].show();
            }
        }
        else if (choice >= 3 && choice <= 6) {
            string key;
            if (choice == 3) cout << "Enter company name: ";
            if (choice == 4) cout << "Enter owner: ";
            if (choice == 5) cout << "Enter phone: ";
            if (choice == 6) cout << "Enter activity: ";
            getline(cin, key);

            bool found = false;
            for (int i = 0; i < count; ++i) {
                if ((choice == 3 && list[i].getName() == key) ||
                    (choice == 4 && list[i].getOwner() == key) ||
                    (choice == 5 && list[i].getPhone() == key) ||
                    (choice == 6 && list[i].getActivity() == key)) {
                    list[i].show();
                    found = true;
                }
            }
            if (!found)
                cout << "No matches found.\n";
        }
        else if (choice != 0) {
            cout << "Invalid option.\n";
        }

    } while (choice != 0);

    cout << "Goodbye!\n";
    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

// Function to add a new contact
void addContact() {
    Contact contact;
    cout << "Enter Name: ";
    cin >> contact.name;
    cout << "Enter Phone: ";
    cin >> contact.phone;
    cout << "Enter Email: ";
    cin >> contact.email;

    ofstream file("contacts.txt", ios::app);
    if (file.is_open()) {
        file << contact.name << " " << contact.phone << " " << contact.email << "\n";
        file.close();
        cout << "Contact added successfully!\n";
    } else {
        cout << "Unable to open file.\n";
    }
}

// Function to display all contacts
void displayContacts() {
    ifstream file("contacts.txt");
    if (file.is_open()) {
        string name, phone, email;
        cout << "\n--- Contact List ---\n";
        while (file >> name >> phone >> email) {
            cout << "Name: " << name << "\nPhone: " << phone << "\nEmail: " << email << "\n\n";
        }
        file.close();
    } else {
        cout << "Unable to open file.\n";
    }
}

// Function to search for a contact by name
void searchContact() {
    ifstream file("contacts.txt");
    string searchName;
    cout << "Enter name to search: ";
    cin >> searchName;

    bool found = false;
    string name, phone, email;
    while (file >> name >> phone >> email) {
        if (name == searchName) {
            cout << "\nContact Found:\n";
            cout << "Name: " << name << "\nPhone: " << phone << "\nEmail: " << email << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Contact not found.\n";
    }

    file.close();
}

// Function to delete a contact by name
void deleteContact() {
    ifstream file("contacts.txt");
    vector<Contact> contacts;
    string name, phone, email, deleteName;

    cout << "Enter name to delete: ";
    cin >> deleteName;

    while (file >> name >> phone >> email) {
        if (name != deleteName) {
            contacts.push_back({name, phone, email});
        }
    }

    file.close();

    ofstream outFile("contacts.txt");
    for (const auto& contact : contacts) {
        outFile << contact.name << " " << contact.phone << " " << contact.email << "\n";
    }

    outFile.close();

    cout << "Contact deleted (if it existed).\n";
}

// Main menu
int main() {
    int choice;
    do {
        cout << "\n--- Contact Management System ---\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}


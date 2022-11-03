// repo created
#include <bits/stdc++.h>
using namespace std;

class contactManager
{
    string firstName;
    string lastName;
    string phoneNumber;
    static int noOfContacts;

public:
    // constructor to increment
    contactManager()
    {
        noOfContacts++;
    }

    // GETTERS
    string getFirstName()
    {
        return firstName;
    }
    string getLastName()
    {
        return lastName;
    }
    string getphoneNumber()
    {
        return phoneNumber;
    }
    int getCount()
    {
        return noOfContacts;
    }

    // SETTERS
    void setFirstName(string firstName)
    {
        this->firstName = firstName;
    }
    void setLastName(string lastName)
    {
        this->lastName = lastName;
    }
    void setPhoneNumber(string phoneNumber)
    {
        this->phoneNumber = phoneNumber;
    }

    // CREATING NEW CONTACT
    void addNewContact(string firstName, string lastName, string phoneNumber)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->phoneNumber = phoneNumber;
    }
};

// initialising the count of contacts = 0
int contactManager::noOfContacts = 0;

// updating the first, last and phoneNumber vectors
void updateMyData(string entry, int index, vector<pair<string, int>> &query)
{
    query.push_back({entry, index});
    int len = query.size() - 1;
    while (len > 0 && query[len - 1].first > query[len].first)
    {
        swap(query[len], query[len - 1]);
        len--;
    }
}

int main()
{
    // Our Data Structures
    vector<contactManager> contacts;
    vector<pair<string, int>> first;
    vector<pair<string, int>> last;
    vector<pair<string, int>> phone;

    cout << "\nWelcome :)\n";
    bool interact = true;
    while (interact)
    {
        cout << "1: Enter new contact\n";
        cout << "2: Search Contact\n";
        cout << "0: Exit\n";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 0:
        {
            cout << "Thank You For Using ;)\n";
            interact = false;
            break;
        }

        case 1:
        {
            string firstName;
            string lastName;
            string phoneNumber;
            cout << "Enter the details :-\n";
            cout << "Enter the First Name: ";
            cin >> firstName;
            cout << "\nEnter the Last Name: ";
            cin >> lastName;
            cout << "\nEnter the Phone Number: ";
            cin >> phoneNumber;

            // creating object and adding in manager
            contactManager newContact;
            newContact.addNewContact(firstName, lastName, phoneNumber);
            contacts.push_back(newContact);

            // updating the first, last, phoneNo vectors
            updateMyData(firstName, newContact.getCount() - 1, first);
            updateMyData(lastName, newContact.getCount() - 1, last);
            updateMyData(phoneNumber, newContact.getCount() - 1, phone);

            cout << "Contact Added\n\n";
            break;
        }

        case 2:
        {
            cout << "\n1: Search by First Name ";
            cout << "\n2: Search by Last Name ";
            cout << "\n3: Search by Phone Number ";
            int choiceSearch;
            cin >> choiceSearch;

            cout << "1 : Prefix Search \n";
            cout << "2 : Complete Search \n";
            int input;
            cin >> input;

            string key;
            cout << "Enter Key to Search" << '\n';
            cin >> key;

            vector<int> ans;
            if (choiceSearch == 1)
            {
                // if (input == 1)
                //     ans = searchPrefix(key, first);
                // else if (input == 2)
                //     ans = searchComplete(key, first);
            }
            else if (choiceSearch == 2)
            {
                // if (input == 1)
                //     ans = searchPrefix(key, last);
                // else if (input == 2)
                //     ans = searchComplete(key, last);
            }
            else if (choiceSearch == 3)
            {
                // if (input == 1)
                //     ans = searchPrefix(key, phone);
                // else if (input == 2)
                //     ans = searchComplete(key, phone);
            }
            // print the searched part
            break;
        }

        default:
        {
            cout << "Please Enter a Valid Option \n";
            break;
        }
        }
    }
}

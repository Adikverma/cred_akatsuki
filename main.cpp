// repo created
#include <bits/stdc++.h>
using namespace std;

class contactManager
{
    string firstName;
    string lastName;
    string phoneNumber;

public:
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

    void addNewContact(string firstName; string lastName; string phoneNumber)
    {
    }
};

int main()
{

    bool interact = true;
    while (interact)
    {
        cout << "Welcome :)\n";
        cout << "To Enter a new contact press 1\n";
        cout << "To Search press 2\n";
        cout << "To Exit press 0\n";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 0:
        {
            cout << "\n Thank You For Using ;)\n";
            interact = false;
            break;
        }

        case 1:
        {
            string firstName;
            string lastName;
            string phoneNumber;
            cout << "Enter the details to add:-\n";
            cout << "Enter the First Name: ";
            cin >> firstName;
            cout << "Enter the Last Name: ";
            cin >> lastName;
            cout << "Enter the Phone Number: ";
            cin >> phoneNumber;
            addNewContact(firstName, lastName, phoneNumber);
            break;
        }

        case 2:
        {
        }
        }
    }
}
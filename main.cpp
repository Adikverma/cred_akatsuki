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

    //constructor to increment
    contactManager(){
        noOfContacts++;
    }

    //GETTERS
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
    int getCount(){
        return noOfContacts;
    }

    //SETTERS
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

    //CREATING NEW CONTACT
    void addNewContact(string firstName, string lastName, string phoneNumber)
    {
        setFirstName(firstName);
        setLastName(lastName);
        setPhoneNumber(phoneNumber);
    }

};

//initialising the count of contacts = 0
int contactManager::noOfContacts=0;

//updating the first, last and phoneNumber vectors
void updateMyData(string entry,int index,vector<pair<string,int>> &query){
    query.push_back({entry,index});
    int len=query.size()-1;
    while(len>0 && query[len-1].first>query[len].first){
        swap(query[len],query[len-1]);
        len--;
    }
}

//applying the Complete Search Functionality
vector<int> searchComplete(string key,vector<pair<string,int>> &query){
    int l=0;
	int r=query.size()-1;
	int end=-1;
	while(l<=r){
		int m=l+(r-l)/2;
		if(query[m].first<=key){
			l=m+1;
			end=m;
		}
		else if(query[m].first>key){
			r=m-1;
		}
	}
	l=0,r=query.size()-1;
	int begin=-1;
	while(l<=r){
		int m=l+(r-l)/2;
		if(query[m].first<key){
			l=m+1;
		}
		else if(query[m].first>=key){
			r=m-1;
			begin=m;
		}
	}
    vector<int> ans;
    ans.push_back(begin);
    ans.push_back(end);
    return ans;
}

//print the search results
void printTheSearch(vector<pair<string,int>> &query,vector<contactManager> &contacts,int begin,int end){
    cout<<"\nNo Of Results : "<<end-begin+1<<'\n';
    if(end==-1){
        cout<<"No Data Found";
    }else{
        for(int i=begin; i<=end; i++){
            cout<<contacts[query[i].second].getFirstName()<<" "<<contacts[query[i].second].getLastName()<<" : "<<contacts[query[i].second].getphoneNumber()<<"\n";
        }
    }
    cout<<"\n";
}

int main()
{   
    //Our Data Structures
    vector<contactManager> contacts;
    vector<pair<string,int>> first;
    vector<pair<string,int>> last;
    vector<pair<string,int>> phone;

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
                cout << "\nEnter the details :-\n";
                cout << "Enter the First Name: ";
                cin >> firstName;
                cout << "Enter the Last Name: ";
                cin >> lastName;
                cout << "Enter the Phone Number: ";
                cin >> phoneNumber;

                //creating object and adding in manager 
                contactManager newContact;
                newContact.addNewContact(firstName, lastName, phoneNumber);
                contacts.push_back(newContact);

                //updating the first, last, phoneNo vectors
                updateMyData(firstName, newContact.getCount()-1,first);
                updateMyData(lastName, newContact.getCount()-1,last);
                updateMyData(phoneNumber, newContact.getCount()-1,phone);
                
                cout<<"\nContact Added\n\n";
                break;
            }

            case 2:
            {
                cout<<"\n1: Search by First Name ";
                cout<<"\n2: Search by Last Name ";
                cout<<"\n3: Search by Phone Number ";
                int choiceSearch;
                cin>>choiceSearch;

                cout<<"1 : Prefix Search \n";
                cout<<"2 : Complete Search \n";
                int input;
                cin>>input;

                string key;
                cout<<"\nEnter Key to Search"<<'\n';
                cin>>key;

                vector<int> ans;
                if(choiceSearch==1){
                    // if(input==1) ans=searchPrefix(key,first);
                    if(input==2) ans=searchComplete(key,first);
                }else if(choiceSearch==2){
                    // if(input==1) ans=searchPrefix(key,last);
                    if(input==2) ans=searchComplete(key,last);
                }else if(choiceSearch==3){
                    // if(input==1) ans=searchPrefix(key,phone);
                    if(input==2) ans=searchComplete(key,phone);
                }
                printTheSearch(first,contacts,ans[0],ans[1]);
                break;
            }

            default : {
                cout<<"Please Enter a Valid Option \n";
                break;
            } 
        }
    }
}

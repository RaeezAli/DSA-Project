#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

class Contact{
	
	public:
		string fullName;
		string phoneNumber;
		string email;
		
	    Contact(string fullName = "" , string phoneNumber = "" , string email = ""){
	    	this->fullName = fullName;
	    	this->phoneNumber = phoneNumber;
	    	this->email = email;
		}
		
		void printInfo() {
			cout << "FULL NAME: " << fullName << endl;
			cout << "EMAIL: " << email << endl;
			cout << "CONTACT NUMBER: " << phoneNumber << endl;
		}		
			
};

class Node{
	public:
		Contact contact;
		Node* next;
		
		Node(Contact contact){
			this->contact = contact;
			this->next = NULL;
		}
		
};

class ContactManager{
	private:
		Node* head;
		
	public:	
		ContactManager(){
			head = NULL;
		}
		
		void addContact(string name , string email , string ph_no){
			Contact newContact(name , ph_no , email);
			Node* newNode = new Node(newContact);
			if(head == NULL){
				head = newNode;
			}
			else{
				Node* temp = head;
				while(temp->next != NULL){
					temp = temp->next;
				}
				temp->next = newNode;
			}
			addContatctInFile("user.txt" , newContact);
			cout << "Congratulations! contact added Successfully" << endl;
		}
		
		void addContatctInFile(const string& fileName , const Contact& newContact){
			ofstream outFile("user.txt" , ios::app);
			if(!outFile){
				cout << "Error File can't open'" << endl;
				return;
			}
			
				outFile<< newContact.fullName <<endl;
				outFile<< newContact.email <<endl;
				outFile<< newContact.phoneNumber <<endl;
			
			    outFile.close();
		}
		
		void searchContact(string name){
			ifstream inFile("user.txt");
			if(!inFile){
				cout << "Error file not open" << endl;
				return;
			}
			else{
				bool found = false;
				string fullName , email , phoneNumber;
				while(getline(inFile , fullName) && getline(inFile , email) && getline(inFile , phoneNumber)){
					if(fullName == name){
						cout << "Contact found" << endl;
						cout << "Full Name: " << fullName << endl;
						cout << "Email: " << email << endl;
						cout << "Phone Number: " << phoneNumber << endl;
					    found = true;
					    break;
					}
				}
				if(!found){
					cout << "Contact not found" << endl;
				}
			}
			inFile.close();
		}
		
		void deleteContact(string ph_no){
			ifstream inFile("user.txt");
			ofstream outFile("temp.txt" , ios::app);
			if(!inFile){
				cout << "File not open" << endl;
				return;
			}
			
			if(!outFile){
				cout << "File not open" << endl;
				return;
			}
			
			string fullName , email , phoneNumber;
			bool found = false;
			while(getline(inFile , fullName) && getline(inFile , email) && getline(inFile , phoneNumber)){
				if(phoneNumber != ph_no){
					outFile<<fullName<<endl;
					outFile<<email<<endl;
					outFile<<phoneNumber<<endl;
				}
				else{
					found = true;
				}
			}
			
			if(found){
				cout << "Successfully Contact Deleted!" << endl;
			}
			else{
				cout << "Data does not exist" << endl;
			}
			
			inFile.close();
 			outFile.close();
			remove("user.txt");
			rename("temp.txt" , "user.txt");
		
		}
		
		void sortContacts(){
			    ifstream inFile("user.txt");
			    
			    if(!inFile){
			    	cout << "Error File can't open" << endl;
			    	return;
				}
				
			    const int MAX_CONTACTS = 1000;
			    Contact contact[MAX_CONTACTS];
			    int count = 0;
			    while(getline(inFile , contact[count].fullName) && getline(inFile , contact[count].email) && getline(inFile , contact[count].phoneNumber)){
			    	count++;
				}
				
				inFile.close();
				
				for(int i = 0; i < count - 1; i++){
					for(int j = i + 1; j < count; j++){
						if(contact[i].fullName[0] > contact[j].fullName[0]){
							Contact temp = contact[i];
							contact[i] = contact[j];
							contact[j] = temp; 
						}
					}
				}
				
				ofstream outFile("temp.txt");
				
				if(!outFile){
					cout << "Error! File can't open" << endl;
					return;
				}
				
				for(int i = 0; i < count; i++){
					outFile<<contact[i].fullName<<endl;
					outFile<<contact[i].email<<endl;
					outFile<<contact[i].phoneNumber<<endl;
				}
				
				cout << "Sort Contact Successfully" << endl;
				
				outFile.close();
				
				remove("user.txt");
				rename("temp.txt" , "user.txt");
				
	}
    
    void displayAllContacts(){
    	ifstream inFile("user.txt");
    	if(!inFile){
    		cout << "File Can't Open" << endl;
    		return;
		}
		
		string fullName , email , phoneNumber;
		
		while(getline(inFile , fullName) && getline(inFile , email) && getline(inFile , phoneNumber)){
			cout << "FULL NAME: " << fullName << endl;
			cout << "EMAIL: " << email << endl;
			cout << "PHONENUMBER: " << phoneNumber << endl;
			cout << "-------------------------------------------" << endl;
		}

        inFile.close();
        
	}
						
};

int main(){
	
	ContactManager contactManager;
	int option;
	bool exit = false;
	
	system("cls");
	
	while(!exit){
    cout << "\n\n" << endl;
    cout << "*"<< endl;
    cout << "*" << endl;
    cout << "*                                                                                                                                                                     *" << endl;
    cout << "*                                                                                                                                                                     *" << endl;
    cout << "*                                                                                                                                                                     *" << endl;
    cout << "*         ####    ##    ##   # #### ####  #### #### #### #####    ###   ###   #####    ###   #  #####   ###     ####  ##   ##  #####  ##   ##  #####  #    #  #####   *" << endl;
    cout << "*        #      #    #  # #  #  #   #  # #      #   #  #   #      #  #  # #   #   #    #  #  #  #   #  #        #  #  # # # #  #      # # # #  #      # #  #    #     *" << endl;
    cout << "*        #      #    #  #  # #  #   #### #      #   ####   #      #   ##  #   #####    #   # #  #####  #    ##  ####  #  #  #  ###    #  #  #  ###    #  # #    #     *" << endl;
    cout << "*         ####    ##    #   ##  #   #  #  ####  #   #  #   #      #       #   #   #    #    ##  #   #    ###    #  #  #     #  #####  #     #  #####  #    #    #     *" << endl;
    cout << "*                                                                                                                                                                     *" << endl;
    cout << "*                                                                                                                                                                     *" << endl;
    cout << "*                                                                                                                                                                     *" << endl;
    cout << "*                                                                                                                                                                     *" << endl;
    cout << "*"<< endl;
    cout << "*\n\n"<< endl;
	
	cout<<"\t\t1.Add Contact."<<endl;
    cout<<"\t\t2.Display All Contact."<<endl;
    cout<<"\t\t3.Search Contact."<<endl;
    cout<<"\t\t4.Delete Contact."<<endl;
    cout<<"\t\t5.Exit."<<endl;
    cout<<"\t\tEnter Choice: ";
    cin >> option;
    
    if(option == 1){
    	cin.ignore();
	    
	    cout << "\t\t\n\nADD CONTACT\n\n"<< endl;
	    
	    startFullName:
    	string fullName;	    	
		cout << "Enter the full name: ";
	    getline(cin , fullName);
	    cout << endl;
	    if(fullName == ""){
	    	goto startFullName;
		}
	    
	    startEmail:	
	    string email;	
	    cout << "Enter the email: ";
	    getline(cin , email);
	    cout << endl;
	    if(email == ""){
	    	goto startEmail;
		}
		
		startPhoneNumber:
	    string phoneNumber;
		cout << "Enter the Phone Number: ";
	    getline(cin , phoneNumber);
	    cout << endl;
	    if(phoneNumber == ""){
	    	goto startEmail;
		}

	   	contactManager.addContact(fullName , email , phoneNumber);
	   	contactManager.sortContacts(); 

	}
	else if(option == 2){
		cin.ignore();
	    cout << "\t\t\n\nDISPLAY ALL CONTACTS\n\n"<< endl;
		
		contactManager.displayAllContacts();			
	}
	else if(option == 3){
		cin.ignore();
	    cout << "\t\t\n\nSEARCH CONTACT\n\n"<< endl;
	    
	    startSearchName:
	    string searchName;
	    cout << "Enter the Search Contact name: ";
	    getline(cin , searchName);
	    if(searchName == ""){
           goto startSearchName;
		}
	    contactManager.searchContact(searchName);
	    
	}
	else if(option == 4){
		cin.ignore();
		cout << "\t\t\n\nDELETE CONTACT\n\n"<< endl;
	    
	    startDeleteNumber:
	    string deletePhoneNumber;
	    cout << "Enter the Contact Number: ";
	    getline(cin ,  deletePhoneNumber);
	    if(deletePhoneNumber == ""){
           goto startDeleteNumber;
		}
		
		contactManager.deleteContact(deletePhoneNumber);
		
	}
	else if(option == 5){
	cout << "\t\t\n\nPlease Wait";
	for(int i = 0; i < 3; i++){
		cout << ".";
		Sleep(800);
	}
	    exit = true;
		cout << "\t\tExit" << endl;
		Sleep(800);
		system("cls");
    }
    else{
    	cout << "Invalid Option" << endl;
	}

   Sleep(3000);
  }
		
	return 0; }

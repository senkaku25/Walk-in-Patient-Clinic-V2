//WICPS.cpp
// Author: Melissa Lee 301300968
//CMPT 225 D100 Assignment 2
//memory leaks prevented with valgrind :)



#include <iostream>
#include <string>
#include <cctype>
#include "List.h"
#include "Patient.h"
using namespace std;


void join(List * patients) {
	string cCard = "";
	string name = "";
	string address = "";
	string phone = "";
	string email = "";
	//int position = -1;

	// Create a new member profile
	cout << "Please enter your carecard number: \n";
	getline(cin >> ws, cCard);
	while (cCard.length() != 10) {
		cout << "Invalid care card number. Please enter again: \n";
		getline(cin >> ws, cCard);
	}
	Patient newpatient(cCard); //creating new patient object for information to be filled out

	cout << "Please enter your name (first name then last name with a space in between): \n";
	getline(cin >> ws, name);
	newpatient.setName(name);

	cout << "Please enter your address: \n";
	getline(cin >> ws, address);
	newpatient.setAddress(address);

	cout << "Please enter your phone (all 10 digits with no spaces): \n";
	getline(cin >> ws, phone);
	newpatient.setPhone(phone);

	cout << "Please enter your email: \n";
	getline(cin >> ws, email);
	newpatient.setEmail(email);



	if (patients->search(newpatient) != NULL) cout << newpatient.getName() << " is already in the system using carecard: " << newpatient.getCareCard() << endl;

	if (patients->insert(newpatient)) cout << newpatient.getName() << " has successfully been entered into the system" << endl;
	else{
		cout << "Patient: " << newpatient.getName() << " was not able to enter the system." << endl;
	}
	return;
}

void leave(List * patients) {
	string cCard = "";
	cout << "Please, enter your carecard number " << endl;
	getline(cin >> ws, cCard);
	while (cCard.length() != 10) {
		cout << "Invalid care card number. Please enter again: \n";
		getline(cin >> ws, cCard);
	}
	Patient target(cCard); //creating a new patient object to act as a target to compare carecards in search function.


	if (patients->getElementCount() != 0) { //checking if list is empty
		if (patients->search(target)!=NULL){ //searches by carecard
			cout << "patient found" << endl;
			if (patients->remove(*patients->search(target)) ) {//searches patient then removes them
				cout << "Patient has left the system." << endl;
			}
		}
		else {
			cout << "Patient was not found. Carecard given is not in the system." << endl; //that carecard has not been entered yet
		}
	}
	else cout << "There are no patients in the system yet." << endl;
	return;
}

void modify(List * patients){
	char choice = ' ';
	string cCard = "";
	string name = "";
	string address = "";
	string phone = "";
	string email = "";
	bool notfinal = true;

	cout << "Walk in patient clinic information editing system" << endl;
	cout << "Please, enter your carecard number: " << endl;
	getline(cin >> ws, cCard);
	while (cCard.length() != 10) {
		cout << "Invalid care card number. Please enter again: \n";
		getline(cin >> ws, cCard);
	}
	Patient target(cCard); //creating a new patient object to act as a target to compare carecards in search function.

	while (notfinal){
		Patient* obj = patients->search(target);
		if (obj !=NULL){ //search by carecard #
		cout << "What function would you like to edit? (Enter the function number)" << endl;
		cout << "1. Name" << endl;
		cout << "2. Address" << endl;
		cout << "3. Phone" << endl;
		cout << "4. Email" << endl;
		cout << "5. Leave editing system" << endl;
		cin >> choice;
		cin.ignore(10, '\n');

	      switch(choice) {

	      case '1':
		cout << "Please Enter name: "<<  endl;
		getline(cin >> ws, name);
		obj->setName(name);
		break;

	      case '2':
		cout << "Please enter your address: ";
		getline(cin >> ws, address);
		obj->setAddress(address);
		break;

	      case '3':
		cout << "Please enter your phone: ";
		getline(cin >> ws, phone);
		obj->setPhone(phone);
		break;

	      case '4':
		cout << "Please enter your email: ";
		getline(cin >> ws, email);
		obj->setEmail(email);
		break;

	      case '5':
		cout << "Leaving editing system ~" << endl;
		notfinal = false;
		break;

	      default: cout << "Not sure what you mean! Please, try again!" << endl;
	   	 }

		cout << "Changes have been made... *PRINTING INFORMATION*" << endl; //printing new patient information
		obj->printPatient();

		}

		else {
			cout << "Carecard number " << cCard << " has not been entered yet." << endl;
			return;
		}
	}



}


int main() {

	List* patients = new List();
	bool finished = false;
	char choice;

  cout << "Welcome to the walk in patient system!" << endl;
	while (!finished) {
		cout << "What function would you like to use? (Enter the function number)" << endl;
		cout << "1. Enter a new patient." << endl;
		cout << "2. Remove a patient from the system." << endl;
		cout << "3. Search for a patient." << endl;
		cout << "4. Modify a patient's record." << endl;
		cout << "5. Print all patients by ascending order of care card numbers." << endl;
		cout << "6. Leave walk in patient system." << endl;

		cin >> choice;
		cin.ignore(10, '\n');

		switch (choice) {
		case '1': {
			join(patients);
			cout << "New list of patients (by ascending carecard order): " << endl;
			patients->printList();
			break;
			}
		case '2': {
			leave(patients);
			cout << "New list of patients (by ascending carecard order): " << endl;
			patients->printList();
			break;
		}
		case '3': {
			string cCard = "";
			cout << "Please enter your carecard number " << endl;
			getline(cin >> ws, cCard);
			while (cCard.length() != 10) {
				cout << "Invalid care card number. Please enter again: \n";
				getline(cin >> ws, cCard);
			}
			Patient target(cCard);

			Patient* obj = patients->search(target);
			if (obj!=NULL){
		 		cout << "Patient is in the system... *PRINTING INFORMATION*" << endl;
				obj->printPatient(); }
			else cout << "Patient has not been found. Carecard has not been entered yet." << endl;
		 	break; }
		case '4' : {
		 	modify(patients);
		 	break;}
		case '5' : {
			cout << "Printing list of all patients..." << endl;
			patients->printList();
			break; }
		case '6' : {
			cout << "Thank you for using the walk in patient clinic!" << endl;
			finished = true;
			break;}

		default: cout << "Not sure what you mean! Please, try again!" << endl;
		}
	}


	patients->removeAll();
	delete patients;
	return 0;


}

//Patient.cpp
// Author: Melissa Lee 301300968
//CMPT 225 D100 Assignment 2


#include <iostream>
#include <string.h>
#include <ctype.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Patient.h"
using namespace std;



// Default Constructor
// Description: Create a patient with a care card number of "0000000000".
// Postcondition: All data members set to "To be entered",
//                except the care card number which is set to "0000000000".
Patient::Patient() :
	name("To be entered"),
	address("To be entered"),
	phone("To be entered"),
	email("To be entered"),
	careCard("0000000000") {}

// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard) :
	name("To be entered"),
	address("To be entered"),
	phone("To be entered"),
	email("To be entered"),
	careCard("0000000000") {
	if (aCareCard.length() == 10) {
		careCard = aCareCard;
	}

}

// Getters and setters
// Description: Returns patient's name.
string Patient::getName() const {
	return name;
}

// Description: Returns patient's address.
string Patient::getAddress() const {
	return address;
}

// Description: Returns patient's phone number.
string Patient::getPhone() const {
	return phone;
}

// Description: Returns patient's email.
string Patient::getEmail() const {
	return email;
}

// Description: Returns patient's care card number.
//precond: careCard is a string of length 10
string Patient::getCareCard() const {
	return careCard;
}

// Description: Sets the patient's name.
//precond: name is a non empty string
//postcond: name is a non empty string that doesn't contain a special symbol in first letter
void Patient::setName(const string aName) {
	string proper(aName.length(), '0');
	for (unsigned int i = 0; i < aName.length(); i++) {
		if (isalpha(aName[i])) {
			if (i == 0) {
				proper[i] = toupper(aName[i]);
			}
			else {
				proper[i] = aName[i];
			}
		}
		else if (aName[i] == ' ') {
			proper[i] = ' ';
			if (isalpha(aName[i+1])) {
				proper[i+1] = toupper(aName[i+1]);
				i++;
			}
			else {
				return;
			}
		}
		else {
			return;
		}
	}
	name = proper;
}

// Description: Sets the patient's address.
//precond: address is set to either 'To be entered' or a string containing some numbers than a place
//postcond: address is set as 'To be entered' if user didn't enter the number of the address before the place or didn't put anything at all.
//          if correctly inputed, the address should be set to anAddress
void Patient::setAddress(const string anAddress) {
	if (isdigit(anAddress[0]) && anAddress.size() > 0) {
		address = anAddress;
	}
	else {
		address = "To be entered";
	}
}

// Description: Sets the patient's phone number.
//precond: phone is either set to 'To be entered' or as a string containing 10 numbers
//postcond: phone stays as it was before if aPhone was entered invalidly.
//         if aPhone is valid, then phone gets set to aPhone
void Patient::setPhone(const string aPhone) {
	bool isvalid = true;
	int i;//for loop incrementor
	if (aPhone.length() == 10) {
			for (i = 0; i < 10; i++) {//itterates through all 10 chars in string
			if (isdigit(aPhone[i]) == false) {
				isvalid = false; // if a char in the length 10 string isn't a digit, aPhone isnt valid
			//	cout << "Phone number entered is not 10 digit number." << endl;
				break;
			}
		}
	}
	else if(aPhone.length() != 10){
		//cout << "Phone number entered is not 10 digit number." << endl;
		isvalid = false;
	}
	if ((isvalid == true)) {
		std::string withdash(12, '0');
		int n = 0;
		for (i = 0; i < 12; i++) {
			if ((i == 3) || (i == 7)) {
				withdash[i] = '-';
			}
			else {
				withdash[i] = aPhone[n];
				n++;
			}
		}
		phone = withdash;
	}
	//if ((isvalid == false)) cout << "Not a valid phone number." << endl;
}

// Description: Sets the patient's email.
// precond: email is 'To be entered' or valid
// postcond: if anEmail is invalid (empty or has no @) it doesn't change. else, if it is valid, email is set to anEmail
// *NOTE* we are assuming that email ends in .com, .ca, etc. because emails end in endless different kinds of those
void Patient::setEmail(const string anEmail) {
	unsigned int i;
	bool hassymb = false; // bool to check if email has @ in it to make it valid email
	for (i=0; i<anEmail.length(); i++){
		if (anEmail[i] == '@') {
				hassymb = true;
		}
	}
	if ((anEmail.length() > 0) && (hassymb == true)) {
		email = anEmail; //if email is not invalid we set it to anEmail
	}
}

// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator==(const Patient & rhs) {
	if (careCard.compare(rhs.getCareCard())==0) return true;
	return false;

}

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card number of "rhs" Patient object.
bool Patient::operator>(const Patient & rhs) {
  int i;
	for(i=0;i<10;i++){
		if((int)careCard[i] > (int)rhs.getCareCard()[i]) return true; //goes through each number in the carecards and returns according to who has the larger number first.
		if((int)careCard[i] < (int)rhs.getCareCard()[i]) return false;
	}
	return false; //if it gets to here, strings are equal.

}

// Description: Prints the content of "this" patient.
// precond: name,address,phone,email is either 'To be entered' or correctly entered.
// postcond: all information is printed "carecard, Patient:  name, address, phone, email"
void Patient::printPatient() {
	cout << careCard << ", Patient: " << name << ", " << address << ", " << phone << ", " << email << endl;
}

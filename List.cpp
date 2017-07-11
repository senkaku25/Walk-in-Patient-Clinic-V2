//List.cpp
//
// Author: Melissa Lee 301300968
//CMPT 225 D100 Assignment 2
//memory leaks prevented with valgrind :)



#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "List.h"
#include "Patient.h"



using namespace std;


// Default constructor
List::List() : elementCount(0)
{


}

List::List(int maxcapacity) : elementCount(0)
{
int i;
for(i=0;i<10;i++){capacity[i] = maxcapacity;} //setting capacities to the capacity passed through as a parameter for overloaded constructor
}

List::~List() {

//cout << "Calling destructor" << endl;

if (ptr0!=NULL) delete [] ptr0; 
if (ptr1!=NULL) delete [] ptr1; 
if (ptr2!=NULL) delete [] ptr2; 
if (ptr3!=NULL) delete [] ptr3;
if (ptr4!=NULL) delete [] ptr4;
if (ptr5!=NULL) delete [] ptr5;
if (ptr6!=NULL) delete [] ptr6;
if (ptr7!=NULL) delete [] ptr7;
if (ptr8!=NULL) delete [] ptr8;
if (ptr9!=NULL) delete [] ptr9;
//if array was expanded in insert function, we delete what was heap allocated (array was allocated using new[])
//these pointers point to heap allocated expanded arrays
//if array wasn't expanded the pointers would still be NULL, thus theres no memory to 'clean up' because the original arrays will be automatically deleted


}


//returns element count
int  List::getElementCount() const {
	return elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted and elementCount has been incremented.
bool List::insert(const Patient& newElement) {// TO BE CONT.
	bool dup = false; //if there is a duplicate patient, we don't add it in
	int i;
	int pos;
	cout << "inserting Carecard: " << newElement.getCareCard() << endl;
	int numb = (newElement.getCareCard())[0]; //getting the first character in the carecard string
	if (numb == 48) numb = 0; //now we translate that character into a digit from 0-9
	if (numb == 49) numb = 1; //this is done using ascii table
	if (numb == 50) numb = 2;
	if (numb == 51) numb = 3;
	if (numb == 52) numb = 4;
	if (numb == 53) numb = 5;
	if (numb == 54) numb = 6;
	if (numb == 55) numb = 7;
	if (numb == 56) numb = 8;
	if (numb == 57) numb = 9;


	for (i = 0; i < count[numb]; i++) {//finding a duplicate
		if ((general[numb])[i] == newElement) dup = true;
	}

	if (dup == true) return false; //theres a duplicate so we cannot add another

	if (dup == false) {
		if (count[numb] + 1 > capacity[numb]) { // if the element count+1 (because we're inserting an element) is above the capacity, then
							// we're going to expand the array
			int newcap = capacity[numb]*2;

			Patient *newarray = new Patient[newcap];//creating a new array with the expanded capacity

			for (i = 0; i < count[numb]; i++) { newarray[i] = (general[numb])[i];} //copying the components from original array to the new array
			
			
			general[numb] = newarray;

			if (numb == 0){
				if (ptr0!=NULL) delete [] ptr0;
				ptr0 = newarray;
					}               
			if (numb == 1){
				if (ptr1!=NULL) delete [] ptr1;
				ptr1 = newarray;}
			if (numb == 2){
				if (ptr2!=NULL) delete [] ptr2;
				ptr2 = newarray;}
			if (numb == 3){
				if (ptr3!=NULL) delete [] ptr3;
				ptr3 = newarray;}
			if (numb == 4){
				if (ptr4!=NULL) delete [] ptr4;
				ptr4 = newarray;}
			if (numb == 5){
				if (ptr5!=NULL) delete [] ptr5;
				ptr5 = newarray;}
			if (numb == 6){
				if (ptr6!=NULL) delete [] ptr6;
				ptr6 = newarray;}
			if (numb == 7){
				if (ptr7!=NULL) delete [] ptr7;
				ptr7 = newarray;}
			if (numb == 8){
				if (ptr8!=NULL) delete [] ptr8;
				ptr8 = newarray;}
			if (numb == 9){
				if (ptr9!=NULL) delete [] ptr9;
				ptr9 = newarray;}
			//if the arrays have already been expanded and allocated, we delete the old list
			//then storing the heap allocated expanded array in the pointer to be deleted for when we're finished using it

			newarray = NULL; //were done using this array pointer

			capacity[numb] = capacity[numb] * 2; //setting new capacity
			//cout << "List has expanded..." << endl;
		}
		
		
		if (count[numb] == 0) { //if element is the first element in the array, we insert it at index 0
			(general[numb])[0] = newElement;
		}
		else { //inserting the new element
			i = 0;

			while ((i<count[numb]) && (newElement.getCareCard() > (general[numb])[i].getCareCard())) { i++; }

			pos = i;//position held for where the newelement should be placed


			for (i = count[numb]; i > pos; i--) { (general[numb])[i] = (general[numb])[i - 1]; } //shifting elements
			(general[numb])[pos] = newElement;//placing the new element
		}
	}
	count[numb]++; //increase element count for the specific array we inserted in
	elementCount++; //increase the general element count
	return true;
}


// Description: Remove an element.
// Precondition: no duplicated patients
// Postcondition: toBeRemoved is removed and elementCount has been decremented.
bool List::remove(const Patient& toBeRemoved) {
	int i;
	int numb = (toBeRemoved.getCareCard())[0];
	if (numb == 48) numb = 0; //translating first character in carecard to number using ascii
	if (numb == 49) numb = 1;
	if (numb == 50) numb = 2;
	if (numb == 51) numb = 3;
	if (numb == 52) numb = 4;
	if (numb == 53) numb = 5;
	if (numb == 54) numb = 6;
	if (numb == 55) numb = 7;
	if (numb == 56) numb = 8;
	if (numb == 57) numb = 9;
	bool isthere=false; //is the patient even on the list?

	for (i = 0; i < count[numb]; i++) {
		if (isthere) {
			(general[numb])[i - 1] = (general[numb])[i]; //shifting the elements back if we found the element
		}
		if ((general[numb])[i] == toBeRemoved) {//is the current patient the to be removed one?
			isthere = true;
		}
	}

	if (isthere == false) {
		cout << "Patient not in our system" << endl;
		return false;
	}
	else {
		count[numb]--; //decreasing element count for specific array of patients
		elementCount--; //decreasing overal element count
		return true;}


}


// Description: Remove all elements.
void List::removeAll() {
	int i;
	elementCount = 0; //unstable remove for every list.
	for (i = 0; i < 10; i++) count[i] = 0;

}

// Description: Search for target element via carecard
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target) {
	int i;
	int numb = (int)(target.getCareCard())[0];
	if (numb == 48) numb = 0;
	if (numb == 49) numb = 1;
	if (numb == 50) numb = 2;
	if (numb == 51) numb = 3;
	if (numb == 52) numb = 4;
	if (numb == 53) numb = 5;
	if (numb == 54) numb = 6;
	if (numb == 55) numb = 7;
	if (numb == 56) numb = 8;
	if (numb == 57) numb = 9;
	Patient *targetlist = general[numb];

	for (i = 0; i < count[numb]; i++) {
		if (targetlist[i].getCareCard() == target.getCareCard()) return &targetlist[i]; //returns the address of the element which is the target
	}
	return NULL;
}

// Description: Prints all elements stored in List.
void List::printList() {
	int i;
	int n;
	for (n = 0; n < 10; n++) {
		Patient *targetlist = general[n];
		for (i = 0; i < count[n]; i++) {
			targetlist[i].printPatient();
		}
	}
}

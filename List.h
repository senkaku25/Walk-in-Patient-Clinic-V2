/*
 * List.h
 * 
 * Class Description: A value-oriented List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - It is sorted by ascending sort order of its elements.
 *                   - Its data structure is expandable: when full, it expands to accommodate 
 *                     new insertion. This is done unbeknown to the client code.
 *
 * 
 * Author: AL
 * Modified by: Melissa Lee 301300968
 */

#pragma once
#include <string>
#include "Patient.h"

using namespace std;


class List  {

private:	
// We must complete this section


int elementCount; //general element count (# of patients held in entire system)


Patient elements0[2]; //holds patients with Carecard # starting at 0
Patient elements1[2]; //holds patients with cc starting at 1
Patient elements2[2]; //holds patients with cc starting at 2
Patient elements3[2]; //holds patients with cc starting at 3
Patient elements4[2]; //holds patients with cc starting at 4
Patient elements5[2]; //holds patients with cc starting at 5
Patient elements6[2]; //holds patients with cc starting at 6
Patient elements7[2]; //holds patients with cc starting at 7
Patient elements8[2]; //holds patients with cc starting at 8
Patient elements9[2]; //holds patients with cc starting at 9


Patient *general[10] = {elements0,elements1,elements2,elements3,elements4,elements5,elements6,elements7,elements8,elements9};
//^array that holds the pointers to the 10 arrays (holds particular pointer with respect to index #)

int count[10] = { 0,0,0,0,0,0,0,0,0,0 }; 
//^array that holds the element counts for each of the 10 arrays (holds particular element count with respect to index #)

int capacity[10] = { 2,2,2,2,2,2,2,2,2,2 };
//^array that holds the capacieties for each of the 10 arrays (holds particular capacity with respect to index #)



Patient *ptr0=NULL;  //pointer to expanded array for Carecard # starting at 0 (holds pointer if expanded, NULL if not)
Patient *ptr1=NULL;  //pointer to expanded array for cc starting at 1 (holds pointer if expanded, NULL if not)
Patient *ptr2=NULL;  //pointer to expanded array for cc starting at 2 (holds pointer if expanded, NULL if not)
Patient *ptr3=NULL;  //pointer to expanded array for cc starting at 3 (holds pointer if expanded, NULL if not)
Patient *ptr4=NULL;  //pointer to expanded array for cc starting at 4 (holds pointer if expanded, NULL if not)
Patient *ptr5=NULL;  //pointer to expanded array for cc starting at 5 (holds pointer if expanded, NULL if not)
Patient *ptr6=NULL;  //pointer to expanded array for cc starting at 6 (holds pointer if expanded, NULL if not)
Patient *ptr7=NULL;  //pointer to expanded array for cc starting at 7 (holds pointer if expanded, NULL if not)
Patient *ptr8=NULL;  //pointer to expanded array for cc starting at 8 (holds pointer if expanded, NULL if not)
Patient *ptr9=NULL;  //pointer to expanded array for cc starting at 9 (holds pointer if expanded, NULL if not)

//pointers to new heap allocated arrays (when array expanded in insert with new[])
//if array IS NOT expanded, pointer stays null and the default array destroyed at end of life
//if array IS expanded, pointer points to newly expanded array so we can delete it in destructor


   
public:

// We must add at least 1 constructor and a destructor
	
	// Default constructor
	List();

	List(int maxcapacity); //overloaded constructor-> you can chose a max capacity for the 10 arrays 
	
	~List(); //destructor

// *** Start of Public Interface ***
// Note: Public Interface must not be modified.

	// Description: Returns the total element count currently stored in List.
	int  getElementCount() const; //DONE

	// Description: Insert an element.
    //              When "this" List is full, its data structure is expanded to accommodate 
    //              a new element. This is done unbeknown to the client code.
	//              If the insertion is successful, true is returned otherwise, false is returned.
	// Precondition: newElement must not already be in data collection.  
	// Postcondition: newElement inserted and the appropriate elementCount has been incremented.	

	bool insert(const Patient& newElement);

	// Description: Remove an element. 
	//              If the removal is successful, true is returned otherwise, false is returned.
	// Postcondition: toBeRemoved is removed, the appropriate elementCount has been decremented.	
	bool remove( const Patient& toBeRemoved );
	
	// Description: Remove all elements.
	void removeAll();
   
	// Description: Search for target element and returns a pointer to it if found,
	//              otherwise, returns NULL.
	Patient* search(const Patient& target);
   
	// Description: Prints all n elements stored in List in sort order and does so in O(n).
	void printList();
	
// *** End of Public Interface ***

}; // end List
















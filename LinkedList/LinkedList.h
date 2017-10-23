/*

How to use this functions:
	Most of them need a pointer to the answer as an argument
	Their return value is just an error code

	error codes:
		0: the function failed
		1: the function succeded
*/

typedef struct linked_list LinkedList;
//type definition


//Constructor and Destructor

LinkedList* createLinkedList(int* initialList, int start, int end);
//Initializes the list

int destroyLinkedList(LinkedList* list);
//Destructor, frees memory, returns an error code


//Get functions

int getLinkedListSize(LinkedList* list, int* size);
//Gets the number of elements in the list, returns an error code

int getLinkedListElementAt(LinkedList* list, int index, int* element);
//Gets the element at the given index of the list, returns an error code

int getLinkedListArray(LinkedList* list, int* array);
//Gets the array of the list, returns an error code

int findLinkedListElement(LinkedList* list, int element, int* index);
//Gets the index of the element in the list, returns an error code


//Set functions

int setLinkedListElementAt(LinkedList* list, int index, int newElement);
//Sets the element at the given index of the list, returns an error code


//Add functions

int appendToLinkedList(LinkedList* list, int newElement);
//Adds a new element to the end of the list, returns an error code

int preppendToLinkedList(LinkedList* list, int newElement);
//Adds a new element to the begining of the list, returns an error code

int addToLinkedListAt(LinkedList* list, int index, int newElement);
//Adds a new element at the given index of the list, returns an error code


//Remove functions

int removeLinkedListElementAt(LinkedList* list, int index);
//Removes the element at the given index of the list, returns an error code

int removeLinkedListElement(LinkedList* list, int element);
//Removes the element in the list, returns an error code


//Print functions

int printLinkedList(LinkedList* list);
//Prints the list, returns an error code
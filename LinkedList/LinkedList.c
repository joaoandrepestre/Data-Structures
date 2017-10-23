#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

struct list_node{

	struct list_node* prevNode;
	int element;
	struct list_node* nextNode;
};

struct linked_list{

	int size;
	struct list_node* firstNode;
	struct list_node* lastNode;
};

//Constructor and Destructor

LinkedList* createLinkedList(int* initialList, int start, int end)
{
	//Initializes the list
	LinkedList* list = (LinkedList*) malloc(sizeof(struct linked_list));
	list->size = end - start;

	if(list->size == 0){//Starting an empty list
		
		list->firstNode = NULL;

		list->lastNode = NULL;

		return list;
	}

	if(list->size == 1){//Basic case for recursion of an odd sized list
		
		list->firstNode->prevNode = list->lastNode;
		list->firstNode->element = initialList[start];
		list->firstNode->nextNode = list->lastNode;

		list->lastNode = list->firstNode;

		return list;
	}

	if(list->size == 2){//Basic case for recursion of an even sized list

		list->firstNode->prevNode = list->lastNode;
		list->firstNode->element = initialList[start];
		list->firstNode->nextNode = list->lastNode;

		list->lastNode->prevNode = list->firstNode;
		list->lastNode->element = initialList[end-1];
		list->lastNode->nextNode = list->firstNode;

		return list;
	}

	LinkedList* tmp = createLinkedList(initialList, start+1, end-1);

	list->firstNode->prevNode = list->lastNode;
	list->firstNode->element = initialList[start];
	list->firstNode->nextNode = tmp->firstNode;

	list->lastNode->prevNode = tmp->lastNode;
	list->lastNode->element = initialList[end-1];
	list->lastNode->nextNode = list->firstNode;

	return list;
}

int destroyLinkedList(LinkedList* list)
{
	//Destructor, frees memory, returns an error code
	if(list == NULL)
		return 0;

	struct list_node* first = list->firstNode;
	struct list_node* tmp;
	int i = 0;

	while(i < list->size){
		tmp = first;
		first = first->nextNode;
		free(tmp);
		i++;
	}

	return 1;
}


//Get functions

int getLinkedListSize(LinkedList* list, int* size)
{
	//Gets the number of elements in the list, returns an error code
	if(list == NULL)
		return 0;

	*size = list->size;
	return 1;
}

int getLinkedListElementAt(LinkedList* list, int index, int* element)
{
	//Gets the element at the given index of the list, returns an error code
	if(list == NULL)
		return 0;

	if(index<0 || index>=list->size)
		return 0;

	int count = 0;
	struct list_node* tmp = list->firstNode;

	while(count < index){
		tmp = tmp->nextNode;
		count++;
	}

	*element = tmp->element;
	return 1;
}

int getLinkedListArray(LinkedList* list, int* array)
{
	//Gets the array of the list, returns an error code
	if(list == NULL)
		return 0;

	struct list_node* tmp = list->firstNode;

	int ret[list->size];
	int i;

	for(i=0;i<list->size;i++){
		ret[i] = tmp->element;
		tmp = tmp->nextNode;
	}

	array = ret;
	return 1;
}

int findLinkedListElement(LinkedList* list, int element, int* index)
{
	//Gets the index of the element in the list, returns an error code
}


//Set functions

int setLinkedListElementAt(LinkedList* list, int index, int newElement)
{
	//Sets the element at the given index of the list, returns an error code
	if(list == NULL)
		return 0;

	if(index<0 || index>=list->size)
		return 0;

	int count = 0;
	struct list_node* tmp = list->firstNode;

	while(count < index){
		list->firstNode = list->firstNode->nextNode;
		count++;
	}

	list->firstNode->element = newElement;
	list->firstNode = tmp;
	return 1;
}


//Add functions

int appendToLinkedList(LinkedList* list, int newElement)
{
	//Adds a new element to the end of the list, returns an error code
	if(list == NULL)
		return 0;

	struct list_node* newNode = (struct list_node*) malloc(sizeof(struct list_node));
	
	newNode->prevNode = list->lastNode;
	newNode->element = newElement;
	newNode->nextNode = list->firstNode;

	list->lastNode = newNode;
	list->size++;

	return 1;
}

int preppendToLinkedList(LinkedList* list, int newElement)
{
	//Adds a new element to the begining of the list, returns an error code
	if(list == NULL)
		return 0;
	
	struct list_node* newNode = (struct list_node*) malloc(sizeof(struct list_node));
	
	newNode->prevNode = list->lastNode;
	newNode->element = newElement;
	newNode->nextNode = list->firstNode;

	list->firstNode = newNode;
	list->size++;

	return 1;
}

int addToLinkedListAt(LinkedList* list, int index, int newElement)
{
	//Adds a new element at the given index of the list, returns an error code
}


//Remove functions

int removeLinkedListElementAt(LinkedList* list, int index)
{
	//Removes the element at the given index of the list, returns an error code
}

int removeLinkedListElement(LinkedList* list, int element)
{
	//Removes the element in the list, returns an error code
}


//Print functions

int printLinkedList(LinkedList* list)
{
	//Prints the list, returns an error code
}

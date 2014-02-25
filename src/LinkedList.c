#include <stdio.h>
#include "LinkedList.h"
#include <malloc.h>

LinkedList *createLinkedList(){

	//Initial State when there ARE NO ELEMENTS.
	LinkedList *list = malloc(sizeof(LinkedList));
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	
	//list->tail = (Element *)124124; //cast int to pointer
	return list;
}

Element *remove_Element(LinkedList *myList, Element *elementPos){

	printf("In src file.\nAddress of element: %p\n", elementPos); //Makesure this is the expected pass-in address
	printf("Address of element[0]: %p\n", (myList->head));
	printf("Address of element[1]: %p\n", (myList->head)->next);
	printf("Address of element[2]: %p\n\n", ((myList->head)->next)->next);
	
	/*head -> 0 .next -> 1 .next -> 2 .next -> NULL
	a) Delete element[0], head point to element[1] instead of 0, tail still point to the element[2]. 
	b) Delete element[1], head point to element[0], tail point to element[2]. element[0].next no longer point to element[1]
	  , it supposed point to element[2].
	c) Delete element[2], head point to element[0], tail point to element[1]. element[1].next no longer point to element[2]
	  , it supposed point NULL address now.
	d) Length minus 1. Clear element[0].data into 0.*/
	
	return elementPos; //Should return the address for element being removed.
	//return NULL; //To test whether the return value work or not
}
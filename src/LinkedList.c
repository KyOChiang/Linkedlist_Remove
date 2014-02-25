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
	
	return elementPos; //Should return the address for element being removed.
	//return NULL; //To test whether the return value work or not
}
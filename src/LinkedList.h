#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

typedef struct Element_t{
	struct Element_t *next;
	int data;
}Element;

typedef struct {
	Element *head;
	Element *tail;
	int length;
}LinkedList;

//Declare function prototype
LinkedList *createLinkedList();
Element *remove_Element(LinkedList *myList, Element *elementPos);

#endif
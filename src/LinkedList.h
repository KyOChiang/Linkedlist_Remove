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
Element *List_remove(LinkedList *myList, Element *elementPos);
//void *remove_ElementX(LinkedList *myList, void *int2Compare, int(*compare)(void*, void*));
int compareInt(void *v1, void *v2);
#endif

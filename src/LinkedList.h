#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

typedef struct Element_t{
	struct Element_t *next; // cant use Element because havent declare
	int data;
}Element;

typedef struct {
	Element *head;
	Element *tail;
	int length;
}LinkedList;



#endif

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
	
	int i = 0;
	Element arrayElem[myList->length], tempStore;
	for(i=0;i<myList->length;i++,myList->head=(myList->head)->next){
		arrayElem[i].next=myList->head;
		// printf("%p\n", arrayElem[i].next);
	}
	
	myList->head = arrayElem[0].next;
	i = 0;
	// printf("%p\n", myList->head);
	// printf("%p\n", myList->head->next);
	// printf("%p\n", myList->head->next->next);
	
	if(elementPos == arrayElem[0].next){
		myList->head = myList->head->next;
		myList->tail = arrayElem[(myList->length - 1)].next;
		myList->length = (myList->length) -1;
	}
	else if(elementPos == arrayElem[(myList->length - 1)].next){
		myList->head = arrayElem[(myList->length) - 2].next;
		myList->head->next = NULL;
		myList->head = arrayElem[0].next;
		myList->tail = arrayElem[(myList->length)-2].next;
		myList->length = (myList->length) -1;
	}
	else{
		tempStore.next = myList->head;
		while(elementPos!=arrayElem[i+1].next){
			i++;
			tempStore.next = (tempStore.next)->next;
		}
		(tempStore.next)->next = arrayElem[i+2].next;//myList->head->next->next;
		myList->tail = arrayElem[(myList->length - 1)].next;
		myList->length = (myList->length) -1;
	}
	
	// i+0->next = i+2
	// i+1->next = i+3
		
	return elementPos; //Should return the address for element being removed.
}
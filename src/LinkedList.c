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

/* This is a remove function to remove element (just replacing pointer that point to element being removed).
 * 
 * Input:
 * i			contain the start counting value.
 * arrayElem	array that contain addresses of element to compare.
 * tempStore	contain the origin myList->head value, for restore purpose
 * 
 * Output:
 * return		contain the address of element being removed, return NULL if no remove operation done
 */

Element *remove_Element(LinkedList *myList, Element *element2Remove){
	
	int i = 0;
	Element arrayElem[myList->length], tempStore;
	tempStore.next = myList->head;
	
	while(myList->head != NULL){
		arrayElem[i].next = myList->head;
		myList->head = myList->head->next;
		i++;
	}
	myList->head = tempStore.next;
	
	/* Determine the second last element.next pointer is point to last element or not.
	 * If not, length - 1 and return an NULL back since nothing removed.
	 * If yes, continue the next removed operation.
	 */
	if((arrayElem[(myList->length)-2].next)->next == NULL){
		myList->length = myList->length - 1;
		return NULL;
	}
	else{
		for(i=0;i<myList->length;i++,myList->head=(myList->head)->next){
			arrayElem[i].next=myList->head;
		}
	}
	
	myList->head = tempStore.next;
	i = 0;
	
	if(element2Remove == arrayElem[0].next){
		myList->head = myList->head->next;
		myList->tail = arrayElem[(myList->length - 1)].next;
		myList->length = (myList->length) -1;
	}
	else if(element2Remove == arrayElem[(myList->length - 1)].next){
		myList->head = arrayElem[(myList->length) - 2].next;
		myList->head->next = NULL;
		myList->head = arrayElem[0].next;
		myList->tail = arrayElem[(myList->length)-2].next;
		myList->length = (myList->length) -1;
	}
	else{
		tempStore.next = myList->head;
		while(element2Remove!=arrayElem[i+1].next){
			i++;
			tempStore.next = (tempStore.next)->next;
		}
		(tempStore.next)->next = arrayElem[i+2].next;
		myList->tail = arrayElem[(myList->length - 1)].next;
		myList->length = (myList->length) -1;
	}
	
	// i+0->next = i+2
	// i+1->next = i+3
		
	return element2Remove; //Should return the address for element being removed.
}
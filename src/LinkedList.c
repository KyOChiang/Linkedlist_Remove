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
 * headPtr/		To store the myList->head as behave like myList->head, it can be updated to next address
 * currentPtr	and do the comparison. This is because I do not want myList->head value change easily.
 * 
 * Output:
 * return		contain the address of element being removed, return NULL if no remove operation done
 */

 Element *List_remove(LinkedList *myList, Element *element2Remove){
	Element *headPtr, *currentPtr;
	currentPtr = myList->head;
	headPtr = myList->head;
	
	if((myList->head == NULL)&&(myList->tail == NULL)&&(myList->length == 0)){
		return NULL; //Since no remove operation done, return a null.
	}
	
	//To check whether that last element being removed is isolated or not.
	while(myList->head != element2Remove){
		myList->head = myList->head->next;
		while((myList->head == myList->tail) && (myList->tail != element2Remove)){
			myList->head = currentPtr;
			return NULL;
		}
	}

	myList->head = currentPtr;
	if(element2Remove == myList->head){
		myList->head = myList->head->next;
	}
	else if(element2Remove == myList->tail){
		while(currentPtr->next->next != NULL){
			currentPtr = currentPtr->next;
		}
		currentPtr->next = NULL;
		myList->tail = currentPtr;
	}
	else{
	/* To delete any element in the middle of list of any length.
	 * The replace pointer should be following
	 * If remove 2nd element, 1st element->next will point to 3rd element.
	 * If remove 3rd element, 2st element->next will point to 4rd element.
	 * If remove 4nd element, 3st element->next will point to 5rd element.
	 *
	 * ...... This show a order sequence.
	 * 					element[0].next = &element[2];
	 * 					element[1].next = &element[3];
	 * 					element[2].next = &element[4];
	 * ...... Until the n.
	 * 					element[n].next = &element[n+2];
	 *
	 * ...... At here. In condition that element[1] being removed.
	 * If currentPtr(contain address of element[0]) not equal to element2Remove.
	 * currentPtr will point to the next element address which is element[1].
	 *
	 * At the same time, if headPtr(address of element[0])->next is not
	 * equal to element[1], it will update and point to next element address.
	 * In this case, headPtr->next is equal to element2Remove(element[1]),
	 * so it do nothing here.
	 *
	 * ...... At the end
	 * We get 2 ptr which are currentPtr(address element[1]) and
	 * headPtr(address element[0]) and form the assignment as above.
	 * 					headPtr->next = currentPtr->next;
	 *					which equivalent to
	 *					element[0].next = &element[2];
	 */
		while(currentPtr != element2Remove){
			currentPtr = currentPtr->next; 
		}
		while(headPtr->next != element2Remove){
			headPtr = headPtr->next;
		}
		headPtr->next = currentPtr->next;
	}
	myList->length--;
	
	return element2Remove; //Should return the address for element being removed.
}

void *compare_Element(LinkedList *myList, void *int2Compare, int(*compare)(void*, void*)){
	int status, value;
	int length = myList->length;
	Element *ptr = myList->head;
	
	for(;ptr != NULL;){
		value = (ptr->data);
		status = compare(&value, int2Compare);
		//printf("%d  \n", status);
		if(status == 1){
			//printf("%p", ptr);
			List_remove(myList,ptr);
			//printf("1 here\n");
			return ptr;
		}
		else if(status == 0){
			ptr = ptr->next;
			length --;
			if(length == 0){
				//printf("2 here\n");
				return NULL;
			}
		}
	}
}

int compareInt(void *v1, void *v2){
	int *value1Int, *value2Int;
	
	value1Int = (int *)v1;
	value2Int = (int *)v2;

	return (*value1Int == *value2Int);
}
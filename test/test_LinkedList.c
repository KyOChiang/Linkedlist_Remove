#include "unity.h"
#include "LinkedList.h"

void setUp(){}
void tearDown(){}

LinkedList *myList;

Element *ptr2Element;

void test_Linked_List_should_create_properly(){
	myList = createLinkedList();
	
	TEST_ASSERT_NULL(myList->head);
	TEST_ASSERT_NULL(myList->tail);
	TEST_ASSERT_EQUAL(0, myList->length);
	TEST_ASSERT_NOT_NULL(myList);
}

void test_Struct_AND_ptr_Element_should_create_properly(){
	
	int length = 3, i = 0;
	Element element[length];
	
	//Initialize each array of Element
	for(i = 0; i < length; i++){
		if(i != length){
			element[i].next = &element[i+1]; 
			element[i].data = 123;
		}
		if(i == (length-1)){
			element[i].next = NULL; 
			element[i].data = 456;
		}
	}
	
	//To let head pointer store address of 1st element, tail pointer store the last element, length store the no of element create.
	myList->head = &element[length-length];
	myList->length = length;
	myList->tail = &element[length-1];
	
	// Test the address for each element is store properly into expected pointers.
	for(i = 0; i < length; i++){
		printf("Address element[%d]: %p data:%d\n", i, &element[i],element[i].data);
	}
	
	TEST_ASSERT_NOT_NULL(myList->head);
	TEST_ASSERT_NOT_NULL(myList->tail);
	TEST_ASSERT_NOT_EQUAL(0,element[0].data);
	
	printf("Head pointer: %p\n",myList->head);
	printf("Tail pointer: %p\n",myList->tail);
}

void test_either_element1_element2_or_element3_should_remove_properly(){
	ptr2Element = remove_Element(myList, ptr2Element);
	TEST_ASSERT_NULL(ptr2Element);
}
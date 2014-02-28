#include "unity.h"
#include "LinkedList.h"

void setUp(){}
void tearDown(){}

LinkedList *myList;

Element *ptr2Element;

void test_createLinkedList_should_create_and_init_LinkedList_head_tail_and_length(){
	myList = createLinkedList();
	
	TEST_ASSERT_NOT_NULL(myList);
	TEST_ASSERT_NULL(myList->head);
	TEST_ASSERT_NULL(myList->tail);
	TEST_ASSERT_EQUAL(0, myList->length);
}

void test_removeElement_0_should_replace_the_head_pointer_with_element0_next_pointer(){
	
	// int length = 3, i = 0;
	myList = createLinkedList();
	Element element[3] = {{.next = &element[1],.data = 123},
						  {.next = &element[2],.data = 456},
						  {.next = NULL,.data = 789}};
	
	// Test the address for each element is store properly into expected pointers.
	// for(i = 0; i < length; i++){
		// printf("Address element[%d]: %p data:%d\n", i, &element[i],element[i].data);
	// }
	
	//To let head pointer store address of 1st element, tail pointer store the last element, 
	//length store the no of element create.
	myList->head = &element[0];
	myList->tail = &element[2];
	myList->length = 3;
	//printf("%p\n",&element[0]);
	//printf("%p\n",&element[1]);
	//printf("%p\n",&element[2]);
	
	ptr2Element = remove_Element(myList, &element[0]);
	
	//printf("%d\n",element[0].data);
	TEST_ASSERT_EQUAL(2,myList->length);
	TEST_ASSERT_EQUAL_PTR(&element[1],myList->head);
	TEST_ASSERT_EQUAL_PTR(&element[2],myList->tail);
	TEST_ASSERT_EQUAL(123,ptr2Element->data);
	TEST_ASSERT_EQUAL_PTR(&element[0],ptr2Element);
}

void test_removeElement_1_should_replace_the_element0_pointer_with_element1_next_pointer(){
	
	// int length = 3, i = 0;
	myList = createLinkedList();
	Element element[3] = {{.next = &element[1],.data = 123},
						  {.next = &element[2],.data = 456},
						  {.next = NULL,.data = 789}};
	
	//To let head pointer store address of 1st element, tail pointer store the last element, 
	//length store the no of element create.
	myList->head = &element[0];
	myList->tail = &element[2];
	myList->length = 3;
	
	ptr2Element = remove_Element(myList, &element[1]);
	
	TEST_ASSERT_EQUAL_PTR(&element[0],myList->head);
	TEST_ASSERT_EQUAL_PTR(&element[2],myList->tail);
	TEST_ASSERT_EQUAL_PTR(&element[2],element[0].next);
	TEST_ASSERT_EQUAL(2,myList->length);
	TEST_ASSERT_EQUAL(456,ptr2Element->data);
	TEST_ASSERT_EQUAL_PTR(&element[1],ptr2Element);
}

void test_removeElement_2_should_replace_the_element1_pointer_with_element2_next_pointer(){
	
	// int length = 3, i = 0;
	myList = createLinkedList();
	Element element[3] = {{.next = &element[1],.data = 123},
						  {.next = &element[2],.data = 456},
						  {.next = NULL,.data = 789}};
	
	//To let head pointer store address of 1st element, tail pointer store the last element, 
	//length store the no of element create.
	myList->head = &element[0];
	myList->tail = &element[2];
	myList->length = 3;
	
	ptr2Element = remove_Element(myList, &element[2]);
	TEST_ASSERT_EQUAL_PTR(&element[0],myList->head);
	TEST_ASSERT_EQUAL_PTR(&element[1],myList->tail);
	TEST_ASSERT_EQUAL_PTR(NULL,element[1].next);
	TEST_ASSERT_EQUAL(2,myList->length);
	TEST_ASSERT_EQUAL(789,ptr2Element->data);
	TEST_ASSERT_EQUAL_PTR(&element[2],ptr2Element);
}

void test_removeElement_2_within_4_elements_should_replace_the_element1_pointer_with_element2_next_pointer(){
	
	// int length = 3, i = 0;
	myList = createLinkedList();
	Element element[4] = {{.next = &element[1],.data = 123},
						  {.next = &element[2],.data = 456},
						  {.next = &element[3],.data = 456},
						  {.next = NULL,.data = 789}};
	
	//To let head pointer store address of 1st element, tail pointer store the last element, 
	//length store the no of element create.
	myList->head = &element[0];
	myList->tail = &element[3];
	myList->length = 4;
	
	ptr2Element = remove_Element(myList, &element[2]);
	TEST_ASSERT_EQUAL_PTR(&element[0],myList->head);
	TEST_ASSERT_EQUAL_PTR(&element[3],myList->tail);
	TEST_ASSERT_EQUAL_PTR(&element[3],element[1].next);
	TEST_ASSERT_EQUAL_PTR(NULL,element[3].next);
	TEST_ASSERT_EQUAL(3,myList->length);
	TEST_ASSERT_EQUAL(456,ptr2Element->data);
	TEST_ASSERT_EQUAL_PTR(&element[2],ptr2Element);
}

void test_removeElement_1_within_4_elements_should_replace_the_element0_pointer_with_element1_next_pointer(){
	
	// int length = 3, i = 0;
	myList = createLinkedList();
	Element element[4] = {{.next = &element[1],.data = 123},
						  {.next = &element[2],.data = 145},
						  {.next = &element[3],.data = 456},
						  {.next = NULL,.data = 789}};
	
	//To let head pointer store address of 1st element, tail pointer store the last element, 
	//length store the no of element create.
	myList->head = &element[0];
	myList->tail = &element[3];
	myList->length = 4;
	
	ptr2Element = remove_Element(myList, &element[1]);
	TEST_ASSERT_EQUAL_PTR(&element[0],myList->head);
	TEST_ASSERT_EQUAL_PTR(&element[3],myList->tail);
	TEST_ASSERT_EQUAL_PTR(&element[2],element[0].next);
	TEST_ASSERT_EQUAL_PTR(NULL,element[3].next);
	TEST_ASSERT_EQUAL(3,myList->length);
	TEST_ASSERT_EQUAL(145,ptr2Element->data);
	TEST_ASSERT_EQUAL_PTR(&element[1],ptr2Element);
}

void test_removeElement_3_within_4_elements_should_replace_the_element2_pointer_with_element3_next_pointer(){
	
	// int length = 3, i = 0;
	myList = createLinkedList();
	Element element[4] = {{.next = &element[1],.data = 123},
						  {.next = &element[2],.data = 145},
						  {.next = &element[3],.data = 456},
						  {.next = NULL,.data = 789}};
	
	//To let head pointer store address of 1st element, tail pointer store the last element, 
	//length store the no of element create.
	myList->head = &element[0];
	myList->tail = &element[3];
	myList->length = 4;
	
	ptr2Element = remove_Element(myList, &element[3]);
	TEST_ASSERT_EQUAL_PTR(&element[0],myList->head);
	TEST_ASSERT_EQUAL_PTR(&element[2],myList->tail);
	TEST_ASSERT_EQUAL_PTR(NULL,element[2].next);
	TEST_ASSERT_EQUAL(3,myList->length);
	TEST_ASSERT_EQUAL(789,ptr2Element->data);
	TEST_ASSERT_EQUAL_PTR(&element[3],ptr2Element);
}

void test_removeElement_0_within_4_elements_should_replace_the_head_pointer_with_element0_next_pointer(){
	
	// int length = 3, i = 0;
	myList = createLinkedList();
	Element element[4] = {{.next = &element[1],.data = 123},
						  {.next = &element[2],.data = 145},
						  {.next = &element[3],.data = 456},
						  {.next = NULL,.data = 789}};
	
	//To let head pointer store address of 1st element, tail pointer store the last element, 
	//length store the no of element create.
	myList->head = &element[0];
	myList->tail = &element[3];
	myList->length = 4;
	
	ptr2Element = remove_Element(myList, &element[0]);
	TEST_ASSERT_EQUAL_PTR(&element[1],myList->head);
	TEST_ASSERT_EQUAL_PTR(&element[3],myList->tail);
	TEST_ASSERT_EQUAL_PTR(NULL,element[3].next);
	TEST_ASSERT_EQUAL(3,myList->length);
	TEST_ASSERT_EQUAL(123,ptr2Element->data);
	TEST_ASSERT_EQUAL_PTR(&element[0],ptr2Element);
}

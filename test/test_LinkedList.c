#include "unity.h"
#include "LinkedList.h"

void setUp(){}
void tearDown(){}

LinkedList *myList;

void test_Linked_List_should_create_properly(){
	myList = createLinkedList();
	
	TEST_ASSERT_NULL(myList->head);
	TEST_ASSERT_NULL(myList->tail);
	TEST_ASSERT_EQUAL(0, myList->length);
	TEST_ASSERT_NOT_NULL(myList);
}
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

void test_removeElement_with_no_element_and_no_operation_complete(){
	
	myList = createLinkedList();

	myList->head = NULL;
	myList->tail = NULL;
	myList->length = 0;
	
	ptr2Element = List_remove(myList, NULL);
	
	TEST_ASSERT_NULL(ptr2Element);
	
}

void test_removeElement_0_should_replace_the_head_pointer_with_element0_next_pointer(){
	
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
	
	ptr2Element = List_remove(myList, &element[0]);
	
	TEST_ASSERT_EQUAL(2,myList->length);
	TEST_ASSERT_EQUAL_PTR(&element[1],myList->head);
	TEST_ASSERT_EQUAL_PTR(&element[2],myList->tail);
	TEST_ASSERT_EQUAL(123,ptr2Element->data);
	TEST_ASSERT_EQUAL_PTR(&element[0],ptr2Element);
}

void test_removeElement_1_should_replace_the_element0_next_pointer_with_element1_next_pointer(){
	
	myList = createLinkedList();
	Element element[3] = {{.next = &element[1],.data = 123},
						  {.next = &element[2],.data = 456},
						  {.next = NULL,.data = 789}};
	
	myList->head = &element[0];
	myList->tail = &element[2];
	myList->length = 3;
	
	ptr2Element = List_remove(myList, &element[1]);
	
	TEST_ASSERT_EQUAL_PTR(&element[0],myList->head);
	TEST_ASSERT_EQUAL_PTR(&element[2],myList->tail);
	TEST_ASSERT_EQUAL_PTR(&element[2],element[0].next);
	TEST_ASSERT_EQUAL(2,myList->length);
	TEST_ASSERT_EQUAL(456,ptr2Element->data);
	TEST_ASSERT_EQUAL_PTR(&element[1],ptr2Element);
}

void test_removeElement_2_within_4elements_should_\
replace_the_element1_next_pointer_with_element2_next_pointer(){
	
	myList = createLinkedList();
	Element element[4] = {{.next = &element[1],.data = 123},
						  {.next = &element[2],.data = 456},
						  {.next = &element[3],.data = 456},
						  {.next = NULL,.data = 789}};
	
	myList->head = &element[0];
	myList->tail = &element[3];
	myList->length = 4;

	ptr2Element = List_remove(myList, &element[2]);

	TEST_ASSERT_EQUAL_PTR(&element[0],myList->head);
	TEST_ASSERT_EQUAL_PTR(&element[3],myList->tail);
	TEST_ASSERT_EQUAL_PTR(&element[3],element[1].next);
	TEST_ASSERT_EQUAL(3,myList->length);
	TEST_ASSERT_EQUAL(456,ptr2Element->data);
	TEST_ASSERT_EQUAL_PTR(&element[2],ptr2Element);
}

void test_removeElement_2_should_replace_the_element1_nextPtr_to_NULL(){
	
	myList = createLinkedList();
	Element element[3] = {{.next = &element[1],.data = 123},
						  {.next = &element[2],.data = 456},
						  {.next = NULL,.data = 789}};
	
	myList->head = &element[0];
	myList->tail = &element[2];
	myList->length = 3;
	
	ptr2Element = List_remove(myList, &element[2]);
	TEST_ASSERT_EQUAL_PTR(&element[0],myList->head);
	TEST_ASSERT_EQUAL_PTR(&element[1],myList->tail);
	TEST_ASSERT_EQUAL_PTR(NULL,element[1].next);
	TEST_ASSERT_EQUAL(2,myList->length);
	TEST_ASSERT_EQUAL(789,ptr2Element->data);
	TEST_ASSERT_EQUAL_PTR(&element[2],ptr2Element);
}

void test_removeElement_1_within_4_elements_should_replace_the_element0_next_pointer_with_element1_next_pointer(){
	
	myList = createLinkedList();
	Element element[4] = {{.next = &element[1],.data = 123},
						  {.next = &element[2],.data = 145},
						  {.next = &element[3],.data = 456},
						  {.next = NULL,.data = 789}};
	
	myList->head = &element[0];
	myList->tail = &element[3];
	myList->length = 4;
	
	ptr2Element = List_remove(myList, &element[1]);
	TEST_ASSERT_EQUAL_PTR(&element[0],myList->head);
	TEST_ASSERT_EQUAL_PTR(&element[3],myList->tail);
	TEST_ASSERT_EQUAL_PTR(&element[2],element[0].next);
	TEST_ASSERT_EQUAL_PTR(NULL,element[3].next);
	TEST_ASSERT_EQUAL(3,myList->length);
	TEST_ASSERT_EQUAL(145,ptr2Element->data);
	TEST_ASSERT_EQUAL_PTR(&element[1],ptr2Element);
}

void test_removeElement_3_within_4_elements_should_replace_the_element2_pointer_with_element3_next_pointer(){
	
	myList = createLinkedList();
	Element element[4] = {{.next = &element[1],.data = 123},
						  {.next = &element[2],.data = 145},
						  {.next = &element[3],.data = 456},
						  {.next = NULL,.data = 789}};
	
	myList->head = &element[0];
	myList->tail = &element[3];
	myList->length = 4;
	
	ptr2Element = List_remove(myList, &element[3]);
	TEST_ASSERT_EQUAL_PTR(&element[0],myList->head);
	TEST_ASSERT_EQUAL_PTR(&element[2],myList->tail);
	TEST_ASSERT_EQUAL_PTR(NULL,element[2].next);
	TEST_ASSERT_EQUAL(3,myList->length);
	TEST_ASSERT_EQUAL(789,ptr2Element->data);
	TEST_ASSERT_EQUAL_PTR(&element[3],ptr2Element);
}

void test_removeElement_0_within_4_elements_should_replace_the_head_pointer_with_element0_next_pointer(){
	
	myList = createLinkedList();
	Element element[4] = {{.next = &element[1],.data = 123},
						  {.next = &element[2],.data = 145},
						  {.next = &element[3],.data = 456},
						  {.next = NULL,.data = 789}};
	
	myList->head = &element[0];
	myList->tail = &element[3];
	myList->length = 4;
	
	ptr2Element = List_remove(myList, &element[0]);
	TEST_ASSERT_EQUAL_PTR(&element[1],myList->head);
	TEST_ASSERT_EQUAL_PTR(&element[3],myList->tail);
	TEST_ASSERT_EQUAL_PTR(NULL,element[3].next);
	TEST_ASSERT_EQUAL(3,myList->length);
	TEST_ASSERT_EQUAL(123,ptr2Element->data);
	TEST_ASSERT_EQUAL_PTR(&element[0],ptr2Element);
}


   /**
    * Given:
    *
    *  tail-------------------+
    *                         V
    *         +------+    +------+        +------+
    *  head-->|elem0 |--->|elem1 |--+     |elem2 |--+
    *         +------+    +------+  |     +------+  |
    *                              _v_             _v_
    *
    * Attempt to remove element 2, but it is not in the linked-list, so expect
    * nothing is done on the list and NULL is returned. 
    */

void test_removeElement_2_should_do_nothing_and_return_a_NULL(){
	
	myList = createLinkedList();
	Element element[3] = {{.next = &element[1],.data = 123},
						  {.next = NULL,.data = 456},
						  {.next = NULL,.data = 789}};
	
	myList->head = &element[0];
	myList->tail = &element[1];
	myList->length = 2;
	
	ptr2Element = List_remove(myList, &element[2]);
	
	TEST_ASSERT_EQUAL(2,myList->length);
	TEST_ASSERT_EQUAL_PTR(&element[0],myList->head);
	TEST_ASSERT_EQUAL_PTR(&element[1],myList->tail);
	TEST_ASSERT_EQUAL(123,element[0].data);
	TEST_ASSERT_EQUAL(456,element[1].data);
	TEST_ASSERT_EQUAL(789,element[2].data);
	TEST_ASSERT_NULL(ptr2Element);
	
}

void test_removeElement_3_should_do_nothing_and_return_a_NULL(){
	
	myList = createLinkedList();
	Element element[4] = {{.next = &element[1],.data = 123},
						  {.next = &element[2],.data = 145},
						  {.next = NULL,.data = 456},
						  {.next = NULL,.data = 789}};
	
	myList->head = &element[0];
	myList->tail = &element[2];
	myList->length = 3;
	
	ptr2Element = List_remove(myList, &element[3]);
	TEST_ASSERT_EQUAL_PTR(&element[0],myList->head);
	TEST_ASSERT_EQUAL_PTR(&element[2],myList->tail);
	TEST_ASSERT_EQUAL_PTR(NULL,element[2].next);
	TEST_ASSERT_EQUAL(3,myList->length);
	TEST_ASSERT_EQUAL_PTR(NULL,ptr2Element);
}

void test_compareInt_should_return_true_if_both_are_equal(){
	int v1 = 2, v2 = 123, v3 = 2;
	int checkStatus;
	
	checkStatus = compareInt(&v1, &v2);
	TEST_ASSERT_FALSE(checkStatus);
	checkStatus = compareInt(&v1, &v3);
	TEST_ASSERT_TRUE(checkStatus);
}

/*void test_compare_to_compare_integer_val_with_integer_data_inside_one_element(){
	int v1 = 9, v2 = 3, v3 = 123;
	int checkStatus;
	myList = createLinkedList();
	Element element = {.next = NULL,.data = 123};
	
	myList->head = &element;
	myList->tail = &element;
	myList->length = 1;
	
	/* Check if 2 values are equal or not?
	 * If equal, a "1" will print out.
	 * If not equal, a "0" will print out.
	 */
	// printf("%d\n", (v1==v2));
	// printf("%d\n", (v1==v1));
	// printf("%d\n", (v1==(v2+v2+v2)));
	
	/* By passing a value to compare with the pass in element.data.
	 * checkStatus = 0, if they are not equal.
	 * checkStatus = 1, if they are equal.
	 */
	/*remove_ElementX(myList, &v1, compareInt);
	remove_ElementX(myList, &v2, compareInt);
	remove_ElementX(myList, &v3, compareInt);
}*/





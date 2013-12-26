#include "testUtils.h"
#include "priorityQueue.h"
#include "testUtils.h"
#include <memory.h>
#include <stdlib.h>

Queue *queue;

void tearDown(){
	free(queue->base);
    free(queue);
}

int compareInt ( void* a,  void* b){
    return (*(int*)a - *(int*)b);
}

int compareStrings( void* a,  void* b){
    return strcmp((char*)a,(char*)b);
}

void test_inserts_an_Integer_element_in_queue(){
        int int_arr[2] = {1,2};
        int first = 2,
        	second = 1;
        Queue expected = {int_arr,2,sizeof(int),1,0};
        queue = create(sizeof(int), 2);
        priorityEnqueue(queue,&first,compareInt);
        priorityEnqueue(queue,&second,compareInt);
}

void test_inserts_String_at_rear_of_queue(){
        String string_arr[3] = {"SOUMYA","GHOSH",""};
        String name1 = "GHOSH",
			   name2 = "SOUMYA";
        Queue expected = {string_arr,3,sizeof(String),1,0};
        queue = create(sizeof(String), 3);
        priorityEnqueue(queue,name1,compareStrings);
        priorityEnqueue(queue,name2,compareStrings);
}

void test_enQueue_returns_one_for_sucessful_insert(){
        int result;
        String name1 = "Soumya";
        queue = create(sizeof(String), 2);
        result = priorityEnqueue(queue, name1,compareStrings);
        ASSERT(1 == result);
}

void test_enQueue_returns_zero_while_trying_to_insert_in_full_queue(){
    int result;
    String name1 = "Soumya";
    String name2 = "Ghosh";
    queue = create(sizeof(String), 1);
    priorityEnqueue(queue,name1,compareStrings);
    result = priorityEnqueue(queue, name2,compareStrings);
    ASSERT(0 == result);
}

void test_dequeues_from_integer_queue(){
        int* result;
    int first = 1,
            second = 2;
        queue = create(sizeof(int), 3);
        priorityEnqueue(queue, &first, compareInt);
        priorityEnqueue(queue, &second, compareInt);
        result = priorityDequeue(queue);
        ASSERT(1 == *result);
        ASSERT(1 == queue->front);
}

void test_dequeue_from_empty_queue_return_zero(){
        queue = create(sizeof(String), 2);
        ASSERT(NULL == priorityDequeue(queue));
}

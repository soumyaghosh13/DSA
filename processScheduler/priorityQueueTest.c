#include "testUtils.h"
#include "priorityQueue.h"


//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed




void test_to_create_a_priority_queue(){
        ProcessSceduler* compiler;
        PriorityQueue p1 = {"GCC",5,1};
        compiler = createPriorityQueue();
        ASSERT(0==compiler->length);
        ASSERT(-1==compiler->tail);
}


void test_to_insert_first_element_in_empty_priority_queue(){
        ProcessSceduler* systemUtility;
        PriorityQueue p1 = {"TaskManager",10,1};
        systemUtility = createPriorityQueue();
        enPriorityQueue(systemUtility, &p1);
        ASSERT(systemUtility->head=&p1);
        ASSERT(systemUtility->length==1);
        ASSERT(systemUtility->tail==0);
}

void test_to_insert_element_into_priority_queue_when_another_element_is_there(){
        ProcessSceduler* sq;
        PriorityQueue p1 = {"Browser",10,1};
        PriorityQueue p2 = {"GCC",10,1};
        sq = createPriorityQueue();
        enPriorityQueue(sq, &p1);
        enPriorityQueue(sq, &p2);
        ASSERT(sq->head=&p1);
        ASSERT(sq->head->next=&p2);
        ASSERT(sq->length==2);
        ASSERT(sq->tail==1);
}

void test_to_delete_element_from_priority_queue(){
        ASSERT(0);
}



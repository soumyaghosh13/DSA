#include "testUtils.h"
#include "circularQueue.h"
#include <memory.h>
#include <stdlib.h>


//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Queue *queue;

//setup
void tearDown(){
    free(queue->base);//not needed
    free(queue);
}

int areEqual(Queue a, Queue b){
        int result = a.length == b.length && a.front == b.front
                                && a.rear == b.rear &&  a.elementSize == b.elementSize ;
        if(!result) return result;
        return 0 == memcmp(a.base,b.base,a.length*a.elementSize);
}

void test_creates_a_queue_of_integers(){
        int arr[2] = {0,0};
        Queue expected = {arr,2,sizeof(int),-1,-1};
        queue = create(sizeof(int),2);
        ASSERT(areEqual(expected, *queue));
};

void test_creates_a_queue_of_strings (){
        String arr_blank[3] = {"","",""};
        Queue expected = {arr_blank,3,sizeof(String),-1,-1};
        queue = create(sizeof(String),3);
        ASSERT(areEqual(expected, *queue));
};

void test_inserts_integer_element_in_queue(){
    int int_arr[3] = {1,2,0};
    int first = 1,second = 2;
    Queue expected = {int_arr,3,sizeof(int),1,0};
    queue = create(sizeof(int), 3);
    enqueue(queue,&first);
    enqueue(queue,&second);
    ASSERT(areEqual(expected, *queue));
}

void test_inserts_String_elements_in_queue_at_end(){
        String string_arr[3] = {"Soumya","Ghosh",""};
        String name1 = "Soumya",
                           name2 = "Ghosh";
        Queue expected = {string_arr,3,sizeof(String),1,0};
        queue = create(sizeof(String), 3);
        enqueue(queue,name1);
        enqueue(queue,name2);
        ASSERT(areEqual(expected, *queue));
}

void test_enqueue_in_full_queue_return_zero(){
    int res;
    String name1 = "Sam",
      name2 = "Soumya",
      name3 = "Ghosh";
    queue = create(sizeof(String), 2);
    enqueue(queue,name1);
    enqueue(queue,name2);
    res = enqueue(queue, name3);
    ASSERT(0 == res);
}

void test_successful_enqueue_return_one(){
        int res;
        String name1 = "Soumya";
        queue = create(sizeof(String), 2);
        res = enqueue(queue, name1);
        ASSERT(1 == res);
}

void test_dequeues_from_integer_queue(){
        int* res;
    int first = 1,
            second = 2;
        queue = create(sizeof(int), 3);
        enqueue(queue, &first);
        enqueue(queue, &second);
        res = dequeue(queue);
        ASSERT(1 == *res);
        ASSERT(1 == queue->front);
}

void test_dequeues_the_first_element_of_queue_of_strings(){
        String* res;
    String name1 = "Soumya",
               name2 = "Ghosh";
        queue = create(sizeof(String), 3);
        enqueue(queue, &name1);
        enqueue(queue, &name2);
        res = dequeue(queue);
        ASSERT(strcmp("Soumya",*res)== 0);
}

void test_dequeue_from_empty_queue_return_zero(){
        queue = create(sizeof(String), 2);
        ASSERT(NULL == dequeue(queue));
}

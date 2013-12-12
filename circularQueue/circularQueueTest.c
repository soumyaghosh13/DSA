#include "testUtils.h"
#include "circularqueue.h"
#include <stdlib.h>
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


void test_create_queue_creates_queue(){
        int i;
        queue* queue;
        int test_arr[] = {0,0,0,0,0};
        queue = create(sizeof(int),5);
        i=memcmp(test_arr,queue->elements,5);
        ASSERT(!i);
        ASSERT(queue->elementSize == 4);
        ASSERT(queue->front == -1);
        ASSERT(queue->rear == -1);
        ASSERT(queue->no_of_elements == 5);
}

void test_enqueue_char_element_at_end_of_queue(){
        queue* queue;
        char c='S';
        queue = create(sizeof(char),5);
        ASSERT(enqueue(queue,&c));
        ASSERT(*(char*)(queue->elements)=='S');
        ASSERT(queue->rear==0);
        free(queue);
}

void test_enqueue_char_element_at_middle_of_queue(){
        queue* queue;
        char c='K';
        queue = create(sizeof(char),6);
        queue->rear = 3;
        ASSERT(enqueue(queue,&c));
        ASSERT(*(char*)(queue->elements+queue->rear*queue->elementSize) == 'K');
        ASSERT(queue->rear == 4);
        free(queue);
}

void test_enqueue_char_element_return_false_when_queue_is_full(){
        queue* queue;
        char c='Q';
        queue = create(sizeof(char),6);
        queue->rear = 5;
        queue->front = -1;
        ASSERT(!enqueue(queue,&c));
        ASSERT(queue->rear == 5);
        free(queue);
}

void test_dequeue_string_element_at_front_of_queue(){
        void* element;
        queue* queue;
        string data[]={"soumya","mohit","sandesh"};
        queue = create(sizeof(string),5);
        enqueue(queue,&data[0]);
        enqueue(queue,&data[1]);
        enqueue(queue,&data[2]);
        ASSERT(queue->rear == 2);
        ASSERT(queue->front == -1);
        element = dequeue(queue);
        ASSERT(!strcmp(*(string*)element , "soumya"));
        ASSERT(queue->rear == 2);
        ASSERT(queue->front == 0);
}


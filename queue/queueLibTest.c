#include "testUtils.h"
#include "queueLib.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


int areEqual(queue* src, queue* expected){
	int res = (src->queueInfo.elementSize == expected->queueInfo.elementSize) 
				&& (src->queueInfo.front == expected->queueInfo.front)
				&& (src->queueInfo.rear == expected->queueInfo.rear)
				&& (src->queueInfo.length == expected->queueInfo.length);
	if(!res)
		return res;
	res = memcmp(src->base,expected->base,src->queueInfo.length*src->queueInfo.elementSize);
	return 0==res;
}


void test_to_create_int_queue(){
	int expArr[2]={0,0};
	queue expected = {expArr,{2,sizeof(int),-1,-1}};
	queue* queue=create(sizeof(int), 2);
	ASSERT(areEqual(queue, &expected));
	free(queue->base);
	free(queue);
}

void test_to_create_string_queue(){
	String expArr[2]={"Prateek","Kajal"};
	queue expected = {expArr,{2,sizeof(String),-1,-1}};
	queue* queue=create(sizeof(String), 2);
	memcpy(queue->base, expected.base, sizeof(String)*2);
	ASSERT(areEqual(queue, &expected));
	free(queue->base);
	free(queue);
}

void test_to_enqueue_an_int_element(){
	int element = 4;
	queue* queue = create(sizeof(int), 3);
	ASSERT(enQueue(queue, &element));
	free(queue->base);
	free(queue);	
}

void test_to_enqueue_an_string_element(){
	String element = "Prateek";
	queue* queue = create(sizeof(String), 3);
	ASSERT(enQueue(queue, &element));
	free(queue->base);
	free(queue);	
}

void test_to_enqueue_an_int_element_when_queue_is_full(){
	int element = 4;
	queue* queue = create(sizeof(int), 2);
	enQueue(queue, &element);
	enQueue(queue, &element);
	ASSERT(0==enQueue(queue, &element));
	free(queue->base);
	free(queue);	
}

void test_to_dequeue_an_int_element(){
	int element = 2;
	int element2 = 3;
	void *dequeuedElement;
	queue* queue = create(sizeof(int), 3);
	enQueue(queue, &element);
	enQueue(queue, &element2);
	dequeuedElement = deQueue(queue); 
	ASSERT(2==*(int*)dequeuedElement);
	ASSERT(3==((int*)queue->base)[0]);
	ASSERT(0==queue->queueInfo.rear);
	free(queue->base);
	free(queue);	
}

void test_to_dequeue_an_int_element_when_it_is_already_empty(){
	void *dequeuedElement;
	queue* queue = create(sizeof(int), 3);
	dequeuedElement = deQueue(queue); 
	ASSERT(NULL==dequeuedElement);
	free(queue->base);
	free(queue);	
}
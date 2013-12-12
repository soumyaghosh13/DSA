#include "queueLib.h"
#include <stdlib.h>
#include <string.h>
queue* create(int elementSize,int length){
	queue* queue = calloc(1,sizeof(queue));
	queue -> base = calloc(length, elementSize);
	queue->queueInfo.front = -1;
	queue->queueInfo.rear = -1;
	queue->queueInfo.elementSize = elementSize;
	queue->queueInfo.length = length;
	return queue;
}

int isFull(queue* queue){
	if(queue->queueInfo.rear+1 >= queue->queueInfo.length)
		return 1;
	return 0;
}

bool enqueue(queue* queue,void* element){
	void* address;
	if(isFull(queue))
		return false;
	address = queue->base+(++(queue->queueInfo.rear)*queue->queueInfo.elementSize);
	memcpy(address,element,queue->queueInfo.elementSize);
	return true; 
}

int isEmpty(queue* queue){
	if(queue->queueInfo.rear == -1)
		return 1;
	return 0;
}

void* dequeue(queue *queue){
	void* dequeuedElement;
	void* copyFrom;
	if(isEmpty(queue))
		return NULL;
	dequeuedElement=malloc(queue->queueInfo.elementSize);
	copyFrom = queue->base+queue->queueInfo.elementSize;
	memcpy(dequeuedElement, queue->base, queue->queueInfo.elementSize);
	memmove(queue->base, copyFrom, (queue->queueInfo.length-1)*queue->queueInfo.elementSize);
	queue->queueInfo.rear--;
	return dequeuedElement;
}
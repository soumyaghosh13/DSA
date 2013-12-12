#include "circularqueue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


queue* create(int elementSize, int no_of_elements){
        queue* queue = calloc(1,sizeof(queue));
        queue->front=-1;
        queue->rear=-1;
        queue->elements= calloc(no_of_elements,elementSize);
        queue->no_of_elements=no_of_elements;
        queue->elementSize=elementSize;
        return queue;
}
bool enqueue(queue* queue,void* element)
{
        if(isFull(queue)) return false;
        queue->rear++;
        memcpy((queue->elements+(queue->elementSize*queue->rear)) , element,queue->elementSize);
        return true;
}
void* dequeue(queue* queue){
        void* element = malloc(queue->elementSize);
        if(isEmpty(queue)) return false;
        queue->front++;
        memmove(element, queue->elements+(queue->elementSize*queue->front), queue->elementSize);
        return element;
}
bool isFull(queue* queue){ 
        if(queue->front == -1 && queue->rear == queue->no_of_elements-1) return true;
        return (queue->front == queue->rear+1);
}
bool isEmpty(queue* queue){
        if(queue->front ==-1 && queue->rear == -1) return true;
        return (queue->front == queue->rear+1);
}


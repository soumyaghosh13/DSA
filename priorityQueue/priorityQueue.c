#include "priorityQueue.h"
#include <memory.h>
#include <stdlib.h>

int compareData ( void* a,  void* b){
    return (*(int*)a - *(int*)b);
}

int priorityEnqueue(Queue* queue, void* element,compare comp){
    int j = (queue->rear)-1;
    void* elementToCompare;
    int comparisonResult;
    if(queueIsFull(queue))
        return 0;
    if(queue->rear >= queue->length)
    	queue->rear = 0;
    if(queue->front == -1 && queue->rear == -1){
    	queue->front++;
    	queue->rear++;
    }
    else{
        queue->rear++;
        for (j = queue->rear-1; j >= queue->front; j--) {
            elementToCompare = queue->base + j * queue->elementSize;
            comparisonResult = comp(element, elementToCompare);
            if (comparisonResult >= 0) {
                break; 
            }
            memmove(elementToCompare + queue->elementSize, 
                    elementToCompare, queue->elementSize);                                     
        } 
        memmove(queue->base+((j+1)*queue->elementSize), element, queue->elementSize);
        return 1;   
    }
    memmove(queue->base+(queue->rear*queue->elementSize), element, queue->elementSize);
    return 1;
}

void* priorityDequeue(Queue *queue){
        void* temp;
        void* deletedElement = malloc(queue->elementSize);
        if(queueIsEmpty(queue))
                return NULL;
        temp = queue->base+(queue->front*queue->elementSize);
        memcpy(deletedElement,temp, queue->elementSize);
        queue->front++;
        return deletedElement;
}


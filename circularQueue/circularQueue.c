#include "circularQueue.h"
#include <memory.h>
#include <stdlib.h>

Queue* create(int elementSize, int length){
    Queue* queue;
    queue = (Queue*)malloc(sizeof(Queue));
    queue->base = calloc(length, elementSize);
    queue->elementSize = elementSize;
    queue->front = -1;
    queue->rear = -1;
    queue->length = length;
    return queue;
}

int queueIsEmpty(Queue* queue){
        if(queue->rear == -1 && queue->front == -1)
                return 1;
        return 0;
}

int queueIsFull(Queue* queue){
        if(queue->front == 0 && queue->rear == queue->length-1)
                return 1;
        if(queue->front == queue->rear+1)
                return 1;
        return 0;
}

int enqueue(Queue* queue, void* element){
    if(queueIsFull(queue))
        return 0;
    if(queue->rear >= queue->length)
            queue->rear = 0;
    if(queue->front == -1 && queue->rear == -1){
            queue->front++;
            queue->rear++;
    }
    else
            queue->rear++;
    memmove(queue->base+(queue->rear*queue->elementSize), element, queue->elementSize);
    return 1;
}

void* dequeue(Queue *queue){
        void* copyFrom;
        void* deletedElement = malloc(queue->elementSize);
        if(queueIsEmpty(queue))
                return NULL;
        copyFrom = queue->base+(queue->front*queue->elementSize);
        memcpy(deletedElement,copyFrom, queue->elementSize);
        queue->front++;
        return deletedElement;
}




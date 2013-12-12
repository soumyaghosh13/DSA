#include "priorityQueue.h"
#include <stdlib.h>

ProcessSceduler* createPriorityQueue(){
        ProcessSceduler* priorityQueue = malloc(sizeof(ProcessSceduler));
        priorityQueue->length=0;
        priorityQueue->tail=-1;
        return priorityQueue;
}

int enPriorityQueue(ProcessSceduler *priorityQueue, PriorityQueue *process){
        if(priorityQueue->length==0 && priorityQueue->tail==-1){
                priorityQueue->head = process;
                process->next = priorityQueue->head;
                priorityQueue->tail++;
                priorityQueue->length++;
                return 1;
        }
        if(priorityQueue->length > 0 && priorityQueue->tail > -1){
                PriorityQueue* temp = priorityQueue->head;
                while(temp->next != priorityQueue->head){
                        temp = temp->next;
                }
                temp->next = process;
                process->next = priorityQueue->head;
                priorityQueue->tail++;
                priorityQueue->length++;
                return 1;
        }
        return 1;
}

PriorityQueue dePriorityQueue(PriorityQueue PQ){
        return PQ;
}

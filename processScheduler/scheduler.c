#include "scheduler.h"
#include <stdlib.h>
#include <string.h>


Scheduler* create(){
    Scheduler *processQueue = calloc(sizeof(Scheduler),1);
    return processQueue;
}

int insertAtStart(Scheduler *processQueue, Process *process){
        if(processQueue->head == NULL)
                process->next = NULL;
        // else
        process->next = processQueue->head;
        processQueue->head = process;
        processQueue->length++;
                return processQueue->length;        
}

int insertProcessInBetween(Scheduler *processQueue,Process *previous,Process *process ,Process *next){
    previous->next = process;
    process->next = next;
    return ++processQueue->length;
}

int insertProcess(Scheduler *processQueue, Process *process){
    Process *previous,*next,*temp;
    temp = processQueue->head;
    if(processQueue->length == 0)                
        return insertAtStart(processQueue, process);
    if(process->processPriority < temp->processPriority)
        return insertAtStart(processQueue, process);
    for(;temp->next != NULL;temp = temp->next){
        previous = temp;
        next = temp->next;
        if(process->processPriority < next->processPriority)
            return insertProcessInBetween(processQueue ,previous, process ,next);
    };
    temp->next = process;
    process->next = NULL;
    return ++processQueue->length;
}

Process* removeProcess(Scheduler *processQueue){
    Process *temp,*previous,*next;
    temp = processQueue->head;
    if(processQueue->length == 1){
        if(temp->processTime == 0)
            processQueue->head = NULL;
        return temp;
    }
    if(temp->processTime == 0)
        processQueue->head = temp->next;
    for(;temp->next != NULL;temp = temp->next){
        previous = temp;
        next = temp->next;
        if(next->processTime == 0){
            previous->next = next->next;
            return next;
        }
    }
    
    if(NULL == temp->next){
        previous->next = NULL;
        return previous;
    };
    return 0;
}

void dispose(Scheduler *processQueue){
    free(processQueue);
}
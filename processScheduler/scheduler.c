#include "scheduler.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Process* add(int priority,int ptime,String name,int num){
        Process *process;
        process = (Process*)malloc(sizeof(Process));
        process->priority = priority;
        process->ptime = ptime;
        process->num = num;
        strcpy(process->name,name);
        return process;
}
bool insert(Stack* stack,Process* process){
        stack->top++;
        if(memcpy((stack->base+(stack->elementSize*stack->top)) , process,stack->elementSize))
                return true;
        return false;
}
int scheduler(Process* process){
        int i;
        int count = 0;
        for(i = 0; i<process->num;i++){
                if(process->priority == 1){
                        if(process->ptime == 0)
                                free(process);
                        else{
                                process->ptime -= 100;
                                count++;
                        }
                }
        }
        return count;
}

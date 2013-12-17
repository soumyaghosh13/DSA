#include "testUtils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "scheduler.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
 
void test_for_add_new_process(){
        Process* result;
        result = add(2, 200, "gcc",3);
        ASSERT(result->priority == 2);
        ASSERT(result->ptime == 200);
        ASSERT(0 == strcmp(result->name,"gcc"));
}

void test_for_schedule_process(){
        Process* process = (Process*)malloc(sizeof(Process));
        Stack* stack = (Stack*)malloc(sizeof(Process));
        int res;
        process = add(2, 400, "browser",3);
        insert(stack,process);
        process = add(3, 100, "taskmanager",3);
        insert(stack,process);
        process = add(1, 200, "gcc",3);
        insert(stack,process);
        res = scheduler(process);
        ASSERT(res == 2);
}
#include "testUtils.h"
#include "scheduler.h"
#include "testUtils.h"
#include <stdlib.h>


//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
Scheduler *queue;

void tearDown(){
        dispose(queue);
}

void test_add_first_process(){
        Status statusp1 = {0,0,0};
        Process p1 = {"p1",1000,statusp1,3,NULL};
        queue = create();
        ASSERT(1 == insertProcess(queue, &p1));
}

void test_add_process_with_priority_higher_than_first_process(){
        Status statusp1 = {0,0,0};
        Process p1 = {"p1",1000,statusp1,3,NULL};
        Process p2 = {"p2",500,statusp1,1,NULL};
        queue = create();
        ASSERT(1 == insertProcess(queue, &p1));
        ASSERT(2 == insertProcess(queue, &p2));
}

void test_allocate_timeSlice_to_process(){
        Status statusp1 = {0,0,0};
        Process p1 = {"p1",1000,statusp1,3,NULL};
        Process p2 = {"p2",500,statusp1,1,NULL};
        queue = create();
        ASSERT(1 == insertProcess(queue, &p1));
        ASSERT(2 == insertProcess(queue, &p2));
               
}
// void test_remove_first_and_only_process(){
//         Status statusp1 = {0,1,0};
//         Process p1 = {"p1",0,statusp1,5,NULL};
//         Process* res;
//         queue = create();
//         insertProcess(queue, &p1);
//         res = removeProcess(queue);
//         ASSERT(&p1 == res);
// }

// void test_remove_processes_in_middle(){
//         Process* res;
//         Status statusp1 = {0,1,0};
//         Process p1 = {"p1",100,statusp1,5,NULL};
//         Process p2 = {"p2",0,statusp1,1,NULL};
//         queue = create();
//         insertProcess(queue, &p1);
//         insertProcess(queue, &p2);
//         res = removeProcess(queue);
//         ASSERT(&p2 == res);
// }

// void test_remove_last_process(){
//         Process* res;
//         Status statusp1 = {0,1,0};
//         Process p1 = {"p1",1000,statusp1,1,NULL};
//         Process p2 = {"p2",10,statusp1,5,NULL};
//         Process p3 = {"p3",0,statusp1,7,NULL};
//         queue = create();
//         insertProcess(queue, &p1);
//         insertProcess(queue, &p2);
//         insertProcess(queue, &p3);
//         res = removeProcess(queue);
//         ASSERT(&p3 == res);
// }
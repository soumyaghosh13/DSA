#include "testUtils.h"
#include "mergeSort.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt(void* prev, void* next){
        return *(int*)prev < *(int*)next;
}

void test_single_element_is_always_sorted(){
        int count;
        int data[] = {1};
        mergeSort(&data,1,sizeof(int),compareInt);
        ASSERT(1==data[0]);
}


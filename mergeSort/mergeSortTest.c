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

void test_sort_for_even_number_of_element_best_case(){
        int count;
        int data[] = {1,2,3,4};
        mergeSort(&data,4,sizeof(int),compareInt);
        for(count=0 ; count < 4 ; count++){
                ASSERT(data[count]==count+1);
        }
}

void test_sort_for_odd_number_of_element_worst_case(){
        int count;
        int data[] = {5,4,3,2,1};
        mergeSort(&data,5,sizeof(int),compareInt);
        for(count=0 ; count < 5 ; count++){
                ASSERT(data[count]==count+1);
        }
}

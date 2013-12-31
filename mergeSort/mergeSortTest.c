#include "testUtils.h"
#include "mergeSort.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct {
        int rollNo;
        char* name;
} Student;

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


int compareChar (void* prev, void* next){
        return *(char*)prev < *(char*)next;
}

void test_to_sort_char_data(){
        char arr[] = {'s','o','u','m','y','a'};
        mergeSort(arr, 6, sizeof(char), compareChar );
        ASSERT(arr[0] == 'a');
        ASSERT(arr[1] == 'm');
        ASSERT(arr[2] == 'o');
        ASSERT(arr[3] == 's');
        ASSERT(arr[4] == 'u');
        ASSERT(arr[5] == 'y');
}

int compareStudent (void* prev, void* next){
        Student* first = (Student*)prev;
        Student* second = (Student*)next;
        return first->rollNo < second->rollNo;
}

void test_to_sort_Student_data(){
        Student arr[] = {{22,"Soumya"},{10,"Sam"},{15,"Buka"}};
        mergeSort(arr, 3, sizeof(Student), compareStudent );
        ASSERT(10 == arr[0].rollNo);
        ASSERT(15 == arr[1].rollNo);
        ASSERT(22 == arr[2].rollNo);
}

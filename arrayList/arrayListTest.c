#include <stdlib.h>
#include "testUtils.h"
#include "arrayList.h"
#include <string.h>

const int SUCCESS = 1;
const int FAILURE = 0;

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct {
        int id;
        char* name;
        int age;
} Intern;

int compareStruct(void* first,void* second){
        Intern *intern1 = (Intern*)first, *intern2 = (Intern*)second;        
        return (intern1->age == intern2->age) &&
                (intern1->id == intern2->id) &&
                (0 == strcmp(intern1->name,intern2->name));
};

Intern soumya = {15386, "soumya", 18};
Intern ji = {13432, "Immortal", 17};        
ArrayList interns;
ArrayList *internsPtr;

void setup() {
        int noOfElements = 2;        
        interns = createArrayList(noOfElements);
        internsPtr = &interns;
}

void tearDown() {
        disposeArrayList(internsPtr);        
}

void test_insert_element(){
        int result = insertInArrayList(internsPtr, 0, &soumya);

        Intern *actual = (Intern*)get(internsPtr, 0);
        ASSERT(result == SUCCESS);
        ASSERT(soumya.id == actual->id);
}

void test_insert_multiple_elements() {
        insertInArrayList(internsPtr, 0, &soumya);
        insertInArrayList(internsPtr, 1, &ji);
        ASSERT(&soumya == get(internsPtr, 0));
        ASSERT(&ji == get(internsPtr, 1));
}

void test_insert_element_increase_capacity() {
        int noOfElements = 1;
        ArrayList list = createArrayList(noOfElements);
        ArrayList *listPtr = &list;

        insertInArrayList(listPtr, 0, &soumya);
        insertInArrayList(listPtr, 1, &ji);

        ASSERT(&soumya == get(listPtr, 0));
        ASSERT(&ji == get(listPtr, 1));

        disposeArrayList(listPtr);                
}

void test_insert_should_fail_beyond_if_insert_length() {
        int result = FAILURE;
        result = insertInArrayList(internsPtr, 2, &soumya);
        ASSERT(result == FAILURE);
}

void test_insert_should_fail_if_insert_at_negative_index() {
        int result = FAILURE;
        result = insertInArrayList(internsPtr, -1, &soumya);
        ASSERT(result == FAILURE);
}

void test_insert_at_middle_should_shift_the_elements() {
        Intern tanbirka = {43343, "Tanbir Ka"};
        insertInArrayList(internsPtr, 0, &soumya);
        insertInArrayList(internsPtr, 1, &ji);
        insertInArrayList(internsPtr, 1, &tanbirka);
        
        ASSERT(&soumya == get(internsPtr, 0));
        ASSERT(&tanbirka == get(internsPtr, 1));
        ASSERT(&ji == get(internsPtr, 2));
}

void test_remove_single_element(){
        int result;
        insertInArrayList(internsPtr, 0, &soumya);
        result = removeFromArrayList(internsPtr,0);
        ASSERT(SUCCESS == result);
        ASSERT(0 == getLength(internsPtr));
        ASSERT(NULL == get(internsPtr,0));
};

void test_removing_element_from_last(){
        int result;
        insertInArrayList(internsPtr, 0, &soumya);
        insertInArrayList(internsPtr, 1, &ji);
        result = removeFromArrayList(internsPtr,1);
        ASSERT(1 == getLength(internsPtr));
        ASSERT(NULL == get(internsPtr,1));
        ASSERT(&soumya == get(internsPtr,0));
};

void test_remove_element_from_between(){
        int result;
        Intern tanbirka = {43343, "Tanbir Ka"};
        insertInArrayList(internsPtr, 0, &soumya);
        insertInArrayList(internsPtr, 1, &ji);
        insertInArrayList(internsPtr, 2, &tanbirka);
        result = removeFromArrayList(internsPtr,1);
        ASSERT(SUCCESS == result);
        ASSERT(&soumya == get(internsPtr,0));
        ASSERT(&tanbirka == get(internsPtr,1));
        ASSERT(NULL == get(internsPtr,2));
};

void test_removing_element_beyond_capacity_should_fail(){
        int result;
        insertInArrayList(internsPtr, 0, &soumya);
        result = removeFromArrayList(internsPtr,1);
        ASSERT(FAILURE == result);
};

void test_removing_non_existing_element_should_fail(){
        int result;
        result = removeFromArrayList(internsPtr,-1);
        ASSERT(FAILURE == result);
};

void remove_fail_when_list_is_null(){
        int result;
        result = removeFromArrayList(NULL,0);
        ASSERT(FAILURE == result);        
};

void test_searching_element(){
        int result;
        Intern sam = {43343, "Sam Fisher"};
        insertInArrayList(internsPtr, 0, &soumya);
        insertInArrayList(internsPtr, 1, &ji);
        insertInArrayList(internsPtr, 2, &sam);
        result = search(internsPtr,&ji,compareStruct);
        ASSERT(1 == result);
};

void test_searching_non_existing_element_gives_0(){
        int result;
        Intern sam = {43343, "Sam Fisher"};
        insertInArrayList(internsPtr, 0, &soumya);
        result = search(internsPtr,&sam,compareStruct);
        ASSERT(-1 == result);
};

void test_getting_next_element_through_iterator(){
        Iterator it;
        insertInArrayList(internsPtr, 0, &soumya);
        insertInArrayList(internsPtr, 1, &ji);
        it = getArrayListIterator(internsPtr);
        ASSERT(&soumya == it.next(&it));
        ASSERT(&ji == it.next(&it));
};
#include <stdlib.h>
#include "testUtils.h"
#include "arrayList.h"

const int SUCCESS = 1;
const int FAILURE = 0;

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct {
        int id;
        char* name;
        int age;
} Intern;

Intern soumya = {15386, "soumya", 22};
Intern ji = {13432, "Immortal", 17};        
ArrayList interns;
ArrayList *internsPtr;

void setup() {
        int noOfElements = 2;        
        interns = create(noOfElements);
        internsPtr = &interns;
}

void tearDown() {
        dispose(internsPtr);        
}

void test_insert_element(){
        int result = insert(internsPtr, 0, &soumya);
        Intern *actual = (Intern*)get(interns, 0);
        ASSERT(result == SUCCESS);
        ASSERT(soumya.id == actual->id);
}

void test_insert_multiple_elements() {
        insert(internsPtr, 0, &soumya);
        insert(internsPtr, 1, &ji);
        ASSERT(&soumya == get(interns, 0));
        ASSERT(&ji == get(interns, 1));
}

void test_insert_grows_beyond_capacity() {
        int noOfElements = 1;
        ArrayList list = create(noOfElements);
        ArrayList *listPtr = &list;
        insert(listPtr, 0, &soumya);
        insert(listPtr, 1, &ji);
        ASSERT(&soumya == get(list, 0));
        ASSERT(&ji == get(list, 1));

        dispose(listPtr);                
}

void test_insert_beyond_length_should_failed() {
        int result = FAILURE;
        result = insert(internsPtr, 2, &soumya);
        ASSERT(result == FAILURE);
}

void test_insert_at_negetive_index_should_failed() {
        int result = FAILURE;
        result = insert(internsPtr, -1, &soumya);
        ASSERT(result == FAILURE);
}

void test_insert_at_middle_should_shift_the_elements() {
        Intern sam = {43343, "Sam Fisher"};
        insert(internsPtr, 0, &soumya);
        insert(internsPtr, 1, &ji);
        insert(internsPtr, 1, &sam);        
        ASSERT(&soumya == get(interns, 0));
        ASSERT(&sam == get(interns, 1));
        ASSERT(&ji == get(interns, 2));
}

void test_deletes_from_list(){
        int result;
        insert(internsPtr, 0, &soumya);
        ASSERT(1 == interns.length);
        result = remove(internsPtr, 0);
        ASSERT(NULL == get(interns, 0));
        ASSERT(0 == interns.length);
        ASSERT(result == SUCCESS);
}

void test_delete_from_middle_should_shifts_element(){
        int result;
        insert(internsPtr, 0, &soumya);
        insert(internsPtr, 0, &ji);
        ASSERT(2 == interns.length);
        result = remove(internsPtr, 0);
        ASSERT(&soumya == get(interns, 0));
        ASSERT(NULL == get(interns, 1));
        ASSERT(result == SUCCESS);        
}

void test_iterator_should_give_1_if_next_data_is_present(){
        Iterator it;
        insert(internsPtr, 0, &soumya);
        it = getIterator(internsPtr);
        ASSERT(1 == it.hasNext(&it));
}

void test_iterator_should_give_0_if_next_data_is_not_present(){
        Iterator it;
        it = getIterator(internsPtr);
        ASSERT(0 == it.hasNext(&it));
}

void test_iterator_gives_the_data_of_next_index(){
        Iterator it;
        insert(internsPtr, 0, &soumya);
        insert(internsPtr, 0, &ji);
        it = getIterator(internsPtr);
        ASSERT(&ji == it.next(&it));
        ASSERT(&soumya == it.next(&it));
        ASSERT(NULL == it.next(&it));
}

int areInternsEqual(void* first, void* second){
        Intern firstIntern = *(Intern*)first;
        Intern secondIntern = *(Intern*)second;
        return firstIntern.id == secondIntern.id;
}

void test_search_should_tell_the_index(){
        int result;
        add(internsPtr, &soumya);
        add(internsPtr, &ji);
        result = search(interns, &soumya, areInternsEqual);
        ASSERT(0 == result);
        result = search(interns, &ji, areInternsEqual);
        ASSERT(1 == result);
}

void test_search_should_gives_minus_one_when_data_is_not_present(){
        int result = search(interns, &soumya, areInternsEqual);
        ASSERT(-1 == result);
}

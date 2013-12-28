#include "testUtils.h"
#include "linkedList.h"
#include <string.h>
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

List* list;
void* elementToInsert;
int res;

void assignSpaceAndData(int bytes,void* content){
        elementToInsert = calloc(1,bytes);
        memcpy(elementToInsert,content,bytes);
};

void setup(){
        list = create();
};

void teardown(){
        dispose(list);
};

void test_inserting_first_node(){
        int element = 10;
        assignSpaceAndData(sizeof(int),&element);
        res = insert(list,elementToInsert,1);
        ASSERT(1 == res);
        ASSERT(element == *(int*)getElement(list,1));
};

void test_insert_first_node_string(){
        String element = "soumya";
        assignSpaceAndData(sizeof(String),&element);
        res = insert(list,elementToInsert,1);
        ASSERT(1 == list->length);
        ASSERT(1 == res);
        ASSERT(0 == strcmp(element,*(String*)getElement(list,1)));
};

void test_insert_two_elements_in_linked_list(){
        void* nodeDeleted;
        int element1 = 20,element2 =40;
        res = insert(list,&element1,1);
        res = insert(list,&element2,2);
        ASSERT(20 == *(int*)getElement(list,1));
        nodeDeleted = remove(list,1);
        ASSERT(20 == *(int*)nodeDeleted);
        ASSERT(40 == *(int*)getElement(list,1));
};

void test_insert_element_in_middle(){
        void* node;
        int element1 = 20,element2 = 40,element3 = 60;
        res = insert(list,&element1,1);
        res = insert(list,&element2,2);
        res = insert(list,&element3,2);
        ASSERT(20 == *(int*)getElement(list,1));
        ASSERT(60 == *(int*)getElement(list,2));
        ASSERT(40 == *(int*)getElement(list,3));
};

void test_insert_at_first_position_in_list(){
        int element1 = 20,element2 = 40;
        res = insert(list,&element1,1);
        res = insert(list,&element2,1);
        ASSERT(40 == *(int*)getElement(list,1));
        ASSERT(20 == *(int*)getElement(list,2));
};
 
void test_when_index_is_negative_node_should_not_be_inserted(){
        int element = 50;
        res = insert(list,&element,-1);
        ASSERT(0 == res);
};

void test_when_index_exceeds_lists_length_then_insertion_should_fail(){
        int element = 50;
        res = insert(list,&element,2);
        ASSERT(0 == res);
};

void test_deleting_the_char_node_when_only_one_is_present(){
        void* nodeDeleted;
        char element = 'S';
        res = insert(list,&element,1);
        nodeDeleted = remove(list,1);
        ASSERT(element == *(char*)nodeDeleted);
        ASSERT(0 == list->length);
};

void test_deleting_all_nodes(){
        void* node;
        int element1 = 10,element2 = 20,element3 = 30;
        res = insert(list,&element1,1);
        res = insert(list,&element2,2);
        res = insert(list,&element3,3);
        node = remove(list,1);
        ASSERT(element1 == *(int*)node);
        node = remove(list,1);
        ASSERT(element2 == *(int*)node);
        node = remove(list,1);
        ASSERT(element3 == *(int*)node);
};

void test_deleting_node_in_middle(){
        int element1 = 10,element2 = 20,element3 = 30;
        void* node;
        Node* secondNode;
        res = insert(list,&element1,1);
        res = insert(list,&element2,2);
        res = insert(list,&element3,3);
        node = remove(list,2);
        ASSERT(element2 == *(int*)node);
        ASSERT(element1 == *(int*)getElement(list,1));
        ASSERT(element3 == *(int*)getElement(list,2));
        ASSERT(2 == length(list));
};

void test_deleting_from_empty_list(){
        int element1 = 100;
        Node* node;
        res = insert(list,&element1,1);
        node = remove(list,1);
        ASSERT(element1 == *(int*)node);
        node = remove(list,1);
        ASSERT(NULL == node);
};

void test_when_negative_index_is_given_to_delete(){
        ASSERT(NULL == remove(list,-1));
};

void test_iterator(){
        int element1 = 555,element2 = 666,element3 = 777;
        Iterator it;
        void *e1;
        res = insert(list,&element1,1);
        res = insert(list,&element2,2);
        res = insert(list,&element3,3);
        it = getIterator(list);
        res = it.hasNext(&it);
        e1 = it.next(&it);
        ASSERT(1 == res);
        ASSERT(555 == *(int*)e1);
        e1 = it.next(&it);
        ASSERT(666 == *(int*)e1);
        e1 = it.next(&it);
        ASSERT(777 == *(int*)e1);
        e1 = it.next(&it);
        ASSERT(NULL == e1);
};
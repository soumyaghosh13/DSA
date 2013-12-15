#include "testUtils.h"
#include "LinkedList.h"
#include <string.h>
#include <stdlib.h>


//createLinkedList setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


char testElement1, testElement2, testElement3,temp;
char *insertElement1,*insertElement2,*insertElement3;
LinkedList* list;
void* elementToInsertNode;


void assignSpaceAndData(int bytes,void* content){
        elementToInsertNode = calloc(1,bytes);
        memcpy(elementToInsertNode,content,bytes);
};


void setup(){
        list = createLinkedList();
        testElement1 = 20;
        testElement2 = 40;
        testElement3 = 60;
        insertElement1 = malloc(sizeof(int));
        insertElement2 = malloc(sizeof(int));
        insertElement3 = malloc(sizeof(int));
        memcpy(insertElement1,&testElement1,sizeof(int));
        memcpy(insertElement2,&testElement2,sizeof(int));
        memcpy(insertElement3,&testElement3,sizeof(int));
};


void teardown(){
        free(insertElement1);
        free(insertElement2);
        free(insertElement3);
        free(elementToInsertNode);
        free(list);
};


void test_creation_of_linked_list(){
        ASSERT(0 == list->length);
        ASSERT(NULL == list->head);
};

void test_insert_Node_at_first_position_in_list(){
        temp = insertNode(list,insertElement1,1);
        temp = insertNode(list,insertElement2,1);
        ASSERT(40 == *(int*)list->head->data);
        ASSERT(20 == *(int*)list->head->next->data);
};

void test_insert_Node_in_middle_of_linked_list(){
        Node* node;
        temp = insertNode(list,insertElement1,1);
        temp = insertNode(list,insertElement2,2);
        temp = insertNode(list,insertElement3,2);
        ASSERT(60 == *(int*)list->head->next->data);
        ASSERT(20 == *(int*)list->head->data);
        ASSERT(40 == *(int*)list->head->next->next->data);
};

void test_for_negetive_index_insertion_should_failed(){
        temp = insertNode(list,insertElement1,-1);
        ASSERT(0 == temp);
};

void test_delete_first_node_of_linked_list(){
        Node* node;
        temp = insertNode(list,insertElement1,1);
        temp = insertNode(list,insertElement2,2);
        node = removeNode(list,1);
        ASSERT(testElement1 == *(int*)node->data);
        ASSERT(testElement2 == *(int*)list->head->data);
};


void test_delete_last_node_of_linked_list(){
        Node* node;
        temp = insertNode(list,insertElement1,1);
        temp = insertNode(list,insertElement2,2);
        node = removeNode(list,2);
        ASSERT(testElement2 == *(int*)node->data);
        ASSERT(testElement1 == *(int*)list->head->data);        
};


void test_delete_any_node_of_linked_list(){
        Node* node;
        Node* secondNode;
        temp = insertNode(list,insertElement1,1);
        temp = insertNode(list,insertElement2,2);
        temp = insertNode(list,insertElement3,3);
        node = removeNode(list,2);
        ASSERT(testElement2 == *(int*)node->data);
        ASSERT(testElement1 == *(int*)list->head->data);
        secondNode = list->head->next;
        ASSERT(testElement3 == *(int*)secondNode->data);
        ASSERT(testElement1 == *(int*)secondNode->previous->data);
};

void test_delete_node_when_linked_list_contain_one_node(){
        Node* node;
        String element  = "soumya";
        assignSpaceAndData(sizeof(String),&element);
        temp = insertNode(list,elementToInsertNode,1);
        node = removeNode(list,1);
        ASSERT(0 == strcmp(element,node->data));
};




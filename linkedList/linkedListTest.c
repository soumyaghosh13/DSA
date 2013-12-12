#include "testUtils.h"
#include "linkedList.h"
#include <string.h>
#include <stdlib.h>


//createLinkedList setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


int element1,element2,element3,res;
int *elementToinsertNode1,*elementToinsertNode2,*elementToinsertNode3;
linkedList* list;
void* elementToinsertNode;


void assignSpaceAndData(int bytes,void* content){
        elementToinsertNode = calloc(1,bytes);
        memcpy(elementToinsertNode,content,bytes);
};


void setup(){
        list = createLinkedList();
        element1 = 20;
        element2 = 40;
        element3 = 60;
        elementToinsertNode1 = malloc(sizeof(int));
        elementToinsertNode2 = malloc(sizeof(int));
        elementToinsertNode3 = malloc(sizeof(int));
        memcpy(elementToinsertNode1,&element1,sizeof(int));
        memcpy(elementToinsertNode2,&element2,sizeof(int));
        memcpy(elementToinsertNode3,&element3,sizeof(int));
};


void teardown(){
        free(elementToinsertNode1);
        free(elementToinsertNode2);
        free(elementToinsertNode3);
        free(elementToinsertNode);
        free(list);
};


void test_creation_of_linked_list(){
        ASSERT(0 == list->length);
        ASSERT(NULL == list->head);
};


void test_insertNodeing_first_integer_node_in_linked_list(){
        int element = 10;
        assignSpaceAndData(sizeof(int),&element);
        res = insertNode(list,elementToinsertNode,1);
        ASSERT(1 == res);
        ASSERT(NULL == list->head->next);
        ASSERT(NULL == list->head->previous);
        ASSERT(element == *(int*)list->head->data);
};

void test_insertNodeing_first_String_node_in_linked_list(){
        String element = "swamiji";
        assignSpaceAndData(sizeof(String),&element);
        res = insertNode(list,elementToinsertNode,1);
        ASSERT(1 == list->length);
        ASSERT(1 == res);
        ASSERT(0 == strcmp(element,*(String*)list->head->data));
};

void test_insertNode_element_in_middle(){
        Node* node;
        res = insertNode(list,elementToinsertNode1,1);
        res = insertNode(list,elementToinsertNode2,2);
        res = insertNode(list,elementToinsertNode3,2);
        ASSERT(60 == *(int*)list->head->next->data);
        ASSERT(20 == *(int*)list->head->data);
        ASSERT(40 == *(int*)list->head->next->next->data);
};


void test_insertNode_at_first_position_in_list(){
        res = insertNode(list,elementToinsertNode1,1);
        res = insertNode(list,elementToinsertNode2,1);
        ASSERT(40 == *(int*)list->head->data);
        ASSERT(20 == *(int*)list->head->next->data);
};

void test_deleting_first_node(){
        Node* node;
        res = insertNode(list,elementToinsertNode1,1);
        res = insertNode(list,elementToinsertNode2,2);
        node = removeNode(list,1);
        ASSERT(element1 == *(int*)node->data);
        ASSERT(element2 == *(int*)list->head->data);
};


void test_deleting_last_node(){
        Node* node;
        res = insertNode(list,elementToinsertNode1,1);
        res = insertNode(list,elementToinsertNode2,2);
        node = removeNode(list,2);
        ASSERT(element2 == *(int*)node->data);
        ASSERT(element1 == *(int*)list->head->data);        
};


void test_deleting_node_from_middle(){
        Node* node;
        Node* secondNode;
        res = insertNode(list,elementToinsertNode1,1);
        res = insertNode(list,elementToinsertNode2,2);
        res = insertNode(list,elementToinsertNode3,3);
        node = removeNode(list,2);
        ASSERT(element2 == *(int*)node->data);
        ASSERT(element1 == *(int*)list->head->data);
        secondNode = list->head->next;
        ASSERT(element3 == *(int*)secondNode->data);
        ASSERT(element1 == *(int*)secondNode->previous->data);
};

void test_when_index_is_negative_node_should_not_be_insertNodeed(){
        res = insertNode(list,elementToinsertNode1,-1);
        ASSERT(0 == res);
};


void test_when_index_exceeds_lists_length_then_insertNodeion_should_fail(){
        res = insertNode(list,elementToinsertNode1,2);
        ASSERT(0 == res);
};

void test_deleting_the_String_node_when_only_one_node_is_present(){
        Node* node;
        String element  = "soumya";
        assignSpaceAndData(sizeof(String),&element);
        res = insertNode(list,elementToinsertNode,1);
        node = removeNode(list,1);
        ASSERT(0 == strcmp(element,node->data));
};
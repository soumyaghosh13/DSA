#include "linkedList.h"
#include <stdlib.h>


linkedList* createLinkedList() {
        linkedList* linkedList = calloc(1,sizeof(linkedList));
        linkedList->length = 0;
        linkedList->head = NULL;
        return linkedList;
};


int insertAtBeginning(Node* node,Node* nodeToInsert,linkedList* linkedList){
        nodeToInsert->next = node;
        node->previous = nodeToInsert;
        linkedList->head = nodeToInsert;
        return 1;
};

int insetAnyPlace(Node* node,Node* nodeToInsert,linkedList* linkedList){
        nodeToInsert->previous = node;
        nodeToInsert->next = node->next;
        node->next = nodeToInsert;
        if(nodeToInsert->next!=NULL)
                node->next->previous = nodeToInsert;
        return 1;
};

int insertNode(linkedList* linkedList,void* element,int index){
        int i;
        Node* nodeToInsert = calloc(1,sizeof(Node));
        Node* node = linkedList->head;
        Node* nextNode;
        nodeToInsert->data = element;
        if((index <= 0 )|| (index >(linkedList->length+1)))  return 0;
        linkedList->length++;
        if(linkedList->head == NULL){
                linkedList->head = nodeToInsert;
                return 1;
        }
        for(i=1;i<index-1;i++)
                node = node->next;
        if(index == 1)
                return insertAtBeginning(node,nodeToInsert,linkedList);
        return insetAnyPlace(node,nodeToInsert,linkedList);
};


Node* setLinkToNull(Node* node){
        node->previous = NULL;
        node->next = NULL;
        return node;
}


Node* removeNode(linkedList *linkedList, int index){
        int i;
        Node* nodeToDelete;
        Node* node;
        nodeToDelete = linkedList->head;
        for(i=1;i<index;i++)
                nodeToDelete = nodeToDelete->next;
        if(NULL == nodeToDelete->previous){
                linkedList->head = nodeToDelete->next;
                return setLinkToNull(nodeToDelete);
        }
        node = nodeToDelete->previous;
        node->next = nodeToDelete->next;
        if(node->next!=NULL)
                node->next->previous = node;
        return setLinkToNull(nodeToDelete);
};


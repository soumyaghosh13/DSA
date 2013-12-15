#include "LinkedList.h"
#include <stdlib.h>


LinkedList* createLinkedList() {
        LinkedList* LinkedList = calloc(1,sizeof(LinkedList));
        LinkedList->length = 0;
        LinkedList->head = NULL;
        return LinkedList;
};


int insertAtBeginning(Node* node, Node* nodeToInsert, LinkedList* LinkedList){
        nodeToInsert->next = node;
        node->previous = nodeToInsert;
        LinkedList->head = nodeToInsert;
        return 1;
};

int insetAnyPlace(Node* node, Node* nodeToInsert, LinkedList* LinkedList){
        nodeToInsert->previous = node;
        nodeToInsert->next = node->next;
        node->next = nodeToInsert;
        if(nodeToInsert->next!=NULL)
                node->next->previous = nodeToInsert;
        return 1;
};

int insertNode(LinkedList* LinkedList,void* element,int index){
        int i;
        Node* nodeToInsert = calloc(1,sizeof(Node));
        Node* node = LinkedList->head;
        Node* nextNode;
        nodeToInsert->data = element;
        if((index <= 0 )|| (index >(LinkedList->length+1)))  return 0;
        LinkedList->length++;
        if(LinkedList->head == NULL){
                LinkedList->head = nodeToInsert;
                return 1;
        }
        for(i=1;i<index-1;i++)
                node = node->next;
        if(index == 1)
                return insertAtBeginning(node,nodeToInsert,LinkedList);
        return insetAnyPlace(node,nodeToInsert,LinkedList);
};


Node* dispose(Node* node){
        node->previous = NULL;
        node->next = NULL;
        return node;
}


Node* removeNode(LinkedList *LinkedList, int index){
        int i;
        Node* nodeToDelete;
        Node* node;
        nodeToDelete = LinkedList->head;
        for(i=1;i<index;i++)
                nodeToDelete = nodeToDelete->next;
        if(NULL == nodeToDelete->previous){
                LinkedList->head = nodeToDelete->next;
                return dispose(nodeToDelete);
        }
        node = nodeToDelete->previous;
        node->next = nodeToDelete->next;
        if(node->next!=NULL)
                node->next->previous = node;
        return dispose(nodeToDelete);
};


#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

Stack* createStack(){
    Stack* stack  = create();
    return stack;
}
bool push(Stack* stack,void* element){
    return insertNode(stack , element, stack->length);
}
void* pop(Stack* stack){
    void* data = top(stack);
    deleteNode(stack, stack->length-1);
    return data;
}
void* top(Stack* stack){
    Node* node = stack->head;
    void *data;
    while(node->next != NULL) node = node->next;
    data = node->data;
    return data;
}

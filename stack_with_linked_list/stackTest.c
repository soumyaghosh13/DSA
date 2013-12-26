#include "testUtils.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_create_stack(){
    Stack* stack;
    stack = createStack();
    ASSERT(stack->head == NULL);         
    ASSERT(stack->length == 0);         
}

void test_push_integer_in_stack(){
    Stack* stack;
    int element = 100;
    int result;
    stack = createStack();
    push(stack , &element);
    result = (int)pop(stack);
    ASSERT(element==result); 
}

// void test_pop_int_from_stack(){
//     Stack* stack;
//     int data;
//     int element1 = 100,
//     	element2 = 250;
//     stack = createStack();
//     push(stack , &element1);
//     push(stack , &element2);
//     data =(int)pop(stack);         
//     ASSERT(stack->length == 1);         
//     ASSERT(*(int*)data == 250);         
// }
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
    stack = createStack();
    push(stack , &element);
    ASSERT(*(int*)stack->head->data == 100);         
    ASSERT(stack->length == 1);         
}

void test_push_string_in_stack(){
    Stack* stack;
    String element;
    strcpy(element , "sam");
    stack = createStack();
    push(stack , &element);
    ASSERT(!strcmp(*(String*)stack->head->data , "sam"));         
    ASSERT(stack->length == 1);         
}

void test_pop_int_from_stack(){
    Stack* stack;
    int data;
    int element1 = 100,
    	element2 = 250;
    stack = createStack();
    push(stack , &element1);
    push(stack , &element2);
    data =(int)pop(stack);         
    ASSERT(stack->length == 1);         
    ASSERT(*(int*)data == 250);         
}

void test_top_char_from_stack(){
    Stack* stack;
    char data;
    char element1 = 's',
    	element2 = 'g';
    stack = createStack();
    push(stack , &element1);
    push(stack , &element2);
    data =(char)top(stack);         
    ASSERT(*(char*)data == 'g');         
}
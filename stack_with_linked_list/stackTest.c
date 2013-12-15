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

void test_push_integer_element_at_start_of_stack(){
    Stack* stack;
    int element = 10;
    stack = createStack();
    push(stack , &element);
    ASSERT(*(int*)stack->head->data == 10);         
    ASSERT(stack->length == 1);         
}

void test_push_double_element_at_start_of_stack(){
    Stack* stack;
    double element = 10.0;
    stack = createStack();
    push(stack , &element);
    ASSERT(*(double*)stack->head->data == 10.0);         
    ASSERT(stack->length == 1);         
}

void test_push_character_element_at_start_of_stack(){
    Stack* stack;
    char element = 'a';
    stack = createStack();
    push(stack , &element);
    ASSERT(*(char*)stack->head->data == 'a');         
    ASSERT(stack->length == 1);         
}

void test_push_string_element_at_start_of_stack(){
    Stack* stack;
    String element;
    strcpy(element , "abc");
    stack = createStack();
    push(stack , &element);
    ASSERT(!strcmp(*(String*)stack->head->data , "abc"));         
    ASSERT(stack->length == 1);         
}

void test_pop_int_element_at_top_of_stack(){
    Stack* stack;
    int data;
    int element1 = 10,
    	element2 = 20;
    stack = createStack();
    push(stack , &element1);
    push(stack , &element2);
    data =(int)pop(stack);         
    ASSERT(stack->length == 1);         
    ASSERT(*(int*)data == 20);         
}

void test_pop_double_element_at_top_of_stack(){
    Stack* stack;
    int data;
    double element1 = 10.0,element2 = 20.0;
    stack = createStack();
    push(stack , &element1);
    push(stack , &element2);
    data =(int)pop(stack);         
    ASSERT(stack->length == 1);         
    ASSERT(*(double*)data == 20.0);         
}

void test_gives_the_topmost_int_element_at_top_of_stack(){
    Stack* stack;
    int data;
    int element1 = 10,
    	element2 = 20;
    stack = createStack();
    push(stack , &element1);
    push(stack , &element2);
    data =(int)top(stack);         
    ASSERT(*(int*)data == 20);         
}
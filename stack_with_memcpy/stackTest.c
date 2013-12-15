#include "testUtils.h"
#include "stack.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areEqual(Stack* src, Stack* expected){
	int res = (src->elementSize == expected->elementSize) 
				&& (src->size == expected->size)
				&& (src->top == expected->top);
	if(!res)
		return res;
	res = memcmp(src->elements,expected->elements,src->size*src->elementSize);
	return 0==res;
}

void test_to_create_int_Stack(){
	int expArr[2]={0,0};
	Stack expected = {expArr,-1,sizeof(int),2};
	Stack* stack=create(sizeof(int), 2);
	ASSERT(areEqual(stack, &expected));
	free(stack->elements);
	free(stack);
}

void test_to_create_String_Stack(){
	String expArr[2]={0,0};
	Stack expected = {expArr,-1,sizeof(String),2};
	Stack* stack=create(sizeof(String), 2);
	ASSERT(areEqual(stack, &expected));
	free(stack->elements);
	free(stack);
}

void test_to_push_into_int_Stack(){
	Stack* stack=create(sizeof(int), 2);
	int value=1;
	boolean result=push(stack,&value);
	int* data=stack->elements;
	ASSERT(data[0]==1);
	free(stack->elements);
	free(stack);
}

void test_to_push_into_string_Stack(){
	Stack* stack=create(sizeof(String), 2);
	String value="Soumya";
	boolean result=push(stack,&value);
	String* data=stack->elements;
	ASSERT(0==strcmp("Soumya",data[0]));
	free(stack->elements);
	free(stack);
}


void test_to_pop_an_element_from_an_int_stack(){
	Stack* stack = create(sizeof(int), 5);
	int* data = (int*)stack->elements;
	data[0]=111;
	data[1]=222;
	data[2]=333;
	data[3]=444;
	data[4]=555;
	stack->top=4;
	ASSERT(555==*(int*)pop(stack));
	ASSERT(3==stack->top);
	free(stack->elements);
	free(stack->elements);
	free(stack);
}

void test_to_pop_an_element_from_an_String_array(){
	Stack* stack = create(sizeof(String), 5);
	String* data=stack->elements;
	strcpy(data[0],"mohit");
	strcpy(data[1],"harjas");
	strcpy(data[2],"taj");
	strcpy(data[3],"sandesh");
	strcpy(data[4],"soumya");
	stack->top=4;
	ASSERT(0==strcmp("soumya",*(String*)pop(stack)));
	ASSERT(3==stack->top);
	free(stack->elements);
	free(stack);
}



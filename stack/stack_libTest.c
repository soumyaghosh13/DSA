#include "testUtils.h"
#include "stack_lib.h"
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

void _1_test_to_create_int_Stack(){
	int expArr[2]={0,0};
	Stack expected = {expArr,-1,sizeof(int),2};
	Stack* stack=create(sizeof(int), 2);
	ASSERT(areEqual(stack, &expected));
	free(stack->elements);
	free(stack);
}

void _2_test_to_create_float_Stack(){
	float expArr[2]={0.0f,0.0f};
	Stack expected = {expArr,-1,sizeof(float),2};
	Stack* stack=create(sizeof(float), 2);
	ASSERT(areEqual(stack, &expected));
	free(stack->elements);
	free(stack);
}

void _3_test_to_create_char_Stack(){
	char expArr[2]={0,0};
	Stack expected = {expArr,-1,sizeof(char),2};
	Stack* stack=create(sizeof(char), 2);
	ASSERT(areEqual(stack, &expected));
	free(stack->elements);
	free(stack);
}

void _4_test_to_create_double_Stack(){
	double expArr[2]={0,0};
	Stack expected = {expArr,-1,sizeof(double),2};
	Stack* stack=create(sizeof(double), 2);
	ASSERT(areEqual(stack, &expected));
	free(stack->elements);
	free(stack);
}

void _5_test_to_create_String_Stack(){
	String expArr[2]={0,0};
	Stack expected = {expArr,-1,sizeof(String),2};
	Stack* stack=create(sizeof(String), 2);
	ASSERT(areEqual(stack, &expected));
	free(stack->elements);
	free(stack);
}

void _6_test_to_push_1_into_Stack(){
	Stack* stack=create(sizeof(int), 2);
	int value=1;
	boolean result=push(stack,&value);
	int* data=stack->elements;
	ASSERT(data[0]==1);
	free(stack->elements);
	free(stack);
}

void _7_test_to_push_one_point_four_point_5_into_float_Stack(){
	Stack* stack=create(sizeof(float), 2);
	float value=1.4f;
	boolean result=push(stack,&value);
	float* data=stack->elements;
	ASSERT(data[0]==1.4f);
	free(stack->elements);
	free(stack);
}

void _8_test_to_push_one_point_two_five_six_point_5_into_double_Stack(){
	Stack* stack=create(sizeof(double), 2);
	double value=1.256;
	boolean result=push(stack,&value);
	double* data=stack->elements;
	ASSERT(data[0]==1.256);
	free(stack->elements);
	free(stack);
}

void _9_test_to_push_character_a_into_char_Stack(){
	Stack* stack=create(sizeof(char), 2);
	char value='a';
	boolean result=push(stack,&value);
	char* data=stack->elements;
	ASSERT(data[0]=='a');
	free(stack->elements);
	free(stack);
}

void _10_test_to_push_String_a_into_char_Stack(){
	Stack* stack=create(sizeof(String), 2);
	String value="Prateek";
	boolean result=push(stack,&value);
	String* data=stack->elements;
	ASSERT(0==strcmp("Prateek",data[0]));
	free(stack->elements);
	free(stack);
}


void _11_test_to_pop_an_element_from_an_int_array(){
	Stack* stack = create(sizeof(int), 5);
	int* data = (int*)stack->elements;
	data[0]=1;
	data[1]=2;
	data[2]=3;
	data[3]=4;
	data[4]=5;
	stack->top=4;
	ASSERT(5==*(int*)pop(stack));
	ASSERT(3==stack->top);
	free(stack->elements);
	free(stack->elements);
	free(stack);
}

void _12_test_to_pop_an_element_from_an_float_array(){
	Stack* stack = create(sizeof(float), 5);
	float* data=stack->elements;
	data[0]=1.2f;
	data[1]=2.2f;
	data[2]=3.2f;
	data[3]=4.2f;
	data[4]=5.2f;
	stack->top=4;
	ASSERT(5.2f==*(float*)pop(stack));
	ASSERT(3==stack->top);
	free(stack->elements);
	free(stack);
}

void _13_test_to_pop_an_element_from_an_char_array(){
	Stack* stack = create(sizeof(char), 5);
	char* data=stack->elements;
	data[0]='a';
	data[1]='b';
	data[2]='c';
	data[3]='d';
	data[4]='e';
	stack->top=4;
	ASSERT('e'==*(char*)pop(stack));
	ASSERT(3==stack->top);
	free(stack->elements);
	free(stack);
}


void _14_test_to_pop_an_element_from_an_String_array(){
	Stack* stack = create(sizeof(String), 5);
	String* data=stack->elements;
	strcpy(data[0],"abc");
	strcpy(data[1],"def");
	strcpy(data[2],"ghi");
	strcpy(data[3],"jkl");
	strcpy(data[4],"mno");
	stack->top=4;
	ASSERT(0==strcmp("mno",*(String*)pop(stack)));
	ASSERT(3==stack->top);
	free(stack->elements);
	free(stack);
}

void _15_test_to_pop_an_element_from_double_array(){
	double _4_nums[4] = {12.0,14.0,45.0,12.0};
    double result;
    Stack* stack = create(sizeof(double),4);
    memcpy(stack->elements,_4_nums,4*sizeof(double));
    stack->top = 3;
    result = *(double*)(pop(stack));
    ASSERT(12.0==result);
    ASSERT(2==stack->top);
}


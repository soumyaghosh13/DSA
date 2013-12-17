#include "testUtils.h"
#include "stack.h"
#include "memory.h"


//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Stack* stack;

int areEqual(Stack expected, Stack actual){
    int result = expected.length == actual.length && expected.top == actual.top && 
                                    expected.elementSize == actual.elementSize;
    if(!result) return result;
    return 0 == memcmp(expected.base,actual.base,expected.length*expected.elementSize);
}

void test_create_a_stack_int(){
    int a[3] = {0,0,0};
           Stack expected = {a,3,0,sizeof(int)};
    stack = create(3, sizeof(int));
    ASSERT(areEqual(expected, *stack));
};

void test_creates_a_stack_for_string(){
        String name[3] = {"","",""};
        Stack expected = {name,3,0,sizeof(String)};
        stack = create(3, sizeof(String));
        ASSERT(areEqual(expected, *stack));
};

void test_push_int_into_stack (){
        bool res;
    int newElement = 3;
    stack = create(3,sizeof(int));
        res = push(stack, &newElement);
        ASSERT(res == true);
        ASSERT(stack -> top == 1);
        ASSERT(*(int*)stack -> base == 3);
};

void test_no_limit_of_push_element(){
        int nums[2] = {23,15};
        int element = 12;
        int result;
        stack = create(2, sizeof(int));
        memcpy(stack->base, nums, sizeof(nums));
        stack->top = 2;
        result = push(stack, &element);
        ASSERT(1==result);
        ASSERT(3 == stack->top && 4 == stack->length);
        ASSERT(12 == *(int*)(stack->base + 2*sizeof(int)));
}

void test_pop_element_from_stack(){
        int a[4] = {1,2,3,4};
        int result;
        stack = create(4, sizeof(int));
        memcpy(stack->base,a,4*sizeof(int));
        stack->top = 4;
        result = *(int*)(pop(stack));
        ASSERT(4 == result);
};

void test_pop_element_from_empty_stack_gives_null(){
        int a[4] = {};
        void* result;
        stack = create(4, sizeof(int));
        memcpy(stack->base,a,4*sizeof(int));
        stack->top = 0;
        result = (pop(stack));
        ASSERT(NULL == result);
};

void test_peek_gives_the_top_element_of_int_stack(){
        int result;
        int nums[3] = {10,20,30};
        stack = create(5, sizeof(int));
        stack->top = 3;
        memcpy(stack->base,nums, 3*stack->elementSize);
        result = *(int*)peek(stack);
        ASSERT(30==result);
        ASSERT(3==stack->top);
};

void test_peek_gives_top_element_of_String_stack(){
        char* result;
        String fruits[3] = {"Sandesh","mohit","soumya"};
        String expected = "soumya";
        stack = create(5, sizeof(String));
        stack->top = 3;
        memcpy(stack->base, fruits, 3*stack->elementSize);
        result = (char*)peek(stack);
        ASSERT(0==strcmp(expected, result));
        ASSERT(3==stack->top);
};

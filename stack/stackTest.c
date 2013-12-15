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
//----------------------create---------------------------
void test_creates_a_stack_for_integer_elements (){
    int a[3] = {0,0,0};
           Stack expected = {a,3,0,sizeof(int)};
    stack = create(3, sizeof(int));
    ASSERT(areEqual(expected, *stack));
};
void test_creates_a_stack_for_float_elements (){
    float a[3] = {0,0,0};
           Stack expected = {a,3,0,sizeof(float)};
    stack = create(3, sizeof(float));
    ASSERT(areEqual(expected, *stack));
};
void test_creates_a_stack_for_String_elements (){
        String name[3] = {"","",""};
        Stack expected = {name,3,0,sizeof(String)};
        stack = create(3, sizeof(String));
        ASSERT(areEqual(expected, *stack));
};


//---------------------push----------------------------------
void test_push_new_element_in_integer_stack (){
        bool res;
    int newElement = 3;
    stack = create(3,sizeof(int));
        res = push(stack, &newElement);
        ASSERT(res == true);
        ASSERT(stack -> top == 1);
        ASSERT(*(int*)stack -> base == 3);
};




void test_increment_of_the_length_of_stack_if_stack_is_full(){
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
void test_adds_the_given_Strings_at_the_top_of_the_stack(){
        String names[2] = {"tannu","tanu"};
        String nname = "tannu";
        String name = "tanu";
        Stack expected = {names,2,2,sizeof(String)};
        stack = create(2, sizeof(String));
        push(stack, nname);
        push(stack, name);
        ASSERT(areEqual(expected, *stack));
}
//--------------------------------pop---------------------------------------------
void test_7_pop_the_top_most_element_of_stack(){
        int a[4] = {1,2,3,4};
        int result;
        stack = create(4, sizeof(int));
        memcpy(stack->base,a,4*sizeof(int));
        stack->top = 4;
        result = *(int*)(pop(stack));
        ASSERT(4 == result);
};
void test_8_pop_the_element_of_empty_stack(){
        int a[4] = {};
        void* result;
        stack = create(4, sizeof(int));
        memcpy(stack->base,a,4*sizeof(int));
        stack->top = 0;
        result = (pop(stack));
        ASSERT(NULL == result);
};
void test_9_pop_the_element_from_a_string_stack(){
        String chars[4] = {"banana","mango","mango","apple"};
        char* result;
        String expected = "apple";
        stack = create(4, sizeof(String));
        memcpy(stack->base,chars,4*sizeof(String));
        stack->top = 4;
        result = (char*)(pop(stack));
        ASSERT(0==strcmp(result, expected));
        ASSERT(3==stack->top);
};
//------------------------------peek---------------------------------------
void test_10_gives_the_top_most_element_of_stack(){
        int result;
        int nums[3] = {10,20,30};
        stack = create(5, sizeof(int));
        stack->top = 3;
        memcpy(stack->base,nums, 3*stack->elementSize);
        result = *(int*)peek(stack);
        ASSERT(30==result);
        ASSERT(3==stack->top);
};
void test_11_gives_the_top_most_element_of_stack_String(){
        char* result;
        String fruits[3] = {"apple","mango","orange"};
        String expected = "orange";
        stack = create(5, sizeof(String));
        stack->top = 3;
        memcpy(stack->base, fruits, 3*stack->elementSize);
        result = (char*)peek(stack);
        ASSERT(0==strcmp(expected, result));
        ASSERT(3==stack->top);
};
//---------------------------isEmpty---------------------------------------------
void test_12_the_stack_is_empty(){
        int result;
        stack = create(5, sizeof(int));
        result = isEmpty(stack);
        ASSERT(1==result);
}
void test_13_the_string_stack_is_empty(){
        int result;
        stack = create(5, sizeof(String));
        result = isEmpty(stack);
        ASSERT(1==result);
}
void test_14_the_stack_is_not_empty(){
        int result;
        stack = create(5, sizeof(int));
        *(int*)stack->base = 15;
        stack->top = 1;
        result = isEmpty(stack);
        ASSERT(0==result);
}


//--------------------------------isFull------------------------


void test_15_the_stack_is_full(){
    int result;
    stack = create(1, sizeof(int));
    *(int*)stack->base = 15;
    stack->top = 1;
    result = isFull(stack);
    ASSERT(1==result);
}




void test_16_the_string_stack_is_full (){
        int result;
        stack = create(1, sizeof(String));
        strcpy(stack->base, "tanbir");
        stack->top = 1;
        result = isFull(stack);
        ASSERT(1==result);
}


void test_17_the_stack_is_not_full(){
        int result;
        stack = create(4, sizeof(String));
        strcpy(stack->base, "tanbir");
        stack->top = 1;
        result = isFull(stack);
        ASSERT(0==result);
}

#include "testUtils.h"
#include "matchBracket.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


void test_first_brackets_of_input_string_match(){
        char* input = "()";
        int result;
        result = isBracketMatching(input);
        ASSERT(1 == result);
};

void test_second_brackets_of_input_string_match(){
        char* input = "{}";
        int result;
        result = isBracketMatching(input);
        ASSERT(1 == result);
};

void test_third_brackets_of_input_string_match(){
        char* input = "[]";
        int result;
        result = isBracketMatching(input);
        ASSERT(1 == result);
};

void test_combination_of_second_and_first_bracket_of_input_string_match(){
        char* input = "{()}";
        int result;
        result = isBracketMatching(input);
        ASSERT(1 == result);
};

void test_combination_of_third_second_and_first_bracket_of_input_string_match(){
        char* input = "[{()}]";
        int result;
        result = isBracketMatching(input);
        ASSERT(1 == result);
};

void test_return_zero_if_bracket_of_given_equation_are_not_matched(){
        char* input = "[{(";
        int result;
        result = isBracketMatching(input);
        ASSERT(0 == result);
};

void test_return_zero_if_brackets_are_not_in_order(){
		char* input = "]})({[";
        int result;
        result = isBracketMatching(input);
        ASSERT(0 == result);	
}

void test_2return_zero_if_brackets_are_not_in_order(){
                char* input = "{[[{{}]}";
        int result;
        result = isBracketMatching(input);
        ASSERT(0 == result);    
}


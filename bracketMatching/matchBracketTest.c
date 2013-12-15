#include "testUtils.h"
#include "matchBracket.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


void test_1_matchs_all_brackets_of_input_string(){
        char* input = "[{(sam)mas}]";
        int result;
        result = startMatching(input);
        ASSERT(1 == result);
};
void test_2_matchs_all_brackets_of_input_string(){
        char* input = "[{(soumya}]";
        int result;
        result = startMatching(input);
        ASSERT(0 == result);
};



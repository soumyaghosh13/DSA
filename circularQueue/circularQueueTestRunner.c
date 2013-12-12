int testCount=-1;
int passCount=0;
void setup();
void tearDown();


void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;


void testStarted(char* name){
        incrementTestCount();
        currentTestFailed=0;
        printf("\t%s\n",name);
}


void testEnded(){
        if(!currentTestFailed)
                incrementPassCount();
}


void resetTestCount(){
        testCount=0;
        passCount=0;
        printf("********* Starting tests\n\n");
}
void summarizeTestCount(){
        printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}


void incrementTestCount(){
        testCount++;
}


void incrementPassCount(){
        passCount++;
}


void testFailed(const char* fileName, int lineNumber, char* expression){
        currentTestFailed = 1;
        printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}


int main(){
        fixtureSetup();
        resetTestCount();


        testStarted("test_create_queue_allocates_memory_for_five_int_elements");
        setup();
                test_create_queue_allocates_memory_for_five_int_elements();
        tearDown();
        testEnded();
        testStarted("test_create_queue_allocates_memory_for_five_float_elements");
        setup();
                test_create_queue_allocates_memory_for_five_float_elements();
        tearDown();
        testEnded();
        testStarted("test_create_queue_allocates_memory_for_five_char_strings");
        setup();
                test_create_queue_allocates_memory_for_five_char_strings();
        tearDown();
        testEnded();
        testStarted("test_create_queue_allocates_memory_for_five_characters");
        setup();
                test_create_queue_allocates_memory_for_five_characters();
        tearDown();
        testEnded();
        testStarted("test_enqueue_char_element_at_rear_of_queue");
        setup();
                test_enqueue_char_element_at_rear_of_queue();
        tearDown();
        testEnded();
        testStarted("test_enqueue_char_element_at_rear_of_queue_rear_is_at_middle");
        setup();
                test_enqueue_char_element_at_rear_of_queue_rear_is_at_middle();
        tearDown();
        testEnded();
        testStarted("test_enqueue_char_element_at_rear_of_queue_rear_is_at_middle1");
        setup();
                test_enqueue_char_element_at_rear_of_queue_rear_is_at_middle1();
        tearDown();
        testEnded();
        testStarted("test_enqueue_char_element_return_false_when_queue_is_full");
        setup();
                test_enqueue_char_element_return_false_when_queue_is_full();
        tearDown();
        testEnded();
        testStarted("test_enqueue_int_element_at_rear_of_queue");
        setup();
                test_enqueue_int_element_at_rear_of_queue();
        tearDown();
        testEnded();
        testStarted("test_enqueue_float_element_at_rear_of_queue");
        setup();
                test_enqueue_float_element_at_rear_of_queue();
        tearDown();
        testEnded();
        testStarted("test_enqueue_string_element_at_rear_of_queue");
        setup();
                test_enqueue_string_element_at_rear_of_queue();
        tearDown();
        testEnded();
        testStarted("test_enqueue_int_element_at_rear_of_queue_rear_is_at_middle");
        setup();
                test_enqueue_int_element_at_rear_of_queue_rear_is_at_middle();
        tearDown();
        testEnded();
        testStarted("test_enqueue_int_element_at_rear_of_queue_rear_is_at_middle1");
        setup();
                test_enqueue_int_element_at_rear_of_queue_rear_is_at_middle1();
        tearDown();
        testEnded();
        testStarted("test_enqueue_int_element_return_false_when_queue_is_full");
        setup();
                test_enqueue_int_element_return_false_when_queue_is_full();
        tearDown();
        testEnded();
        testStarted("test_enqueue_int_element_return_false_when_queue_is_full1");
        setup();
                test_enqueue_int_element_return_false_when_queue_is_full1();
        tearDown();
        testEnded();
        testStarted("test_enqueue_float_element_at_rear_of_queue_rear_is_at_middle");
        setup();
                test_enqueue_float_element_at_rear_of_queue_rear_is_at_middle();
        tearDown();
        testEnded();
        testStarted("test_enqueue_float_element_at_rear_of_queue_rear_is_at_middle1");
        setup();
                test_enqueue_float_element_at_rear_of_queue_rear_is_at_middle1();
        tearDown();
        testEnded();
        testStarted("test_enqueue_float_element_return_false_when_queue_is_full");
        setup();
                test_enqueue_float_element_return_false_when_queue_is_full();
        tearDown();
        testEnded();
        testStarted("test_enqueue_float_element_return_false_when_queue_is_full1");
        setup();
                test_enqueue_float_element_return_false_when_queue_is_full1();
        tearDown();
        testEnded();
        testStarted("test_enqueue_string_element_at_rear_of_queue_rear_is_at_middle");
        setup();
                test_enqueue_string_element_at_rear_of_queue_rear_is_at_middle();
        tearDown();
        testEnded();
        testStarted("test_enqueue_string_element_at_rear_of_queue_rear_is_at_middle1");
        setup();
                test_enqueue_string_element_at_rear_of_queue_rear_is_at_middle1();
        tearDown();
        testEnded();
        testStarted("test_enqueue_string_element_return_false_when_queue_is_full");
        setup();
                test_enqueue_string_element_return_false_when_queue_is_full();
        tearDown();
        testEnded();
        testStarted("test_enqueue_string_element_return_false_when_queue_is_full1");
        setup();
                test_enqueue_string_element_return_false_when_queue_is_full1();
        tearDown();
        testEnded();
        testStarted("test_dequeue_int_element_at_front_of_queue");
        setup();
                test_dequeue_int_element_at_front_of_queue();
        tearDown();
        testEnded();
        testStarted("test_dequeue_float_element_at_front_of_queue");
        setup();
                test_dequeue_float_element_at_front_of_queue();
        tearDown();
        testEnded();
        testStarted("test_dequeue_string_element_at_front_of_queue");
        setup();
                test_dequeue_string_element_at_front_of_queue();
        tearDown();
        testEnded();


        summarizeTestCount();
        fixtureTearDown();
        return 0;
}


void setup(){}


void tearDown(){}


void fixtureSetup(){}


void fixtureTearDown(){}

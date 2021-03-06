#include <stdio.h>

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

	testStarted("test_create_a_stack_int");
	setup();
		test_create_a_stack_int();
	tearDown();
	testEnded();
	testStarted("test_creates_a_stack_for_string");
	setup();
		test_creates_a_stack_for_string();
	tearDown();
	testEnded();
	testStarted("test_push_int_into_stack");
	setup();
		test_push_int_into_stack();
	tearDown();
	testEnded();
	testStarted("test_no_limit_of_push_element");
	setup();
		test_no_limit_of_push_element();
	tearDown();
	testEnded();
	testStarted("test_pop_element_from_stack");
	setup();
		test_pop_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_element_from_empty_stack_gives_null");
	setup();
		test_pop_element_from_empty_stack_gives_null();
	tearDown();
	testEnded();
	testStarted("test_peek_gives_the_top_element_of_int_stack");
	setup();
		test_peek_gives_the_top_element_of_int_stack();
	tearDown();
	testEnded();
	testStarted("test_peek_gives_top_element_of_String_stack");
	setup();
		test_peek_gives_top_element_of_String_stack();
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

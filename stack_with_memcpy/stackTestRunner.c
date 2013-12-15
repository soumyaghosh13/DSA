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

	testStarted("test_to_create_int_Stack");
	setup();
		test_to_create_int_Stack();
	tearDown();
	testEnded();
	testStarted("test_to_create_String_Stack");
	setup();
		test_to_create_String_Stack();
	tearDown();
	testEnded();
	testStarted("test_to_push_into_int_Stack");
	setup();
		test_to_push_into_int_Stack();
	tearDown();
	testEnded();
	testStarted("test_to_push_into_string_Stack");
	setup();
		test_to_push_into_string_Stack();
	tearDown();
	testEnded();
	testStarted("test_to_pop_an_element_from_an_int_stack");
	setup();
		test_to_pop_an_element_from_an_int_stack();
	tearDown();
	testEnded();
	testStarted("test_to_pop_an_element_from_an_String_array");
	setup();
		test_to_pop_an_element_from_an_String_array();
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

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

	testStarted("test_insert_element");
	setup();
		test_insert_element();
	tearDown();
	testEnded();
	testStarted("test_insert_multiple_elements");
	setup();
		test_insert_multiple_elements();
	tearDown();
	testEnded();
	testStarted("test_insert_element_increase_capacity");
	setup();
		test_insert_element_increase_capacity();
	tearDown();
	testEnded();
	testStarted("test_insert_should_fail_beyond_if_insert_length");
	setup();
		test_insert_should_fail_beyond_if_insert_length();
	tearDown();
	testEnded();
	testStarted("test_insert_should_fail_if_insert_at_negative_index");
	setup();
		test_insert_should_fail_if_insert_at_negative_index();
	tearDown();
	testEnded();
	testStarted("test_insert_at_middle_should_shift_the_elements");
	setup();
		test_insert_at_middle_should_shift_the_elements();
	tearDown();
	testEnded();
	testStarted("test_remove_single_element");
	setup();
		test_remove_single_element();
	tearDown();
	testEnded();
	testStarted("test_removing_element_from_last");
	setup();
		test_removing_element_from_last();
	tearDown();
	testEnded();
	testStarted("test_remove_element_from_between");
	setup();
		test_remove_element_from_between();
	tearDown();
	testEnded();
	testStarted("test_removing_element_beyond_capacity_should_fail");
	setup();
		test_removing_element_beyond_capacity_should_fail();
	tearDown();
	testEnded();
	testStarted("test_removing_non_existing_element_should_fail");
	setup();
		test_removing_non_existing_element_should_fail();
	tearDown();
	testEnded();
	testStarted("test_searching_element");
	setup();
		test_searching_element();
	tearDown();
	testEnded();
	testStarted("test_searching_non_existing_element_gives_0");
	setup();
		test_searching_non_existing_element_gives_0();
	tearDown();
	testEnded();
	testStarted("test_getting_next_element_through_iterator");
	setup();
		test_getting_next_element_through_iterator();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}

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

	testStarted("test_put_first_element_in_list");
	setup();
		test_put_first_element_in_list();
	tearDown();
	testEnded();
	testStarted("test_put_multiple_elements");
	setup();
		test_put_multiple_elements();
	tearDown();
	testEnded();
	testStarted("test_same_key_should_update_value");
	setup();
		test_same_key_should_update_value();
	tearDown();
	testEnded();
	testStarted("test_put_should_fail_when_key_is_null");
	setup();
		test_put_should_fail_when_key_is_null();
	tearDown();
	testEnded();
	testStarted("test_get_null_when_element_is_absent");
	setup();
		test_get_null_when_element_is_absent();
	tearDown();
	testEnded();
	testStarted("test_get_element_should_fail_when_key_is_null");
	setup();
		test_get_element_should_fail_when_key_is_null();
	tearDown();
	testEnded();
	testStarted("test_deleting_element_having_specific_key");
	setup();
		test_deleting_element_having_specific_key();
	tearDown();
	testEnded();
	testStarted("test_deleting_element_when_absent");
	setup();
		test_deleting_element_when_absent();
	tearDown();
	testEnded();
	testStarted("test_deleting_when_key_is_null_should_fail");
	setup();
		test_deleting_when_key_is_null_should_fail();
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

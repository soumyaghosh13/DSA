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

	testStarted("test_inserts_an_Integer_element_in_queue");
	setup();
		test_inserts_an_Integer_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_inserts_String_at_rear_of_queue");
	setup();
		test_inserts_String_at_rear_of_queue();
	tearDown();
	testEnded();
	testStarted("test_enQueue_returns_one_for_sucessful_insert");
	setup();
		test_enQueue_returns_one_for_sucessful_insert();
	tearDown();
	testEnded();
	testStarted("test_enQueue_returns_zero_trying_ti_insert_in_full_queue");
	setup();
		test_enQueue_returns_zero_trying_ti_insert_in_full_queue();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void fixtureSetup(){}

void fixtureTearDown(){}

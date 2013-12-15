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

	testStarted("test_creates_a_queue_of_integers");
	setup();
		test_creates_a_queue_of_integers();
	tearDown();
	testEnded();
	testStarted("test_creates_a_queue_of_strings");
	setup();
		test_creates_a_queue_of_strings();
	tearDown();
	testEnded();
	testStarted("test_inserts_integer_element_in_queue");
	setup();
		test_inserts_integer_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_inserts_String_elements_in_queue_at_end");
	setup();
		test_inserts_String_elements_in_queue_at_end();
	tearDown();
	testEnded();
	testStarted("test_enqueue_in_full_queue_return_zero");
	setup();
		test_enqueue_in_full_queue_return_zero();
	tearDown();
	testEnded();
	testStarted("test_successful_enqueue_return_one");
	setup();
		test_successful_enqueue_return_one();
	tearDown();
	testEnded();
	testStarted("test_dequeues_from_integer_queue");
	setup();
		test_dequeues_from_integer_queue();
	tearDown();
	testEnded();
	testStarted("test_dequeues_the_first_element_of_queue_of_strings");
	setup();
		test_dequeues_the_first_element_of_queue_of_strings();
	tearDown();
	testEnded();
	testStarted("test_dequeue_from_empty_queue_return_zero");
	setup();
		test_dequeue_from_empty_queue_return_zero();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void fixtureSetup(){}

void fixtureTearDown(){}

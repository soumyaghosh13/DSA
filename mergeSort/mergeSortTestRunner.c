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

	testStarted("test_single_element_is_always_sorted");
	setup();
		test_single_element_is_always_sorted();
	tearDown();
	testEnded();
	testStarted("test_sort_for_even_number_of_element_best_case");
	setup();
		test_sort_for_even_number_of_element_best_case();
	tearDown();
	testEnded();
	testStarted("test_sort_for_odd_number_of_element_worst_case");
	setup();
		test_sort_for_odd_number_of_element_worst_case();
	tearDown();
	testEnded();
	testStarted("test_to_sort_char_data");
	setup();
		test_to_sort_char_data();
	tearDown();
	testEnded();
	testStarted("test_to_sort_Student_data");
	setup();
		test_to_sort_Student_data();
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

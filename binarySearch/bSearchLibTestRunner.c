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

	testStarted("test_to_search_an_element_in_an_integer_array_when_element_is_present");
	setup();
		test_to_search_an_element_in_an_integer_array_when_element_is_present();
	tearDown();
	testEnded();
	testStarted("test_to_search_an_element_in_an_integer_array_when_element_is_not_present");
	setup();
		test_to_search_an_element_in_an_integer_array_when_element_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_to_search_an_element_in_a_character_array_when_element_is_present");
	setup();
		test_to_search_an_element_in_a_character_array_when_element_is_present();
	tearDown();
	testEnded();
	testStarted("test_to_search_an_element_in_a_character_array_when_element_is_not_present");
	setup();
		test_to_search_an_element_in_a_character_array_when_element_is_not_present();
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

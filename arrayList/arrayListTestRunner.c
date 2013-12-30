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
	testStarted("test_insert_grows_beyond_capacity");
	setup();
		test_insert_grows_beyond_capacity();
	tearDown();
	testEnded();
	testStarted("test_insert_beyond_length_should_failed");
	setup();
		test_insert_beyond_length_should_failed();
	tearDown();
	testEnded();
	testStarted("test_insert_at_negetive_index_should_failed");
	setup();
		test_insert_at_negetive_index_should_failed();
	tearDown();
	testEnded();
	testStarted("test_insert_at_middle_should_shift_the_elements");
	setup();
		test_insert_at_middle_should_shift_the_elements();
	tearDown();
	testEnded();
	testStarted("test_deletes_from_list");
	setup();
		test_deletes_from_list();
	tearDown();
	testEnded();
	testStarted("test_delete_from_middle_should_shifts_element");
	setup();
		test_delete_from_middle_should_shifts_element();
	tearDown();
	testEnded();
	testStarted("test_iterator_should_give_1_if_next_data_is_present");
	setup();
		test_iterator_should_give_1_if_next_data_is_present();
	tearDown();
	testEnded();
	testStarted("test_iterator_should_give_0_if_next_data_is_not_present");
	setup();
		test_iterator_should_give_0_if_next_data_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_iterator_gives_the_data_of_next_index");
	setup();
		test_iterator_gives_the_data_of_next_index();
	tearDown();
	testEnded();
	testStarted("test_search_should_tell_the_index");
	setup();
		test_search_should_tell_the_index();
	tearDown();
	testEnded();
	testStarted("test_search_should_gives_minus_one_when_data_is_not_present");
	setup();
		test_search_should_gives_minus_one_when_data_is_not_present();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}

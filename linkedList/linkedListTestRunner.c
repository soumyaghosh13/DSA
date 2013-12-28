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

	testStarted("test_inserting_first_node");
	setup();
		test_inserting_first_node();
	tearDown();
	testEnded();
	testStarted("test_insert_first_node_string");
	setup();
		test_insert_first_node_string();
	tearDown();
	testEnded();
	testStarted("test_insert_two_elements_in_linked_list");
	setup();
		test_insert_two_elements_in_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_element_in_middle");
	setup();
		test_insert_element_in_middle();
	tearDown();
	testEnded();
	testStarted("test_insert_at_first_position_in_list");
	setup();
		test_insert_at_first_position_in_list();
	tearDown();
	testEnded();
	testStarted("test_when_index_is_negative_node_should_not_be_inserted");
	setup();
		test_when_index_is_negative_node_should_not_be_inserted();
	tearDown();
	testEnded();
	testStarted("test_when_index_exceeds_lists_length_then_insertion_should_fail");
	setup();
		test_when_index_exceeds_lists_length_then_insertion_should_fail();
	tearDown();
	testEnded();
	testStarted("test_deleting_the_char_node_when_only_one_is_present");
	setup();
		test_deleting_the_char_node_when_only_one_is_present();
	tearDown();
	testEnded();
	testStarted("test_deleting_all_nodes");
	setup();
		test_deleting_all_nodes();
	tearDown();
	testEnded();
	testStarted("test_deleting_node_in_middle");
	setup();
		test_deleting_node_in_middle();
	tearDown();
	testEnded();
	testStarted("test_deleting_from_empty_list");
	setup();
		test_deleting_from_empty_list();
	tearDown();
	testEnded();
	testStarted("test_when_negative_index_is_given_to_delete");
	setup();
		test_when_negative_index_is_given_to_delete();
	tearDown();
	testEnded();
	testStarted("test_iterator");
	setup();
		test_iterator();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}

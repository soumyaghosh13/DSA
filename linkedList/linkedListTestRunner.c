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

	testStarted("test_creation_of_linked_list");
	setup();
		test_creation_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insertNodeing_first_integer_node_in_linked_list");
	setup();
		test_insertNodeing_first_integer_node_in_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insertNodeing_first_String_node_in_linked_list");
	setup();
		test_insertNodeing_first_String_node_in_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insertNode_element_in_middle");
	setup();
		test_insertNode_element_in_middle();
	tearDown();
	testEnded();
	testStarted("test_insertNode_at_first_position_in_list");
	setup();
		test_insertNode_at_first_position_in_list();
	tearDown();
	testEnded();
	testStarted("test_deleting_first_node");
	setup();
		test_deleting_first_node();
	tearDown();
	testEnded();
	testStarted("test_deleting_last_node");
	setup();
		test_deleting_last_node();
	tearDown();
	testEnded();
	testStarted("test_deleting_node_from_middle");
	setup();
		test_deleting_node_from_middle();
	tearDown();
	testEnded();
	testStarted("test_when_index_is_negative_node_should_not_be_insertNodeed");
	setup();
		test_when_index_is_negative_node_should_not_be_insertNodeed();
	tearDown();
	testEnded();
	testStarted("test_when_index_exceeds_lists_length_then_insertNodeion_should_fail");
	setup();
		test_when_index_exceeds_lists_length_then_insertNodeion_should_fail();
	tearDown();
	testEnded();
	testStarted("test_deleting_the_String_node_when_only_one_node_is_present");
	setup();
		test_deleting_the_String_node_when_only_one_node_is_present();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}

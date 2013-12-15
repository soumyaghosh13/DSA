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
	testStarted("test_insert_Node_at_first_position_in_list");
	setup();
		test_insert_Node_at_first_position_in_list();
	tearDown();
	testEnded();
	testStarted("test_insert_Node_in_middle_of_linked_list");
	setup();
		test_insert_Node_in_middle_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_for_negetive_index_insertion_should_failed");
	setup();
		test_for_negetive_index_insertion_should_failed();
	tearDown();
	testEnded();
	testStarted("test_delete_first_node_of_linked_list");
	setup();
		test_delete_first_node_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_delete_last_node_of_linked_list");
	setup();
		test_delete_last_node_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_delete_any_node_of_linked_list");
	setup();
		test_delete_any_node_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_delete_node_when_linked_list_contain_one_node");
	setup();
		test_delete_node_when_linked_list_contain_one_node();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}

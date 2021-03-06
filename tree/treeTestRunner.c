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

	testStarted("test_create_root_node_in_tree");
	setup();
		test_create_root_node_in_tree();
	tearDown();
	testEnded();
	testStarted("test_insert_first_node_as_child_of_root");
	setup();
		test_insert_first_node_as_child_of_root();
	tearDown();
	testEnded();
	testStarted("test_insert_node_in_2_level_below_root");
	setup();
		test_insert_node_in_2_level_below_root();
	tearDown();
	testEnded();
	testStarted("test_search_for_root_node");
	setup();
		test_search_for_root_node();
	tearDown();
	testEnded();
	testStarted("test_search_for_child_of_root");
	setup();
		test_search_for_child_of_root();
	tearDown();
	testEnded();
	testStarted("test_search_two_level_below_root");
	setup();
		test_search_two_level_below_root();
	tearDown();
	testEnded();
	testStarted("test_removing_leaf_node");
	setup();
		test_removing_leaf_node();
	tearDown();
	testEnded();
	testStarted("test_removing_node_with_childs_should_fail");
	setup();
		test_removing_node_with_childs_should_fail();
	tearDown();
	testEnded();
	testStarted("test_remove_root_node");
	setup();
		test_remove_root_node();
	tearDown();
	testEnded();
	testStarted("test_remove_absent_node_should_fail");
	setup();
		test_remove_absent_node_should_fail();
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

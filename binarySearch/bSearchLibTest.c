#include "testUtils.h"
#include "bSearchLib.h"
#include <stdlib.h>
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


int compareInt(void* key,void* element){
	return ( *(int*)key -  *(int*)element );
}

int compareString(void* key,void* element){
	return strcmp( *(String*)key, *(String*)element );
}

void test_to_search_an_element_in_an_integer_array_when_element_is_present(){
	int threeInts[3]={1,2,3};
	int key=3;
	ASSERT(3==*(int*)binarySearch(&key, threeInts, sizeof(threeInts)/sizeof(threeInts[0]), sizeof(threeInts[0]), compareInt));
	ASSERT(&threeInts[2] == binarySearch(&key, threeInts, sizeof(threeInts)/sizeof(threeInts[0]), sizeof(threeInts[0]), compareInt));
}

void test_to_search_an_element_in_an_integer_array_when_element_is_not_present(){
	int fiveInts[]={1,2,3,4,5};
	int key=7;
	ASSERT(NULL==(int*)binarySearch(&key, fiveInts, sizeof(fiveInts)/sizeof(fiveInts[0]), sizeof(fiveInts[0]), compareInt));
}

void test_to_search_an_element_in_a_character_array_when_element_is_present(){
	String fiveString[]={"a","b","c","d","e"};
	String key="a";
	ASSERT(!strcmp("a",*(String*)binarySearch(&key, fiveString, sizeof(fiveString)/sizeof(fiveString[0]), sizeof(fiveString[0]), compareString)));
}

void test_to_search_an_element_in_a_character_array_when_element_is_not_present(){
	String fiveString[]={"a","b","c","d","e"};
	String key="s";
	ASSERT(NULL==binarySearch(&key, fiveString, sizeof(fiveString)/sizeof(fiveString[0]), sizeof(fiveString[0]), compareString));
}
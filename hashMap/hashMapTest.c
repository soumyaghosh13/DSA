#include "testUtils.h"
#include "hashMap.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int roll22 = 22;
int roll15 = 15;
int roll10 = 10;
int roll5 = 5;

typedef struct {
        int roll;
        char name[20];
} Student;

int getHashCode(void *key){
        return *(int*)key;
};

int cmpInt(void *first,void *second){
        return 0 == *(int*)first - *(int*)second;
};

void test_put_first_element_in_list(){
        Student soumya = {22,"soumya"};
        HashMap map = createHashMap(getHashCode,cmpInt,10);
        ASSERT(1 == put(&map,&roll22,&soumya.name));
        ASSERT(0 == strcmp(soumya.name,getHashObject(&map,&roll22)));
        disposeHashMap(&map);
};

void test_put_multiple_elements(){
        Student soumya = {22,"Soumya"};
        Student sam = {15,"Sam"};
        Student buka = {10,"Buka"};
        HashMap map = createHashMap(getHashCode,cmpInt,10);
        put(&map,&roll22,&soumya.name);
        put(&map,&roll15,&sam.name);
        put(&map,&roll10,&buka.name);
        ASSERT(0 == strcmp(soumya.name,getHashObject(&map,&roll22)));
        ASSERT(0 == strcmp(sam.name,getHashObject(&map,&roll15)));
        ASSERT(0 == strcmp(buka.name,getHashObject(&map,&roll10)));
        disposeHashMap(&map);
};

void test_same_key_should_update_value(){
        Iterator it;
        Student Soumya = {22,"Soumya"};
        Student Sam = {10,"Sam"};
        HashMap map = createHashMap(getHashCode,cmpInt,10);
        put(&map,&roll22,&Soumya.name);
        put(&map,&roll22,&Sam.name);
        it = keys(&map);
        ASSERT(0 == strcmp(Sam.name,getHashObject(&map,&roll22)));
        ASSERT(0 != strcmp(Soumya.name,getHashObject(&map,&roll22)));
        disposeHashMap(&map);
};

void test_put_should_fail_when_key_is_null(){
        HashMap map = createHashMap(getHashCode,cmpInt,10);
        Student soumya = {10,"soumya"};
        ASSERT(0 == put(&map,NULL,&soumya.name));        
        disposeHashMap(&map);
};

void test_get_null_when_element_is_absent(){
        HashMap map = createHashMap(getHashCode,cmpInt,10);
        ASSERT(NULL == getHashObject(&map,&roll22));
        disposeHashMap(&map);
};

void test_get_element_should_fail_when_key_is_null(){
        HashMap map = createHashMap(getHashCode,cmpInt,10);
        ASSERT(NULL == getHashObject(&map,NULL));
        disposeHashMap(&map);
};

void test_deleting_element_having_specific_key(){
        Student soumya = {22,"soumya"};
        HashMap map = createHashMap(getHashCode,cmpInt,10);
        put(&map,&roll22,&soumya.name);
        ASSERT(1 == removeHashObject(&map,&roll22));
        ASSERT(NULL == getHashObject(&map,&roll22));
        disposeHashMap(&map);
};

void test_deleting_element_when_absent(){
        HashMap map = createHashMap(getHashCode,cmpInt,10);
        ASSERT(0 == removeHashObject(&map,&roll22));
        disposeHashMap(&map);
};

void test_deleting_when_key_is_null_should_fail(){
        HashMap map = createHashMap(getHashCode,cmpInt,10);
        ASSERT(0 == removeHashObject(&map,NULL));
        disposeHashMap(&map);
};

void test_iterate_over_hash_map(){
        Student soumya = {10,"soumya"};
        Student sam = {20,"sam"};
        Student buka = {11,"buka"};
        HashMap map = createHashMap(getHashCode,cmpInt,10);
        Iterator it;
        put(&map,&roll22,&soumya.name);
        put(&map,&roll15,&buka.name);
        put(&map,&roll10,&sam.name);
        it = keys(&map);
        ASSERT(15 == *(int*)it.next(&it));
        ASSERT(22 == *(int*)it.next(&it));
        ASSERT(10 == *(int*)it.next(&it));
        ASSERT(NULL == it.next(&it));
        disposeHashMap(&map);
};

void test_iterating_gives_null_if_there_is_no_element(){
        HashMap map = createHashMap(getHashCode,cmpInt,10);
        Iterator it;
        it = keys(&map);
        ASSERT(0 == it.hasNext(&it));
        ASSERT(NULL == it.next(&it));
        disposeHashMap(&map);
};

void test_map_should_rehash_when_elements_in_bucket_are_more_than_3(){
        Iterator it;
        Student soumya = {10,"soumya"};
        Student sam = {20,"sam"};
        Student buka = {30,"buka"};
        Student guru = {40,"guru"};
        HashMap map = createHashMap(getHashCode,cmpInt,10);
        put(&map,&roll22,&soumya.name);
        put(&map,&roll15,&sam.name);
        put(&map,&roll10,&buka.name);
        put(&map,&roll5,&guru.name);
        it = keys(&map);
        ASSERT(15 == *(int*)it.next(&it));
        ASSERT(5 == *(int*)it.next(&it));
        ASSERT(22 == *(int*)it.next(&it));
        ASSERT(10 == *(int*)it.next(&it));
        ASSERT(NULL == it.next(&it));
        disposeHashMap(&map);
};

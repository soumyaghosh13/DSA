#include "testUtils.h"
#include "hashMap.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int roll22 = 22;
int roll15 = 15;
int roll10 = 10;

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
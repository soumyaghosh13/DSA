#include "arrayList.h"
#include <stdlib.h>

ArrayList create(int capacity) {
        ArrayList list;
        list.base = (void*)malloc(sizeof(void*) * capacity);
        list.capacity = capacity;
        list.length = 0;
        return list;
}

void forwardShift(ArrayList *list, int index) {
        int i;
        if (index < list->length) {
                for (i = list->length - 1; i >= index; i--) {
                        list->base[i+1] = list->base[i];
                }
        }        
}

int isFull(ArrayList *list) {
        return list->length == list->capacity;
}

void increaseCapacity(ArrayList *list) {
        int targetCapacity;
        if (isFull(list)) {
                targetCapacity = list->capacity * 2;
                list->base = realloc(list->base, targetCapacity * sizeof(void*));
                list->capacity = targetCapacity;
        }        
}

int insert(ArrayList *list, int index, void* data) {
        if (list == NULL) return 0;
        if (index < 0 || index > list->length) return 0;

        increaseCapacity(list);
        forwardShift(list, index);
        list->base[index] = data;
        list->length++;
        return 1;
}

int add(ArrayList *list, void *data){
        if(!list) return 0;
        return insert(list, list->length, data);
}

void* get(ArrayList list, int index) {
        if (index < 0 || index >= list.length) return NULL;
        return list.base[index];
}

void backwordShift(ArrayList *list, int index) {
        int i;
        if (index < list->length-1) {
                for (i = index; i < list->length; i++) {
                        list->base[i] = list->base[i+1];
                }
        }        
}

int remove(ArrayList* list, int index){
        if(index < 0 || index >= list->length) return 0;
        backwordShift(list, index);
        list->length--;
        return 1;
}

int hasNext(Iterator* it){
        ArrayList *list = it->list;
        if(list->length <= it->position) return 0;
        return 1;
};

void* getNextData(Iterator* it){
        ArrayList* list = it->list;
        if(!hasNext(it)) return NULL;
        return list->base[it->position++];
}

Iterator getIterator(ArrayList* list){
        Iterator it;
        it.list = list;
        it.position = 0;
        it.hasNext = &hasNext;
        it.next = &getNextData;
        return it;
}

int search(ArrayList list, void *data, Comparator *areEqual){
        Iterator it = getIterator(&list);
        void* currentData;
        int result;
        while(it.hasNext(&it)){
                currentData = it.next(&it);
                result = areEqual(currentData, data);
                if(result) return it.position - 1;
        }
        return -1;
}

void iterate(ArrayList list, ForEach* forEach){
        int result,index;
        for(index = 0;index < list.length ;index++){
                forEach(list.base[index]);
        }
}

void dispose(ArrayList *list) {
        free(list->base);
}
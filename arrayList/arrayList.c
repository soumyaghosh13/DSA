#include "arrayList.h"
#include <stdlib.h>

ArrayList create(int capacity) {
        ArrayList list;
        list.base = (void*)malloc(sizeof(void*) * capacity);
        list.capacity = capacity;
        list.length = 0;
        return list;
}

void shiftRight(ArrayList *list, int index) {
        int i;
        for (i = list->length - 1; i >= index; i--) {
                list->base[i+1] = list->base[i];
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
        shiftRight(list, index);

        list->base[index] = data;
        list->length++;

        return 1;
}
int add(ArrayList *list,void *data){
        return insert(list, list->length, data);
}
void shiftLeft(ArrayList *list, int index) {
        int i;
        for(i = index;i < list->length-1;i++){
        list->base[i] = list->base[i+1];
    }
}

int remove(ArrayList *list,int index){
        int i;
        if (list == NULL) return 0;
        if (index < 0 || index > list->length) return 0;
    shiftLeft(list, index);
    list->length--;
    return 1;
}
void* get(ArrayList *list, int index) {
        if (index < 0 || index >= list->length) return NULL;
        return list->base[index];
}
int search(ArrayList *list, void *searchElement, compare cmpFun){
        int i;
        for(i = 0;i < list->length;i++){
                if(0 == cmpFun(searchElement,list->base[i]))
                        return i;
        }
        return -1;
}

void dispose(ArrayList *list) {
        free(list->base);
}

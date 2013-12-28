#include "../iterator.h"
typedef struct {
        void** base;
        int capacity;
        int length;
} ArrayList;

typedef int Comparator (void* first,void* second);
typedef void ForEach(void* data);

ArrayList create(int capacity);

int insert(ArrayList *list, int index, void* data);
void* get(ArrayList list, int index);
int remove(ArrayList* list, int index);
int add(ArrayList* list, void* data);
int search(ArrayList list, void* data, Comparator* areEqual);
Iterator getIterator(ArrayList* list);
void dispose(ArrayList *list);
void iterate(ArrayList list, ForEach* forEach);
typedef int (*comparator)(void* prev, void* next);

void mergeSort(void* base, int numberOfElements, int elementSize, comparator comp);
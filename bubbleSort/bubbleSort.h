#include <stddef.h>

typedef int (*compare)(void* first, void* second);

void bubbleSort(void* base, size_t numberOfElements, size_t elementSize, compare comp); 


#include "mergeSort.h"
#include <memory.h>
#include <stdlib.h>

void mergeSort(void* base, int numberOfElements, int elementSize, comparator comp){
     if (numberOfElements <= 1)
     	return ;
     }
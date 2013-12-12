#include "bSearchLib.h"
#include <stdlib.h>
#include <math.h>

void* binarySearch(void *key, void *base, int length, int size, int (*compare)(void *, void *)){
	int first = 0;
	int last = length-1;
	int centerIndex,status;
	while(first <= last){
		centerIndex = floor((first + last) / 2);
		status = compare(key,base+(centerIndex*size));
		if(!status)
			return base+(centerIndex*size);
		if(status < 0)
			last = centerIndex -1;
		if(status > 0)
			first = centerIndex + 1;
	}
	return NULL;
}
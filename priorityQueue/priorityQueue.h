#include <stdbool.h>
#include "circularQueue.h"


typedef int (*compare)(void* first, void* second);

int priorityEnqueue(Queue* queue, void* element,compare comp);

void* priorityDequeue(Queue* queue);


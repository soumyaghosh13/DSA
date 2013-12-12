#include <stdbool.h>

typedef struct{
	void *base;
	struct queueInfo{
		int length;
		int elementSize;
		int front;
		int rear;
	}queueInfo;
} queue;

typedef char String[256];

queue* create(int elementSize,int length);
bool enQueue(queue* queue,void* element);
void* deQueue(queue* queue);
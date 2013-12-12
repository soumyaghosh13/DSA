#include <stdbool.h>


typedef char string[50];
typedef struct{
        void* elements;
        int elementSize;
        int front;
        int rear;
        int no_of_elements;
}queue;


queue* create(int elementSize, int no_of_elements);
bool enqueue(queue* queue,void* element);
void* dequeue(queue* queue);
bool isFull(queue* queue);
bool isEmpty(queue* queue);
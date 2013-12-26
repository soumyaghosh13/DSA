typedef struct{
    void* base;
    int length;
    int elementSize;
    int rear;
    int front;
}Queue;


typedef char String[256];
Queue* create(int elementSize,int length);
int enqueue(Queue* queue, void* element);
void* dequeue(Queue* queue);
int queueIsEmpty(Queue* queue);
int queueIsFull(Queue* queue);


#include <stdbool.h>
typedef struct{
        void* base;
        int length;
        int top;
        int elementSize;


}Stack;
typedef char String[256];


Stack* create(int length,int elementSize);
bool push(Stack* stack,void* element);
void* pop(Stack* stack);
void* peek(Stack* stack);
int isEmpty(Stack* stack);
int isFull(Stack* stack);


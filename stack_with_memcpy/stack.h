#define true 1
#define false 0

typedef struct 
{
	void *elements;
	int top;
	int elementSize;
	int size;
}Stack;

typedef char String[256];

typedef int boolean;

Stack* create(int ElementSize, int length);
boolean push(Stack* stack,void* InsertElement);
void* pop(Stack *stack);
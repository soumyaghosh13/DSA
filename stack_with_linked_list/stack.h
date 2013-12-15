#include "./include/linkList.h"
#include <stdbool.h>

typedef char String[256];
typedef  DList Stack;
Stack* createStack();
bool push(Stack* stack,void* element);
void* pop(Stack* stack);
void* top(Stack* stack);
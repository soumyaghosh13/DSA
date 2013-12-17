#include "linkedList.h"
#include <stdbool.h>

typedef  LinkedList Stack;

Stack* createStack();

bool push(Stack* stack, void* element);

void* pop(Stack* stack);

void* top(Stack* stack);
#include "stack_lib.h"
#include <stdlib.h>
#include <string.h>

Stack* create(int ElementSize, int length){
	Stack* stack;
	stack=(Stack*)malloc(sizeof(Stack));
	stack->elements = calloc(ElementSize,length);
	stack->elementSize=ElementSize;
	stack->size=length;
	stack->top=-1;
	return stack;	
}

boolean IsEmpty(Stack* stack){
	return stack->top==-1;
}

boolean IsStackFull(Stack *st){
	if((st->top+1) >= st->size)
		return true;
	else
		return false;
}

boolean push(Stack* stack,void* elementToPush){
	void* address;
	if(IsStackFull(stack))
		return false;
	address=stack->elements+(++(stack->top)*stack->elementSize);
	memcpy(address, elementToPush, stack->elementSize);
	return true;
}

void* pop(Stack* stack){
	if(IsEmpty(stack))	
		return false;
	return stack->elements+((stack->top--)*stack->elementSize);
}


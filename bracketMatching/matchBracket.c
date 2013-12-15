#include "matchBracket.h"
#include <stdio.h>
#include <String.h>


int matchBrackets(char element,Stack* stack,char openBracket,char closeBracket){
    void* currentTop;
    if(closeBracket == element){
        currentTop = peek(stack);
        if(openBracket == *(char*)currentTop)
            pop(stack);
        else
            return 0;
    }
    return 1;
};
int isStackEmpty(Stack *stack){
        if(stack->top==0)
        return 1;
    return 0;
}
int startMatching(const char* input){
        Stack* stack;
    int i, limit;
    limit = strlen(input);
    stack = create(limit, sizeof(char));


    for(i = 0; i < limit; i++){
        if(input[i]=='{' || input[i]=='[' || input[i]=='('){
                push(stack, (void*)&input[i]);
        };
        if(!matchBrackets(input[i], stack, '(', ')'))
                return 0;


        if(!matchBrackets(input[i], stack, '[', ']'))
                        return 0;


                if (!matchBrackets(input[i], stack, '{', '}'))
                        return 0;
    }
    return isStackEmpty(stack);
}


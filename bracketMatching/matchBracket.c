#include "matchBracket.h"
#include <stdio.h>
#include <String.h>

int compareBracket(char element,Stack* stack,char openBracket,char closeBracket){
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

int isBracketMatching(const char* input){
        Stack* stack;
    int i, limit;
    limit = strlen(input);
    stack = create(limit, sizeof(char));


    for(i = 0; i < limit; i++){
        if(input[i]=='{' || input[i]=='[' || input[i]=='('){
                push(stack, (void*)&input[i]);
        };
        if(!compareBracket(input[i], stack, '(', ')'))
                return 0;


        if(!compareBracket(input[i], stack, '[', ']'))
                        return 0;


                if (!compareBracket(input[i], stack, '{', '}'))
                        return 0;
    }
    return isEmpty(stack);
}


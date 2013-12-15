#include <stdio.h>
#include "matchBracket.h"




int main(int argc, char const *argv[])
{
        const char* input = argv[1];
        int result = startMatching(input);
        if(!result)
        printf("%s\n","Not Matched" );
    else
            printf("%s\n","All Brackets Matched" );
        return 0;
}


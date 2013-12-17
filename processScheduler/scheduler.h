# include "../bracketMatching/stack.h"

typedef struct{
        int priority;
        int ptime;
        String name;
        int num;
}Process;

Process* add(int priority,int ptime,String name,int num);

int scheduler(Process* process);

bool insert(Stack* stack,Process* process);
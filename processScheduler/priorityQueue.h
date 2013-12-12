typedef char String[256];

typedef struct PriorityQueue{
        String queueName;
        int time;
        int priority;
        struct PriorityQueue *next;
} PriorityQueue;

typedef struct {
        PriorityQueue *head;
        void *End;
        int length;
        int tail;
} ProcessSceduler;


ProcessSceduler* createPriorityQueue();
int enPriorityQueue(ProcessSceduler*, PriorityQueue*);
PriorityQueue dePriorityQueue(PriorityQueue);


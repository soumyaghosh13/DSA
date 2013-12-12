typedef struct node {
        void* data;
        struct node* next;
        struct node* previous;
} Node;

typedef struct {
        int length;
        Node* head;
} linkedList;

typedef char String[256];

linkedList* createLinkedList();
int insertNode(linkedList* list,void* element,int index);
Node* removeNode(linkedList* list,int index);
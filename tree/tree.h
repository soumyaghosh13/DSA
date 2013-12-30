#include "iterator.h"

typedef int (*compareFunc)(void* first,void* second);

typedef struct {
        void* root;
        compareFunc compare;
} Tree;

Tree createRoot(compareFunc compare);

int insertTreeNode(Tree* tree,void* parent,void* data);

int removeSpecificNode(Tree *tree,void* data);

Iterator getChildren(Tree *tree,void* parent);        

int search(void* tree,void* parent);

void disposeTree(Tree *tree);
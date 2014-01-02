typedef int (*CompareFunc)(void *first,void *second);

typedef struct {
        void *root;
        CompareFunc compare;
} BSTree;

BSTree createBinarySearchTree(CompareFunc compare);

int insert(BSTree *tree,void *data);
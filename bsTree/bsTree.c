#include "BSTree.h"
#include <stdlib.h>

typedef struct bstreenode{
        void *data;
        struct bstreenode *left;
        struct bstreenode *right;
        struct bstreenode *parent;
} BSTreeNode;

BSTree createBinarySearchTree(CompareFunc compare) {
        BSTree BStree;
        BStree.root = NULL;
        BStree.compare = compare;
        return BStree;
};

BSTreeNode* createBinarySearchTreeNode(void *data){
        BSTreeNode *node = calloc(1,sizeof(BSTreeNode));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
};
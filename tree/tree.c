#include "tree.h"
#include "privateTree.h"
#include "memory.h"
#include <stdlib.h>

Tree createTree(compareFunc cmp){
        Tree tree;
        tree.compare = cmp;
        tree.root = NULL;
        return tree;
};

TreeNode* createTreeNode(void* child){
        TreeNode *node = calloc(1,sizeof(TreeNode));
        node->data = child;
        node->list = NULL;
        node->parent = NULL;
        return node;
};
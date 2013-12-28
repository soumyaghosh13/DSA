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


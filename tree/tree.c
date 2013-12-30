#include "tree.h"
#include "privateTree.h"
#include "memory.h"
#include <stdlib.h>

Tree createRoot(compareFunc cmp){
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

TreeNode* fetchNode(List* list,void* parent,compareFunc cmp){
        TreeNode *tn;
        Iterator it = getIterator(list);
        while(it.hasNext(&it)){
                tn = it.next(&it);
                if(0 == cmp(tn->data,parent))
                        return tn;
                if(tn->list)
                        return fetchNode(tn->list,parent,cmp);
        }
        return NULL;
};

TreeNode* traverse(void* tree,void *parent){
        TreeNode *treeNode;
        if(!((Tree*)tree)->root)
                return NULL;
        treeNode = ((Tree*)tree)->root;
        if(0==((Tree*)tree)->compare(treeNode->data,parent))
                return treeNode;
        return fetchNode(treeNode->list,parent,((Tree*)tree)->compare);
};

void* searchSpecific(Tree *tree,void* parent){
        TreeNode* tn;
        tn = traverse(tree,parent);
        return tn;
};

int search(void* tree,void* parent){
        void *matchedNode = searchSpecific(tree,parent);
        if(matchedNode) return 1;
        return 0;
};

int insertNode(Tree *tree,void *parent,void *child){
        TreeNode *node = createTreeNode(child);
        TreeNode *matchedTreeNode;
        List* list;
        if(parent == NULL){
                tree->root = node;
                return 1;
        }
        matchedTreeNode = searchSpecific(tree,parent);
        node->parent = matchedTreeNode;
        if(matchedTreeNode->list == NULL){
                list = create();
                matchedTreeNode->list = list;
        }
        list = matchedTreeNode->list;
        insert(list,node,1);
        return 1;
};

void* getRootNode(Iterator* it){
        TreeNode *root = (TreeNode*)it->list;
        return root->data;
};

int hasCurrentTreeNode(Iterator* it){
        return ((Node*)(it->current)) != NULL;
};

void* getCurrentTreeNode(Iterator *it){
        TreeNode* result = NULL;
        if(it->hasNext(it)){
                result = ((Node*)(it->current))->data;
                it->current = ((Node*)(it->current))->next;
        }
        if(result)
                return result->data;
        return result;
};

Iterator getChildren(Tree *tree,void* parent){
        Iterator it;
        TreeNode *matchedNode;
        if(parent == NULL){
                it.list = tree->root;
                it.current = NULL;
                it.hasNext = NULL; 
                it.next = getRootNode;
                return it;
        }
        matchedNode = searchSpecific(tree,parent);
        it.list = matchedNode->list;
        if(it.list == NULL) it.current = NULL;
        else it.current = ((List*)it.list)->head;
        it.next = getCurrentTreeNode;
        it.hasNext = hasCurrentTreeNode;
        return it;
};

int getIndex(List* list,void* data,compareFunc cmp){
        int i = 0;
        TreeNode *tn;
        Iterator it = getIterator(list);
        while(it.hasNext(&it)){
                i = i + 1;
                tn = (TreeNode*)it.next(&it);
                if(0 == cmp(tn->data,data))
                        return i;
        }
        return i;
};

int removeSpecificNode(Tree *tree,void* data){
        List* list;
        int index;
        TreeNode *matchedNode = searchSpecific(tree,data);
        if(!matchedNode) return 0;
        if(matchedNode->list) return 0;
        if(matchedNode == tree->root){
                tree->root = NULL;
                free(matchedNode);
                return 1;
        }
        list = matchedNode->parent->list;
        index = getIndex(list,data,tree->compare);
        remove(list,index);
        if(length(list) == 0)
                matchedNode->parent->list = NULL;
        free(matchedNode);
        return 1;
};

void freeAllNodes(Tree *tree,List *childs){
        TreeNode *tn;
        Iterator it = getIterator(childs);
        while(it.hasNext(&it)){
                tn = it.next(&it);
                if(tn->list)
                        return freeAllNodes(tree,tn->list);
                removeSpecificNode(tree,tn->data);
        }
};

void disposeTree(Tree *tree){
        TreeNode* root = tree->root;
        freeAllNodes(tree,root->list);
};
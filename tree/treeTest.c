#include "testUtils.h"
#include "tree.h"
#include <memory.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int cmpInt(void* first,void* second){
        return *(int*)first - *(int*)second;
};

void test_create_root_node_in_tree(){
        Tree tree = createRoot(cmpInt);
        Iterator it;
        void *element;
        int element1 =10;
        ASSERT(1 == insertTreeNode(&tree,NULL,&element1));
        it = getChildren(&tree,NULL);
        element = it.next(&it);
        ASSERT(*(int*)element == element1);
        disposeTree(&tree);
};

void test_insert_first_node_as_child_of_root(){
        Tree tree = createRoot(cmpInt);
        Iterator it;
        int element1 = 10,element2 = 20;
        insertTreeNode(&tree,NULL,&element1);
        insertTreeNode(&tree,&element1,&element2);
        it = getChildren(&tree,&element1);
        ASSERT(element2 == *(int*)it.next(&it));
        ASSERT(NULL == it.next(&it));
        disposeTree(&tree);
};

void test_insert_node_in_2_level_below_root(){
        Tree tree = createRoot(cmpInt);
        void * element;
        Iterator it;
        int element1 = 555,element2 = 666,element3 = 777,element4 = 888;
        insertTreeNode(&tree,NULL,&element1);
        insertTreeNode(&tree,&element1,&element2);
        insertTreeNode(&tree,&element2,&element3);
        insertTreeNode(&tree,&element2,&element4);
        it = getChildren(&tree,&element2);
        ASSERT(element4 == *(int*)it.next(&it));
        ASSERT(element3 == *(int*)it.next(&it));
        disposeTree(&tree);
};
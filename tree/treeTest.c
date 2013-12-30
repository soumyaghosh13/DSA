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

void test_search_for_root_node(){
        Tree tree = createRoot(cmpInt);
        int element1 =555;
        ASSERT(1 == insertTreeNode(&tree,NULL,&element1));
        ASSERT(1 == search(&tree,&element1));
        disposeTree(&tree);
};

void test_search_for_child_of_root(){
        Tree tree = createRoot(cmpInt);
        int element1 = 555,element2 = 666,element3 = 777;
        insertTreeNode(&tree,NULL,&element1);
        insertTreeNode(&tree,&element1,&element2);
        insertTreeNode(&tree,&element1,&element3);
        ASSERT(1 == search(&tree,&element2));
        ASSERT(1 == search(&tree,&element3));
        disposeTree(&tree);
};


void test_search_two_level_below_root(){
        Tree tree = createRoot(cmpInt);
        int element1 = 10,element2 = 20,element3 = 30,element4 = 40;
        insertTreeNode(&tree,NULL,&element1);
        insertTreeNode(&tree,&element1,&element2);
        insertTreeNode(&tree,&element2,&element3);
        insertTreeNode(&tree,&element2,&element4);
        ASSERT(1 == search(&tree,&element3));
        ASSERT(1 == search(&tree,&element4));
        disposeTree(&tree);
};

void test_removing_leaf_node(){
        Tree tree = createRoot(cmpInt);
        int element1 = 10,element2 = 20;
        Iterator it;
        insertTreeNode(&tree,NULL,&element1);
        insertTreeNode(&tree,&element1,&element2);
        ASSERT(1 == removeSpecificNode(&tree,&element2));
        it = getChildren(&tree,&element1);
        ASSERT(NULL == it.next(&it));
        disposeTree(&tree);
};

void test_removing_node_with_childs_should_fail(){
        Tree tree = createRoot(cmpInt);
        int element1 = 10,element2 = 20,element3 = 30,element4 = 40;
        insertTreeNode(&tree,NULL,&element1);
        insertTreeNode(&tree,&element1,&element2);
        ASSERT(0 == removeSpecificNode(&tree,&element1));
        disposeTree(&tree);
};

void test_remove_root_node(){
        Tree tree = createRoot(cmpInt);
        int element1 = 10;
        insertTreeNode(&tree,NULL,&element1);
        ASSERT(1 == removeSpecificNode(&tree,&element1));
        ASSERT(0 == search(&tree,&element1));
};

void test_remove_absent_node_should_fail(){
        Tree tree = createRoot(cmpInt);
        int element1 = 10,element2 = 20,element3 = 30;
        Iterator it;
        insertTreeNode(&tree,NULL,&element1);
        insertTreeNode(&tree,&element1,&element2);
        ASSERT(0 == removeSpecificNode(&tree,&element3));
        disposeTree(&tree);
};

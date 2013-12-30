#include "testUtils.h"
#include "tree.h"
#include <memory.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int cmpInt(void* first,void* second){
        return *(int*)first - *(int*)second;
};

void test_insert_first_element_in_tree(){
        Tree tree = createRoot(cmpInt);
        Iterator it;
        void *element;
        int element1 =10;
        ASSERT(1 == insertNode(&tree,NULL,&element1));
        it = getChildren(&tree,NULL);
        element = it.next(&it);
        ASSERT(*(int*)element == element1);
        disposeTree(&tree);
};
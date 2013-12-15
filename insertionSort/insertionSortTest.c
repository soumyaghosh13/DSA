#include "testUtils.h"
#include "insertionSort.h"
#include <stdio.h>
#include <memory.h>


typedef struct {
        int rollNo;
        int marks;
} Student;


int compareInt ( void* a,  void* b){
    return (*(int*)a - *(int*)b);
}

int areStudentsEqual(Student* expected,Student* actual){
        int result = expected->rollNo == actual->rollNo && 
                                        expected->marks == actual->marks  ;
    return result;
}

int compareStudentsByrollNo(void* first, void* second) {
        Student* firstStudent = (Student*)first;
        Student* secondStudent = (Student*)second;
        return firstStudent->rollNo - secondStudent->rollNo;
}

void test_sorting_an_array_of_integers(){
        int expected[] = {1,2,3,4};
        int actual[] = {4,3,1,2};
        isort(actual, 4, sizeof(int), compareInt);
        ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}

void test_sorting_Students_by_roll_number(){
        Student expected[] = {{1,100},{3,85},{4,90},{5,99}};
        Student Students[] = {{5,99},{3,85}, {4,90},{1,100}};
        isort(Students, 4, sizeof(Student), compareStudentsByrollNo);
        ASSERT(1 == areStudentsEqual(expected, Students));
}





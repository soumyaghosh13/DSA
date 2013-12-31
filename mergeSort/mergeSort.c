#include "mergeSort.h"
#include <memory.h>
#include <stdlib.h>

int merge(void* destination, void* left, void* right, size_t leftLength, 
							size_t rightLength,size_t elementSize, comparator cmp ){
        int i=0,j=0,k=0;
        while(i < leftLength && j < rightLength){
                if(cmp(left+(i*elementSize), right+(j*elementSize))){
                        memmove(destination+(k*elementSize), left+(i*elementSize), elementSize);
                        i++;
                }
                else{
                        memmove(destination+(k*elementSize), right+(j*elementSize), elementSize);
                        j++;
                }
                k++;
        }
        while( j < rightLength){
                memmove(destination+(k*elementSize), right+(j*elementSize), elementSize);
                j++;
                k++;
        }
        while(i < leftLength){
                memmove(destination+(k*elementSize), left+(i*elementSize), elementSize);
                i++;
                k++;
        }
        return 1;
}

void mergeSort(void* base, int numberOfElements, int elementSize, comparator comp){
        int mid = numberOfElements/2,i,j,leftLength,rightLength;
        void* left = calloc(mid,elementSize);
        void* right = calloc((numberOfElements-mid),elementSize);
        if(numberOfElements < 2) return;
        leftLength = mid;
        rightLength = numberOfElements-mid;
        for(i=0;i<mid;i++)
                memmove(left+i*elementSize,base+i*elementSize,elementSize);
        for(i=mid;i<numberOfElements;i++)
                memmove(right+elementSize*(i-mid),base+elementSize*i,elementSize);
        mergeSort(left,leftLength,elementSize,comp);
        mergeSort(right,rightLength,elementSize,comp);
        merge(base, left, right, leftLength, rightLength, elementSize, comp);
        free(left);
        free(right);
}
//
//  mergeSort.cpp
//  console
//
//  Created by yuanrui on 15/4/19.
//  Copyright (c) 2015年 KudoCC. All rights reserved.
//

#include "mergeSort.h"
#include <string>
#include <stdlib.h>

void _mergeSort(int *array, int *bakArray, int len) ;

void mergeSort(int *array, int len)
{
    int *bak = (int *)malloc(sizeof(int)*len) ;
    _mergeSort(array, bak, len) ;
    free(bak) ;
}

void _mergeSort(int *array, int *bakArray, int len)
{
    if (len >= 2) {
        int leftLen = len/2 ;
        _mergeSort(array, bakArray, leftLen) ;
        _mergeSort(array+leftLen, bakArray, len-leftLen) ;
        int *pa = array ;
        int *pb = array+leftLen ;
        int aIndex = 0 ;
        int bIndex = 0 ;
        while (aIndex < leftLen && bIndex < len-leftLen) {
            int a = pa[aIndex] ;
            int b = pb[bIndex] ;
            if (a < b) {
                bakArray[aIndex+bIndex] = a ;
                ++aIndex ;
            } else if (a == b) {
                bakArray[aIndex+bIndex] = a ;
                bakArray[aIndex+bIndex+1] = a ;
                ++aIndex ;
                ++bIndex ;
            } else {
                bakArray[aIndex+bIndex] = b ;
                ++bIndex ;
            }
        }
        if (aIndex < leftLen) {
            memcpy(bakArray+aIndex+bIndex, pa+aIndex, sizeof(int)*(leftLen-aIndex)) ;
        } else if (bIndex < len-leftLen) {
            memcpy(bakArray+aIndex+bIndex, pb+bIndex, sizeof(int)*(len-leftLen-bIndex)) ;
        }
        memcpy(array, bakArray, sizeof(int)*len) ;
    }
}

static const int MaxArraySize = 100 ;
int main()
{
    srand(time(NULL)) ;
    int array[MaxArraySize] ;
    for (int i = 0 ; i < MaxArraySize; ++i) {
        array[i] = rand() % 10000 ;
    }
    mergeSort(array, MaxArraySize) ;
    for (int i = 0 ; i < MaxArraySize; ++i) {
        printf("%d ", array[i]) ;
    }
    printf("\n") ;
    return 0 ;
}


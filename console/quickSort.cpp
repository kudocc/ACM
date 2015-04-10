//
//  quickSort.cpp
//  console
//
//  Created by yuanrui on 15-4-10.
//  Copyright (c) 2015年 KudoCC. All rights reserved.
//

#include "quickSort.h"
#include <stdlib.h>
#include <time.h>

void queueSortSwap(int i, int j, int *array) ;
void quickSortPart(int *array, int left, int right) ;

void quickSort(int *array, int length)
{
    quickSortPart(array, 0, length-1) ;
}

// select the middle number, let it be right
// get the partition index of [left, right], which means the element of middle is larger
// than elements in [left, middle) and is less than (middle, right]
int partition(int *array, int left, int right)
{
    int allLeftOfItIsLessOrEqualToMiddle = -1 ;
    for (int i = left; i < right; ++i) {
        if (array[i] <= array[right]) {
            if (allLeftOfItIsLessOrEqualToMiddle != -1) {
                queueSortSwap(allLeftOfItIsLessOrEqualToMiddle, i, array) ;
                ++allLeftOfItIsLessOrEqualToMiddle ;
            }
        } else {
            if (allLeftOfItIsLessOrEqualToMiddle == -1) {
                allLeftOfItIsLessOrEqualToMiddle = i ;
            }
        }
    }
    if (allLeftOfItIsLessOrEqualToMiddle != -1) {
        queueSortSwap(allLeftOfItIsLessOrEqualToMiddle, right, array) ;
        return allLeftOfItIsLessOrEqualToMiddle ;
    } else {
        return right ;
    }
}

void quickSortPart(int *array, int left, int right)
{
    if (left >= right) {
        return ;
    }
    int mid = partition(array, left, right) ;
    quickSortPart(array, left, mid-1) ;
    quickSortPart(array, mid+1, right) ;
}

void queueSortSwap(int i, int j, int *array)
{
    int tmp = array[i] ;
    array[i] = array[j] ;
    array[j] = tmp ;
}

static const int MaxArraySize = 100 ;
int main()
{
    srand(time(NULL)) ;
    int array[MaxArraySize] ;
    for (int i = 0 ; i < MaxArraySize; ++i) {
        array[i] = rand() % 10000 ;
    }
    quickSort(array, MaxArraySize) ;
    for (int i = 0 ; i < MaxArraySize; ++i) {
        printf("%d ", array[i]) ;
    }
    printf("\n") ;
}

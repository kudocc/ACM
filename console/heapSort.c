//
//  heapSort.c
//  console
//
//  Created by yuanrui on 15-3-31.
//  Copyright (c) 2015年 KudoCC. All rights reserved.
//

#include "heapSort.h"

void buildMaxHeap(int *array, int lenArray) ;
void makeMaxHeap(int *array, int start, int end) ;

void maxHeapSort(int *array, int lenArray)
{
    buildMaxHeap(array, lenArray) ;
    for (int i = 1; i < lenArray-1; ++i) {
        int last = *(array+lenArray-i) ;
        int first = *(array) ;
        *array = last ;
        *(array+lenArray-i) = first ;
        makeMaxHeap(array, 1, lenArray-i-1) ;
    }
}

void buildMaxHeap(int *array, int lenArray)
{
    for (int i = lenArray/2; i >= 1; --i) {
        makeMaxHeap(array, i, lenArray) ;
    }
}

void makeMaxHeap(int *array, int start, int end)
{
    int index = start ;
    int left = start*2 ;
    int right = left+1 ;
    while (left <= end) {
        int val = *(array+index-1) ;
        int lVal = *(array+left-1) ;
        int rVal = right>end ? INT32_MIN : *(array+right-1) ;
        if (val >= lVal && val >= rVal) {
            break ;
        } else {
            if (lVal >= rVal) {
                *(array+index-1) = lVal ;
                *(array+left-1) = val ;
                index = left ;
            } else {
                *(array+index-1) = rVal ;
                *(array+right-1) = val ;
                index = right ;
            }
        }
        left = index*2 ;
        right = left+1 ;
    }
}
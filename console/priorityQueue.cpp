//
//  priorityQueue.cpp
//  console
//
//  Created by yuanrui on 15-3-31.
//  Copyright (c) 2015年 KudoCC. All rights reserved.
//

#include "priorityQueue.h"
#include <stdlib.h>

#ifndef INT32_MAX
#define INT32_MAX 600000
#endif // !INT32_MAX


CPriorityQueue::CPriorityQueue(int capacity)
{
    this->capacity = capacity ;
    this->size = 0 ;
    pArray = (PPriorityQueueObject *)malloc(sizeof(PPriorityQueueObject)*capacity) ;
}

CPriorityQueue::~CPriorityQueue()
{
    if (pArray) {
        free(pArray) ;
    }
}

void CPriorityQueue::printAllElement()
{
    printf("begin print all elements, number is %d\n", size) ;
    int i = 0 ;
    while (i < size) {
        printf("index:%d, %p\n", i, pArray[i]) ;
        ++i ;
    }
    printf("end print all elements\n") ;
}

PPriorityQueueObject CPriorityQueue::extractMin()
{
	if (size == 0) {
		return NULL;
	}
	PriorityQueueObject *firstObj = pArray[0] ;
	PriorityQueueObject *lastObj = pArray[size-1] ;
	pArray[size-1] = NULL ;
	pArray[0] = lastObj ;
	--size ;
	keepMinHeap(0) ;
    
    return firstObj ;
}

void CPriorityQueue::enqueue(PPriorityQueueObject pObj)
{
    if (pObj && size+1<=capacity) {
        ++size ;
        pArray[size-1] = pObj ;
		
        upTheObject(size-1) ;
    }
}

void CPriorityQueue::decreaseObj(PPriorityQueueObject pObj)
{
    // find the obj
    int iPos = -1 ;
    for (int i = 0; i < size; ++i) {
        if (pArray[i] == pObj) {
            iPos = i ;
            break ;
        }
    }
    if (iPos == -1) {
        return ;
    }
    
    upTheObject(iPos) ;
}

int CPriorityQueue::getSize()
{
	return size;
}

void CPriorityQueue::buildMinHeap()
{
    for (int i = size/2; i >= 1; --i) {
		keepMinHeap(i - 1);
    }
}


void CPriorityQueue::upTheObject(int iPos)
{
    ++iPos ;
    
    int i = iPos ;
    while (i >= 2) {
        int parent = i / 2 ;
        PPriorityQueueObject obj = pArray[i-1] ;
        PPriorityQueueObject objParent = pArray[parent-1] ;
        if (obj->priority < objParent->priority) {
            pArray[i-1] = objParent ;
            pArray[parent-1] = obj ;
            i = parent ;
        } else {
            break;
        }
    }
}

void CPriorityQueue::keepMinHeap(int start)
{
    ++start ;
    
    int index = start ;
    int left = start*2 ;
    int right = left+1 ;
    while (left <= size) {
        PPriorityQueueObject obj = *(pArray+index-1) ;
        int val = obj->priority ;
        PPriorityQueueObject leftObj = *(pArray+left-1) ;
        int lVal = leftObj->priority ;
        PPriorityQueueObject rightObj = right>size ? NULL : *(pArray+right-1) ;
        int rVal = rightObj ? rightObj->priority : INT32_MAX ;
        if (val <= lVal && val <= rVal) {
            break ;
        } else {
            if (lVal <= rVal) {
                *(pArray+index-1) = leftObj ;
                *(pArray+left-1) = obj ;
                index = left ;
            } else {
                *(pArray+index-1) = rightObj ;
                *(pArray+right-1) = obj ;
                index = right ;
            }
        }
        left = index*2 ;
        right = left+1 ;
    }
}
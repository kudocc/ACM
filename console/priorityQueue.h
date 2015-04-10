//
//  priorityQueue.h
//  console
//
//  Created by yuanrui on 15-3-31.
//  Copyright (c) 2015年 KudoCC. All rights reserved.
//

#ifndef __console__priorityQueue__
#define __console__priorityQueue__

#include <stdio.h>
#include "common.h"

class PriorityQueueObject {
public:
    int element ;
    int priority ;
};
typedef PriorityQueueObject *PPriorityQueueObject;

/**
 *  优先级队列，优先级低的先出
 */
class CPriorityQueue {
public:
    CPriorityQueue(int capacity) ;
    ~CPriorityQueue() ;
public:
    void printAllElement() ;
    PPriorityQueueObject extractMin() ;
    void enqueue(PPriorityQueueObject pObj) ;
    void decreaseObj(PPriorityQueueObject pObj) ;
	int getSize();
private:
    void buildMinHeap() ;
    /**
     *  start是数组下标值
     */
	void keepMinHeap(int start);
    // 从此处开始向上整理
    void upTheObject(int index) ;
private:
    PPriorityQueueObject *pArray ;
    int capacity ;
    int size ;
};

#endif /* defined(__console__priorityQueue__) */

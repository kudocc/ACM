//
//  deepFirstSearch.cpp
//  console
//
//  Created by yuanrui on 15-4-13.
//  Copyright (c) 2015年 KudoCC. All rights reserved.
//

#include <stdio.h>
#include "adjacencyList.h"
#include <vector>
#include <deque>
#include <math.h>

typedef enum {
    StateOfVertexWhite, // 没有被访问过
    StateOfVertexGray,  // 被访问过，但是还没有访问他相邻的点
    StateOfVertexBlack  // 他和他的邻居都访问过
} StateOfVertex ;

const int MaxVertexCount = 100 ;

/*
 test case:
 5
 2 1 2
 1 4
 2 3 4
 1 0
 0
 */

void deepFirstSearch(std::vector<std::vector<int>*> *vector, int *state, int iNode) ;

int mainDeep()
{
    // 每个点对应的状态
    int state[MaxVertexCount] ;
    // 邻接表
    std::vector<std::vector<int>*>* vector = constructGraphFromStandardInput() ;
    int vertexCount = (int)vector->size() ;
    printf("dfs begin\n") ;
    for (int i = 0; i < vertexCount; ++i) {
        state[i] = StateOfVertexWhite ;
    }
    for (int i = 0 ; i < vertexCount; ++i) {
        state[i] = StateOfVertexGray ;
        deepFirstSearch(vector, state, i) ;
    }
    printf("bfs end\n") ;
    freeGraph(vector) ;
    return 0 ;
}

void deepFirstSearch(std::vector<std::vector<int>*> *vector, int *state, int iNode)
{
    std::vector<int> *pVector = (*vector)[iNode] ;
    for (int i = 0; i < pVector->size(); ++i) {
        int neighbor = (*pVector)[i] ;
        if (state[neighbor] == StateOfVertexWhite) {
            state[neighbor] = StateOfVertexGray ;
            printf("dfs %d->%d\n", iNode, neighbor) ;
            deepFirstSearch(vector, state, neighbor) ;
        }
    }
    state[iNode] = StateOfVertexBlack ;
}



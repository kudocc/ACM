//
//  breadthFirstSearch.cpp
//  console
//
//  Created by yuanrui on 15-4-10.
//  Copyright (c) 2015年 KudoCC. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <deque>

typedef enum {
    StateOfVertexWhite, // 没有被访问过
    StateOfVertexGray,  // 被访问过，但是还没有访问他相邻的点
    StateOfVertexBlack  // 他和他的邻居都访问过
} StateOfVertex ;

const int MaxVertexCount = 100 ;

int main()
{
    // 每个点对应的状态
    int state[MaxVertexCount] ;
    // 邻接表
    std::vector<std::vector<int>*> vector ;
    int vertexCount = 0 ;
    scanf("%d", &vertexCount) ;
    for (int i = 0 ; i < vertexCount; ++i) {
        int neighborCount = 0 ;
        std::vector<int> *list = new std::vector<int>() ;
        scanf("%d", &neighborCount) ;
        for (int j = 0; j < neighborCount; ++j) {
            int neighbor = 0 ;
            scanf("%d", &neighbor) ;
            list->push_back(neighbor) ;
        }
        vector.push_back(list) ;
    }
    printf("bfs begin\n") ;
    for (int i = 0; i < vertexCount; ++i) {
        state[i] = StateOfVertexWhite ;
    }
    std::deque<int> queue ;
    queue.push_back(0) ;
    state[0] = StateOfVertexGray ;
    while (queue.size() > 0) {
        int index = queue.front() ;
        queue.pop_front() ;
        std::vector<int> *list = vector[index] ;
        for (int i = 0; i < list->size(); ++i) {
            int neighbor = (*list)[i] ;
            if (state[neighbor] == StateOfVertexWhite) {
                printf("edge %d -> %d\n", index, neighbor) ;
                queue.push_back(neighbor) ;
                state[neighbor] = StateOfVertexGray ;
            }
        }
        state[index] = StateOfVertexBlack ;
    }
    printf("bfs end\n") ;
    
    for (int i = 0; i < vector.size(); ++i) {
        std::vector<int> *list = vector[i] ;
        delete list ;
    }
    return 0 ;
}
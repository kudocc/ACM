//
//  adjacencyList.cpp
//  console
//
//  Created by yuanrui on 15-4-13.
//  Copyright (c) 2015年 KudoCC. All rights reserved.
//

#include "adjacencyList.h"

std::vector<std::vector<int>*>* constructGraphFromStandardInput()
{
    // 邻接表
    std::vector<std::vector<int>*> *vector = new std::vector<std::vector<int>*>() ;
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
        vector->push_back(list) ;
    }
    return vector ;
}

void freeGraph(std::vector<std::vector<int>*>* vector)
{
    for (int i = 0; i < vector->size(); ++i) {
        std::vector<int> *list = (*vector)[i] ;
        delete list ;
    }
    delete vector ;
}

std::vector<std::vector<AdjacencyElement>*>* constructGraphFromStandardInputWithMultipleWeight()
{
    std::vector<std::vector<AdjacencyElement>*> *vector = new std::vector<std::vector<AdjacencyElement>*>() ;
    int vertexCount = 0 ;
    scanf("%d", &vertexCount) ;
    for (int i = 0 ; i < vertexCount; ++i) {
        int neighborCount = 0 ;
        std::vector<AdjacencyElement> *list = new std::vector<AdjacencyElement>() ;
        scanf("%d", &neighborCount) ;
        for (int j = 0; j < neighborCount; ++j) {
            int neighbor = 0 ;
            int weight = 0 ;
            scanf("%d %d", &neighbor, &weight) ;
            AdjacencyElement element ;
            element.neighbor = neighbor ;
            element.weight = weight ;
            list->push_back(element) ;
        }
        vector->push_back(list) ;
    }
    return vector ;
}

void freeGraphWithMultipleWeight(std::vector<std::vector<AdjacencyElement>*> *vector)
{
    for (int i = 0; i < vector->size(); ++i) {
        std::vector<AdjacencyElement> *list = (*vector)[i] ;
        delete list ;
    }
    delete vector ;
}


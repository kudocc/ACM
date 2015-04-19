//
//  adjacencyList.h
//  console
//
//  Created by yuanrui on 15-4-13.
//  Copyright (c) 2015年 KudoCC. All rights reserved.
//

#ifndef __console__adjacencyList__
#define __console__adjacencyList__

#include <stdio.h>
#include <vector>

struct AdjacencyElement {
    int neighbor ;
    int weight ;
} ;

std::vector<std::vector<int>*>* constructGraphFromStandardInput() ;
void freeGraph(std::vector<std::vector<int>*> *vector) ;

std::vector<std::vector<AdjacencyElement>*>* constructGraphFromStandardInputWithMultipleWeight() ;
void freeGraphWithMultipleWeight(std::vector<std::vector<AdjacencyElement>*> *vector) ;

#endif /* defined(__console__adjacencyList__) */

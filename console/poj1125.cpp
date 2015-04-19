#include <stdlib.h>
#include "common.h"
#include "priorityQueue.h"
#include <vector>

using namespace std ;

int mainPOJ1125()
{
    int graph[101][101] ;
    while (1) {
        int stockerNumber = 0 ;
        scanf("%d", &stockerNumber) ;
        if (stockerNumber == 0) {
            break ;
        }
        // init the graph to -1
        for (int i = 0; i <= stockerNumber; ++i) {
            for (int j = 0; j < stockerNumber; ++j) {
                if (i == j) {
                    graph[i][j] = 0 ;
                } else {
                    graph[i][j] = INT_MAX ;
                }
            }
        }
        // construct the graph
        for (int stockerIndex = 1; stockerIndex <= stockerNumber; ++stockerIndex) {
            int contacts = 0 ;
            scanf("%d", &contacts) ;
            for (int i = 0; i < contacts; ++i) {
                int contactsIndex = 0 ;
                int time = 0 ;
                scanf("%d%d", &contactsIndex, &time) ;
                graph[stockerIndex][contactsIndex] = time ;
            }
        }
        int *distance = (int *)malloc(sizeof(int)*(stockerNumber+1)) ;
        int minPath = INT_MAX ;
        int sourceIndex = INT_MIN ;
        for (int stockerIndex = 1; stockerIndex <= stockerNumber; ++stockerIndex) {
            int source = stockerIndex ;
            // init the distance
            for (int i = 1 ; i <= stockerNumber; ++i) {
                distance[i] = INT_MAX ;
            }
            distance[source] = 0 ;
            
            vector<PriorityQueueObject *> vecterPQO ;
            CPriorityQueue priorityQue = CPriorityQueue(stockerNumber) ;
            for (int i = 1; i <= stockerNumber; ++i) {
                PriorityQueueObject *obj = new PriorityQueueObject ;
                // element is index of stocker
                obj->element = i ;
                obj->priority = distance[i] ;
                priorityQue.enqueue(obj) ;
                vecterPQO.push_back(obj) ;
            }
            
            while (priorityQue.getSize() > 0) {
                PriorityQueueObject *obj = priorityQue.extractMin() ;
                int indexMin = obj->element ;
                int distanceMin = obj->priority ;
                if (distanceMin == INT_MAX) {
                    // disjoint and free left objects
                    break ;
                }
                // enumerate all the edges that indexMin connects to
                for (int i = 1; i <= stockerNumber; ++i) {
                    if (graph[indexMin][i] > 0 && graph[indexMin][i] != INT_MAX) {
                        // get rid of self and the one has no edge with indexMin
                        if (distance[i] > distanceMin + graph[indexMin][i]) {
                            // relex the edge
                            distance[i] = distanceMin + graph[indexMin][i] ;
                            PriorityQueueObject *objRelax = vecterPQO[i-1] ;
                            objRelax->priority = distance[i] ;
                            priorityQue.decreaseObj(objRelax) ;
                        }
                    }
                }
            }
            
            int maxPathForSepSource = distance[1] ;
            for (int i = 1; i <= stockerNumber; ++i) {
                maxPathForSepSource = distance[i] > maxPathForSepSource ? distance[i] : maxPathForSepSource ;
            }
            if (maxPathForSepSource < minPath) {
                minPath = maxPathForSepSource ;
                sourceIndex = source ;
            }
            
            // free
            vector<PriorityQueueObject *>::iterator iter ;
            for (iter = vecterPQO.begin(); iter != vecterPQO.end(); iter++) {
                PriorityQueueObject *obj = *iter ;
                delete obj ;
            }
            vecterPQO.clear() ;
        }
        if (minPath == INT_MAX) {
            printf("disjoint\n") ;
        } else {
            printf("%d %d\n", sourceIndex, minPath) ;
        }
        free(distance) ;
    }
	return 0;
}
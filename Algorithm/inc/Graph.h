#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "Global.h"

typedef struct GrapgAdjacencyMatrixSt 
{ 
  int nodeCount;
  int **connects;
} GrapgAdjacencyMatrix; 

extern GrapgAdjacencyMatrix adjacencyMatrix;

extern void AdjacencyMatrixInit(int nodeCount);
extern void AdjacencyMatrixFree();
extern void AdjacencyMatrixCreate(int **nodeConns, int count);
extern void AdjacencyMatrixWithWeightCreate(int **nodeConns, int count);
extern void AdjacencyMatrixPrint();

extern int GraphCycleDetect(int **nodeConns, int count, int totalVetex);

#endif ///<  __GRAPH_H__

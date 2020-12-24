#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "Global.h"

typedef struct GrapgAdjacencyMatrixSt 
{ 
  int nodeCount;
  int **connects;
} GrapgAdjacencyMatrix; 

extern void AdjacencyMatrixInit(int nodeCount);
extern void AdjacencyMatrixFree();
extern void CreateAdjacencyMatrix(int **nodeConns, int count);
extern void AdjacencyMatrixPrint();
#endif ///<  __GRAPH_H__

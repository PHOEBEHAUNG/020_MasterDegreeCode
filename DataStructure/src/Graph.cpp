#include "Global.h"

GrapgAdjacencyMatrix adjacencyMatrix;

void AdjacencyMatrixInit(int nodeCount)
{
  adjacencyMatrix.nodeCount = nodeCount;
  adjacencyMatrix.connects  =  (int **) malloc(sizeof(int*)* nodeCount);

  for(int i = 0; i < nodeCount; i++)
  {
    adjacencyMatrix.connects[i] = (int *) malloc(sizeof(int)* nodeCount);
  }
}

void AdjacencyMatrixFree()
{
  for(int i = 0; i < adjacencyMatrix.nodeCount; i++)
  {
    free(adjacencyMatrix.connects[i]);
  }
  free(adjacencyMatrix.connects);
  adjacencyMatrix.nodeCount = 0;
}

void CreateAdjacencyMatrix(int **nodeConns, int count)
{
  if(nodeConns == NULL)
  {
    return;
  }
  int point1 = -1;
  int point2 = -1;

  for(int i = 0; i < count; i++)
  {
    if(nodeConns[i] == NULL)
    {
      continue;
    }
    point1 = nodeConns[i][0];
    point2 = nodeConns[i][1];

    printf("Add %d = (%d, %d)\n", i, point1, point2);
    adjacencyMatrix.connects[point1][point2] = 1;
    //無方向圖
    adjacencyMatrix.connects[point2][point1] = 1;
  }
}

void AdjacencyMatrixPrint()
{
  printf("Adjacency Matrix Print \n");
  for(int i = 0; i < adjacencyMatrix.nodeCount; i++)
  {
    for(int j = 0; j < adjacencyMatrix.nodeCount; j++)
    {
      printf("%d ", adjacencyMatrix.connects[i][j]);
    }
    printf("\n");
  }
  printf("========================================== \n");
}
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

void AdjacencyMatrixCreate(int **nodeConns, int count)
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

void AdjacencyMatrixWithWeightCreate(int **nodeConns, int count)
{
  if(nodeConns == NULL)
  {
    return;
  }
  int point1 = -1;
  int point2 = -1;
  int weight = -1;

  for(int i = 0; i < count; i++)
  {
    if(nodeConns[i] == NULL)
    {
      continue;
    }
    point1 = nodeConns[i][0];
    point2 = nodeConns[i][1];
    weight = nodeConns[i][2];

    printf("Add %d = (%d, %d)\n", i, point1, point2);
    adjacencyMatrix.connects[point1][point2] = weight;
    //無方向圖
    adjacencyMatrix.connects[point2][point1] = weight;
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

int find(int *parent, int i)
{
  if (parent[i] == -1)
  {
    return i;
  }
  return find(parent, parent[i]);
}

void Union(int parent[], int x, int y)
{
    int x1 = find(parent, x);
    int y1 = find(parent, y);
    if(x1 != y1)
    {
      parent[x1] = y1;
    }
}

int GraphCycleDetect(int **nodeConns, int count, int totalVetex)
{
  if(count <= 1)
  {
    return 0;
  }

  int *parent = (int*) malloc(totalVetex * sizeof(int));
  for(int i = 0; i < totalVetex; i++)
  {
    parent[i] = -1;
  }
  for(int i = 0; i < count; i++)
  { 
    int v1 = find(parent, nodeConns[i][0]);
    int v2 = find(parent, nodeConns[i][1]);
    if(v1 == v2)
    {
      return 1;
    }  
    Union(parent, v1, v2);
  }
  free(parent);
  return 0;
}

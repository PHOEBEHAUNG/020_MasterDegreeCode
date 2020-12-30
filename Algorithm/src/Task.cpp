#include "Global.h"

#define NUM_LINE 2
#define NUM_STATION 4

int AssemblyLineScheduling()
{
    int a[][NUM_STATION] = {{4, 5, 3, 2}, {2, 10, 1, 4}};
    int t[][NUM_STATION] = {{0, 7, 4, 5}, {0, 9, 2, 8}};
    int e[] = {10, 12};
    int x[] = {18, 7};

    int T1[NUM_STATION], T2[NUM_STATION], i;

    T1[0] = e[0] + a[0][0]; // time taken to leave first station in line 1
    T2[0] = e[1] + a[1][0]; // time taken to leave first station in line 2
 
    // Fill tables T1[] and T2[] using the above given recursive relations
    for (i = 1; i < NUM_STATION; ++i)
    {
        T1[i] = fmin(T1[i-1] + a[0][i], T2[i-1] + t[1][i] + a[0][i]);
        T2[i] = fmin(T2[i-1] + a[1][i], T1[i-1] + t[0][i] + a[1][i]);
    }
 
    // Consider exit times and retutn minimum
    return fmin(T1[NUM_STATION-1] + x[0], T2[NUM_STATION-1] + x[1]);
}

/**
 * for min spanning tree
 * 每次挑選最小邊，若有聯通則不加入邊的集合
 */
int KruskalAlgorithm()
{
    int connectCount = 10;
    int vetexCount = 6;
    int connect[10][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 4}, {2, 3}, {2, 4}, {2, 5}, {3, 5}, {4, 5}};
    /// 0 : v1, 1 : v2, 2 : weight, 3 : status (-1 : connected, 0 : hasn't searched 1 : added)
    int connectWithWeight[10][4] = {{0, 1, 6, 0}, 
                                    {0, 2, 1, 0}, 
                                    {0, 3, 5, 0}, 
                                    {1, 2, 5, 0}, 
                                    {1, 4, 3, 0}, 
                                    {2, 3, 5, 0}, 
                                    {2, 4, 6, 0}, 
                                    {2, 5, 4, 0}, 
                                    {3, 5, 2, 0}, 
                                    {4, 5, 6, 0}};
    int *p[10];

    int findEdge[10][3]; 
    int *pFind[10];
    int findCount = 0;
    
    for(int i = 0; i < connectCount; i++)
    {
        p[i] = connectWithWeight[i];
    }

    for(int i = 0; i < connectCount; i++)
    {
        pFind[i] = findEdge[i];
    }

    AdjacencyMatrixInit(vetexCount);
    AdjacencyMatrixWithWeightCreate(p, connectCount);
    AdjacencyMatrixPrint();

    /// Method 1 
    int minimun = INT32_MAX;
    while(1)
    {
        if(findCount >= connectCount)
        {
            break;
        }

        int tempMin = INT32_MAX;
        int findIdx = -1;
        /// 找到此次最小的邊
        for(int i = 0; i < connectCount; i++)
        {   
            /// 如果之前連通或已加入則不做比較
            if(connectWithWeight[i][3] != 0)
            {
                continue;
            }
            if(tempMin > connectWithWeight[i][2])
            {
                tempMin = connectWithWeight[i][2];
                memcpy(findEdge[findCount], connectWithWeight[i], sizeof(int) * 3);
                findIdx = i;
                printf("Find Edge [%d]: %d, %d, %d\n", findIdx, findEdge[findCount][0], findEdge[findCount][1], findEdge[findCount][2]);
            }
        }

        /// 所有邊都被標註為"找過" 或是 “連通” 
        if(findIdx == -1)
        {
            printf("沒有找到可加入邊");
            break;
        }
        /// 沒有連通
        if(GraphCycleDetect(pFind, findCount + 1, vetexCount) == 0)
        {   
            printf("加入 [%d]: %d, %d, %d\n", findIdx, findEdge[findCount][0], findEdge[findCount][1], findEdge[findCount][2]);
            connectWithWeight[findIdx][3] = 1;
            minimun = tempMin;
            findCount++;
        }
        else
        {
            printf("連通 [%d]: %d, %d, %d\n", findIdx, findEdge[findCount][0], findEdge[findCount][1], findEdge[findCount][2]);
            connectWithWeight[findIdx][3] = -1;
        }
    }

    printf("Minimun Spanning Tree \n");
    for(int i = 0; i < findCount; i++)
    {   
        printf("[%d]: %d, %d, %d\n", i, findEdge[i][0], findEdge[i][1], findEdge[i][2]);
    }
    printf("========================================================================\n");
    AdjacencyMatrixFree();
    return 0;
}

/**
 * for min spanning tree
 * 以節點來思考
 */
int PrimesAlgorithm()
{
    int connectCount = 10;
    int vetexCount = 6;
    int connect[10][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 4}, {2, 3}, {2, 4}, {2, 5}, {3, 5}, {4, 5}};
    /// 0 : v1, 1 : v2, 2 : weight, 3 : status (-1 : connected, 0 : hasn't searched 1 : added)
    int connectWithWeight[10][4] = {{0, 1, 6, 0}, 
                                    {0, 2, 1, 0}, 
                                    {0, 3, 5, 0}, 
                                    {1, 2, 5, 0}, 
                                    {1, 4, 3, 0}, 
                                    {2, 3, 5, 0}, 
                                    {2, 4, 6, 0}, 
                                    {2, 5, 4, 0}, 
                                    {3, 5, 2, 0}, 
                                    {4, 5, 6, 0}};
    int searchMatrix[6][6];
    int *p[10];

    int findEdge[10][3]; 
    int findVetex[6]; 
    int *pFind[10];
    int findCount = 0;
    
    for(int i = 0; i < vetexCount; i++)
    {
        for(int j = 0; j < vetexCount; j++)
        {
            searchMatrix[i][j] = 0;
        }
    }

    for(int i = 0; i < connectCount; i++)
    {
        p[i] = connectWithWeight[i];
    }

    for(int i = 0; i < connectCount; i++)
    {
        pFind[i] = findEdge[i];
    }

    AdjacencyMatrixInit(vetexCount);
    AdjacencyMatrixWithWeightCreate(p, connectCount);
    AdjacencyMatrixPrint();

    /// Method 1 
    int minimun = INT32_MAX;
    int startV = 1;
    findVetex[findCount] = startV;
    while(1)
    {
        if(findCount >= connectCount)
        {
            break;
        }

        int tempMin = INT32_MAX;
        int findV = -1;
        
        int v1 = -1;
        int v2 = -1;
        for(int i = 0; i < (findCount + 1); i++)
        {
            for(int j = 0; j < vetexCount; j++)
            {
                if(findVetex[i] == j)
                {
                    continue;
                }

                if(searchMatrix[findVetex[i]][j] != 0)
                {
                    continue;
                }

                if(adjacencyMatrix.connects[findVetex[i]][j] == 0)
                {
                    continue;
                }

                if(tempMin > adjacencyMatrix.connects[findVetex[i]][j])
                {
                    tempMin = adjacencyMatrix.connects[findVetex[i]][j];
                    v1 = findVetex[i];
                    v2 = j;
                    findV = v2;
                }
            }
        }

        pFind[findCount][0] = v1;
        pFind[findCount][1] = v2;
        pFind[findCount][2] = tempMin;

        /// 所有點都被加入 
        if(findV == -1)
        {
            printf("沒有找到可加入點\n");
            break;
        }
        /// 沒有連通
        if(GraphCycleDetect(pFind, findCount + 1, vetexCount) == 0)
        {   
            printf("加入 [%d]: %d, %d, %d\n", findV, findEdge[findCount][0], findEdge[findCount][1], findEdge[findCount][2]);
            searchMatrix[v1][v2] = 1;
            minimun = tempMin;
            findCount++;
            findVetex[findCount] = v2; 
        }
        else
        {
            printf("連通 [%d]: %d, %d, %d\n", findV, findEdge[findCount][0], findEdge[findCount][1], findEdge[findCount][2]);
            searchMatrix[v1][v2] = -1;
        }
    }

    printf("Minimun Spanning Tree \n");
    for(int i = 0; i < findCount; i++)
    {   
        printf("[%d]: %d, %d, %d\n", i, findEdge[i][0], findEdge[i][1], findEdge[i][2]);
    }
    printf("========================================================================\n");
    AdjacencyMatrixFree();
    return 0;
}

/**
 * for min spanning tree
 * 把節點當成樹來思考
 * 
 */
int SollinAlgorithm()
{
    int connectCount = 10;
    int vetexCount = 6;
    int connect[10][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 4}, {2, 3}, {2, 4}, {2, 5}, {3, 5}, {4, 5}};
    /// 0 : v1, 1 : v2, 2 : weight, 3 : status (-1 : connected, 0 : hasn't searched 1 : added)
    int connectWithWeight[10][4] = {{0, 1, 6, 0}, 
                                    {0, 2, 1, 0}, 
                                    {0, 3, 5, 0}, 
                                    {1, 2, 5, 0}, 
                                    {1, 4, 3, 0}, 
                                    {2, 3, 5, 0}, 
                                    {2, 4, 6, 0}, 
                                    {2, 5, 4, 0}, 
                                    {3, 5, 2, 0}, 
                                    {4, 5, 6, 0}};
    int searchMatrix[6][6];
    int *p[10];

    int findEdge[10][3]; 
    int findVetex[6]; 
    int *pFind[10];
    int findCount = 0;
    
    for(int i = 0; i < vetexCount; i++)
    {
        for(int j = 0; j < vetexCount; j++)
        {
            searchMatrix[i][j] = 0;
        }
    }

    for(int i = 0; i < connectCount; i++)
    {
        p[i] = connectWithWeight[i];
    }

    for(int i = 0; i < connectCount; i++)
    {
        pFind[i] = findEdge[i];
    }

    AdjacencyMatrixInit(vetexCount);
    AdjacencyMatrixWithWeightCreate(p, connectCount);
    AdjacencyMatrixPrint();

    /// Method 1 
    /// TODO
    
    printf("Minimun Spanning Tree \n");
    for(int i = 0; i < findCount; i++)
    {   
        printf("[%d]: %d, %d, %d\n", i, findEdge[i][0], findEdge[i][1], findEdge[i][2]);
    }
    printf("========================================================================\n");
    AdjacencyMatrixFree();
    return 0;
}
 
 
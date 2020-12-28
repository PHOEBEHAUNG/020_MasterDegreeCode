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
    return 0;
}

/**
 * for min spanning tree
 * 
 */
int PrimesAlgorithm()
{
    return 0;
}

/**
 * for min spanning tree
 * 
 */
int SollinAlgorithm()
{
    return 0;
}
 
 
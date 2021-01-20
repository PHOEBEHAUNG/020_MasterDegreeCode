#ifndef __TASK_H__
#define __TASK_H__

#include "Global.h"

extern int AssemblyLineScheduling();
extern int KruskalAlgorithm();
extern int PrimesAlgorithm();
extern int SollinAlgorithm();

extern int DijkstrasShortestPathOnetoAll();
extern int FloydWarshallShortestPathAlltoAll();
extern int BellmanShortestPathOnetoAll();

extern void TaskSorting();
extern void TaskSearching();
#endif ///<  __TASK_H__

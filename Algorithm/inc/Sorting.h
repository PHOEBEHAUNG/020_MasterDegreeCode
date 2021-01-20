#ifndef __SORTING_H__
#define __SORTING_H__

#include "Global.h"

extern void InsertionSorting(int *datas, int cnt, int order);
extern void BubbleSorting(int *datas, int cnt, int order);
extern void SelectionSorting(int *datas, int cnt, int order);
extern void QuickSorting(int *datas, int cnt, int order);
extern void MergeSorting(int *datas, int cnt, int order);
extern void HeapSorting(int *datas, int cnt, int order);
extern void RadixSorting(int *datas, int cnt, int order);

#endif ///<  __SORTING_H__

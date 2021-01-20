#include "Global.h"

int LinearSearching(int *datas, int cnt, int target)
{
  int i = 0;
  int result = -1;

  for(i = 0; i < cnt; i++)
  {
    if(datas[i] == target)
    {
      result = i;
      break;
    }
  }
  return result;
}

void BinarySearching(int *datas, int cnt, int target)
{
  
}

void FibonacciSearching(int *datas, int cnt, int target)
{
  
}

void InterpolationSearching(int *datas, int cnt, int target)
{
  
}


#include "Global.h"

///=========================================================///
/// Stack
///=========================================================///
IntStack intStack;
void StackInit(int maxCount)
{
  intStack.maxCount = maxCount;
  intStack.count    = 0;
  intStack.data     = (int *)malloc(maxCount * sizeof(int));
  intStack.tail     = intStack.data;
}

void StackPush(int value)
{
  if(intStack.count >= (intStack.maxCount - 1))
  {
    return; 
  }

  int checkValue = 0;

  memcpy(intStack.tail, &value, sizeof(int));
  memcpy(&checkValue, intStack.tail, sizeof(int));
  //printf("StackPush (%d) %d\n", intStack.tail, checkValue);
  intStack.count++;
  intStack.tail = intStack.data + intStack.count * 1;
}

int StackPop()
{
  if(intStack.count <= 0)
  {
    return 0;
  }

  int value;

  intStack.tail = intStack.tail - 1;

  memcpy(&value, intStack.tail, sizeof(int));
  //printf("StackPop : %d\n", value);
  //printf("StackPop Cnt : %d\n", intStack.count);
  intStack.count--;
  return value;
}

void StackClear()
{
  memset(intStack.data, 0, intStack.maxCount * sizeof(int));
  intStack.tail = intStack.data; 
  intStack.count = 0;
}

void StackUninit()
{
  intStack.maxCount = 0;
  intStack.count    = 0;
  intStack.tail     = NULL;
  free(intStack.data);
}

void PrintMyStack(IntStack intStack)
{
  printf("Stack start\n");
  for(int i = 0; i < intStack.count; i++)
  {
    printf("%d\n", intStack.data[i]);
  }
  printf("Stack end\n");
}
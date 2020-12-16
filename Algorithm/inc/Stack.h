#ifndef __STACK_H__
#define __STACK_H__

#include "Global.h"
typedef struct IntStackSt
{
  int maxCount;
  int count;
  int *data;
  int *tail;
}IntStack;

extern IntStack intStack;

extern void StackInit(int maxCount);
extern void StackPush(int value);
extern int StackPop();
extern void StackClear();
extern void StackUninit();

extern void PrintMyStack(IntStack intStack);

#endif ///<  __STACK_H__

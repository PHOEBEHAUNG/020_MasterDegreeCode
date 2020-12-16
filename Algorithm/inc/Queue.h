#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "Global.h"

typedef struct IntQueueSt
{
  int maxCount;
  int count;
  int *head;
}IntQueue;

extern void QueueInit(int maxCount);
extern void QueueEnqueue(int value);
extern int QueueDequeue();
extern void QueueClear();
#endif ///<  __QUEUE_H__

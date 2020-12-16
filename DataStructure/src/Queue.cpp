#include "Global.h"

///=========================================================///
/// Int Queue
///=========================================================///
IntQueue nodeQueue;
void QueueInit(int maxCount)
{
  nodeQueue.maxCount = maxCount;
  nodeQueue.count    = 0;
  nodeQueue.head     = (int *)malloc(maxCount * sizeof(int));
}

void QueueEnqueue(int value)
{
  if(nodeQueue.count >= (nodeQueue.maxCount - 1))
  {
    return; 
  }
  int checkValue = 0;
  int *address = nodeQueue.head + nodeQueue.count * sizeof(int);
  memcpy(address, &value, sizeof(int));

  memcpy(&checkValue, address, sizeof(int));
  printf("QueuePush %d\n", checkValue);
  nodeQueue.count++;
}

int QueueDequeue()
{
  if(nodeQueue.count <= 0)
  {
    return 0;
  }

  int value;
  memcpy(&value, nodeQueue.head, sizeof(int));
  printf("CHECCK ADDRESS : %d\n", value);
  printf("QueuePop Cnt : %d\n", nodeQueue.count);
  nodeQueue.count--;

  for(int i = 0; i < nodeQueue.count; i++)
  {
    memcpy(nodeQueue.head + i * 4, nodeQueue.head + 4 * (i + 1), 4);
  }
  printf("QueuePop : %d\n", value);
  return value;
}

void QueueClear()
{
  memset(nodeQueue.head, 0, nodeQueue.maxCount * sizeof(int));
  nodeQueue.count = 0;
}

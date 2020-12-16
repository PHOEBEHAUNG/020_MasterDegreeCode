#include "Global.h"

int QueueMain()
{
  return 0;
}

int StackMain()
{
  int iArrElement[7] = {3,9,20,-1000,-1000,15,7};
  int elementSize = sizeof(iArrElement) / sizeof(int);

  int popVal = 0;
  StackInit(20);

  StackPush(iArrElement[0]);
  PrintMyStack(intStack);
  StackPush(iArrElement[1]);
  PrintMyStack(intStack);
  StackPush(iArrElement[2]);
  PrintMyStack(intStack);
  StackPush(iArrElement[3]);
  PrintMyStack(intStack);
  popVal = StackPop();
  PrintMyStack(intStack);
  popVal = StackPop();
  PrintMyStack(intStack);
  popVal = StackPop();
  PrintMyStack(intStack);
  popVal = StackPop();
  
  return 0;                           
}

int LinkedListMain()
{
  int iArrElement[7] = {3,9,20,-1000,-1000,15,7};
  int elementSize = sizeof(iArrElement) / sizeof(int);

  int delVal = 0;
  LinkedListInit(iArrElement[0]);
  LinkedListPush(iArrElement[1]);
  LinkedListPush(iArrElement[2]);
  LinkedListPush(iArrElement[3]);
  PrintMyLinkedLis();

  LinkedListInsertHead(iArrElement[5]);
  LinkedListPop();
  PrintMyLinkedLis();

  LinkedListPush(iArrElement[6]);
  PrintMyLinkedLis();

  LinkedListPop();
  PrintMyLinkedLis();

  LinkedListUnInit();
  PrintMyLinkedLis();

  LinkedListInit(iArrElement[0]);
  LinkedListPush(iArrElement[1]);
  LinkedListPush(iArrElement[2]);
  LinkedListPush(iArrElement[3]);
  LinkedListPush(iArrElement[4]);
  LinkedListPush(iArrElement[5]);
  LinkedListPush(iArrElement[6]);
  PrintMyLinkedLis();

  LinkedListNode * insert = NULL;
  insert = LinkedListGetByIndex(3);
  LinkedListInsertAfter(insert, 100);
  PrintMyLinkedLis();

  LinkedListDeleteByKey(20);
  PrintMyLinkedLis();

  LinkedListUnInit();
  PrintMyLinkedLis();
  return 0;            
}

int BinaryTreeMain()
{
  /// NULL is represented for -1000
  int iArrElement[7] = {1,2,3,4,5,6,7};

  int elementSize = sizeof(iArrElement) / sizeof(int);
  printf("TreeCreate Element Size : %d\n", elementSize);

  for(int i = 0; i < elementSize; i++) 
  { 
    AddToTreeByLevelOrderTraversal(iArrElement[i]); 
  }

  PrintMyTreeByLevelOrderTraversal(Root);

  int depth = MaxDepth(Root);
  printf("Tree Depth : %d \n", depth);

  return 0;
}
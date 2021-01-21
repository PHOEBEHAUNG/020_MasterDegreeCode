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
  PrintMyLinkedList();

  LinkedListInsertHead(iArrElement[5]);
  LinkedListPop();
  PrintMyLinkedList();

  LinkedListPush(iArrElement[6]);
  PrintMyLinkedList();

  LinkedListPop();
  PrintMyLinkedList();

  LinkedListUnInit();
  PrintMyLinkedList();

  LinkedListInit(iArrElement[0]);
  LinkedListPush(iArrElement[1]);
  LinkedListPush(iArrElement[2]);
  LinkedListPush(iArrElement[3]);
  LinkedListPush(iArrElement[4]);
  LinkedListPush(iArrElement[5]);
  LinkedListPush(iArrElement[6]);
  PrintMyLinkedList();

  LinkedListNode * insert = NULL;
  insert = LinkedListGetByIndex(3);
  LinkedListInsertAfter(insert, 100);
  PrintMyLinkedList();

  LinkedListDeleteByKey(20);
  PrintMyLinkedList();

  LinkedListUnInit();
  PrintMyLinkedList();
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

/*
      1
     / \
    /   \
   2     3
  / \   /
 4   5 6
*/
void TaskFindBinaryTreeByPreorderInorder()
{
  int in[]   = {4, 2, 5, 1, 6, 3};

  int pre[]  = {1, 2, 4, 5, 3, 6};
  int post[] = {4, 5, 2, 6, 3, 1};

  //FindBinaryTreeByPreorderInorder(pre, in, 6);
  printf("===================\n");
  FindBinaryTreeByPostorderInorder(post, in, 6);
}

int TaskGraphMain()
{
  int connectCount = 6;
  int connect[6][2] = {{0, 5}, {2, 3}, {1, 5}, {3, 4}, {1, 2}, {0, 4}};

  int *p[connectCount];

  for(int i = 0; i < connectCount; i++)
  {
    p[i] = connect[i];
  }

  AdjacencyMatrixInit(6);
  CreateAdjacencyMatrix(p, 6);

  AdjacencyMatrixPrint();
  AdjacencyMatrixFree();
  
  return 0;
}

void TaskLikedListQueue()
{
  int iArrElement[7] = {3,9,20,-1000,-1000,15,7};
  int elementSize = sizeof(iArrElement) / sizeof(int);

  int delVal = 0;

  LinkedListInit(iArrElement[0]);
  LinkedListPush(iArrElement[1]);
  LinkedListPush(iArrElement[2]);
  LinkedListPush(iArrElement[3]);
  PrintMyLinkedList();

  delVal = LinkedListDeleteHead();
  printf("LikedListQueue Head : %d\n", delVal);
  PrintMyLinkedList();

  LinkedListPush(iArrElement[4]);
  LinkedListPush(iArrElement[5]);
  PrintMyLinkedList();

  LinkedListUnInit();
}

void TaskLikedListStack()
{
  int iArrElement[7] = {3,9,20,-1000,-1000,15,7};
  int elementSize = sizeof(iArrElement) / sizeof(int);

  int delVal = 0;
  LinkedListInit(iArrElement[0]);
  LinkedListPush(iArrElement[1]);
  LinkedListPush(iArrElement[2]);
  LinkedListPush(iArrElement[3]);
  PrintMyLinkedList();

  LinkedListPop();
  PrintMyLinkedList();

  LinkedListPush(iArrElement[6]);
  PrintMyLinkedList();

  LinkedListPop();
  PrintMyLinkedList();

  PrintMyLinkedList();

  LinkedListPush(iArrElement[1]);
  LinkedListPush(iArrElement[2]);
  LinkedListPush(iArrElement[3]);
  LinkedListPush(iArrElement[4]);
  LinkedListPush(iArrElement[5]);
  LinkedListPush(iArrElement[6]);
  PrintMyLinkedList();

  LinkedListUnInit();
}

void TaskLickedListMultiStack()
{

}

void TaskLickedListMultiQueue()
{

}

void TaskLikedListDouble()
{
  LinkedListDoubleInit(5);
  LinkedListDoublePush(15);
  LinkedListDoublePush(25);
  LinkedListDoublePush(35);
  LinkedListDoublePush(45);

  LinkedListDoubleDeleteByIndex(3);
  PrintMyLinkedLisDouble();

  LinkedListDoubleDeleteByIndex(1);
  PrintMyLinkedLisDouble();

  LinkedListDoubleUnInit();
  PrintMyLinkedLisDouble();
}

void TaskLikedListCircle()
{
  LinkedListCircleInit(10);

  LinkedListCirclePush(15);
  LinkedListCircleInsertHead(20);
  
  PrintMyLinkedListCircle();
  LinkedListCircleUnInit();

  PrintMyLinkedListCircle();
}

void TaskLikedListPolynomial()
{

}

void TaskLikedListSparseMatrix()
{
  
}
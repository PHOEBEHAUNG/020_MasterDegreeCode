#include "Global.h"

///=========================================================///
/// LinkedListDouble
///=========================================================///
LinkedListDoubleNode *linkedListDoubleHead = NULL;
void LinkedListDoubleInit(int data)
{
  linkedListDoubleHead = (LinkedListDoubleNode *)malloc(sizeof(LinkedListDoubleNode));
  linkedListDoubleHead->data = data;
  linkedListDoubleHead->next = NULL;
  linkedListDoubleHead->previous = NULL;
}

LinkedListDoubleNode* LinkedListDoubleGetByIndex(int index)
{
  LinkedListDoubleNode *p = linkedListDoubleHead;
  return p;
}

/// insert by index
void LinkedListDoublePush(int data)
{
  if(linkedListDoubleHead == NULL)
  {
    return;
  }

  LinkedListDoubleNode *preNode = linkedListDoubleHead;
  while(preNode->next != NULL)
  {
    preNode = preNode->next;
  }

  LinkedListDoubleNode *newNode = (LinkedListDoubleNode *)malloc(sizeof(LinkedListDoubleNode));
  newNode->data = data;
  newNode->next = NULL;
  newNode->previous = preNode;
  preNode->next = newNode;
}

void LinkedListDoubleInsertHead(int data)
{

}

void LinkedListDoubleInsertAfter(LinkedListDoubleNode *preNode, int data)
{

}

/// delete by index 
int LinkedListDoublePop()
{
  return 0;
}

int LinkedListDoubleDeleteHead()
{
  return 0;
}

void LinkedListDoubleDeleteByKey(int key)
{

}

void LinkedListDoubleDeleteByIndex(int index)
{
  if(linkedListDoubleHead == NULL)
  {
    return;
  }

  int count = 0;
  bool find = true;
  LinkedListDoubleNode *p = linkedListDoubleHead;

  while(count < index)
  {
    if(p->next == NULL)
    {
      find = false;
      break;
    }

    p = p->next;
    count = count + 1;
  }

  if(find)
  {
    p->previous->next = p->next;
    p->next->previous = p->previous;

    p->data   = 0;
    free(p);
    p->next = NULL;
    p->previous = NULL;
  }
}

void LinkedListDoubleClear(LinkedListDoubleNode *deleteNode)
{
  if(deleteNode == NULL)
  {
    return;
  }

  LinkedListDoubleNode *preNode = deleteNode;
  LinkedListDoubleClear(deleteNode->next);
  deleteNode->data   = 0;

  free(preNode->next);
  preNode->next = NULL;
}

void LinkedListDoubleUnInit()
{
  LinkedListDoubleClear(linkedListDoubleHead);

  if(linkedListDoubleHead->next == NULL)
  {
    linkedListDoubleHead->data   = 0;
    free(linkedListDoubleHead);
    linkedListDoubleHead = NULL;
  }
}

void PrintMyLinkedLisDouble()
{
  printf("PrintMyLinkedLisDouble start\n");
  
  if(linkedListDoubleHead == NULL)
  {
    printf("PrintMyLinkedLisDouble end\n");
    return;
  }

  LinkedListDoubleNode *p = linkedListDoubleHead;
  while(p)
  {
    printf("..%d..\n", p->data);
    p = p->next;
  }
  printf("PrintMyLinkedLisDouble end\n");
}


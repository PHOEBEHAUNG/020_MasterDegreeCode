#include "Global.h"

///=========================================================///
/// LinkedListCircle
///=========================================================///
LinkedListCircleNode *linkedListCircleHead = NULL;

void LinkedListCircleInit(int data)
{
  linkedListCircleHead = (LinkedListCircleNode *) malloc(sizeof(LinkedListCircleNode));
  linkedListCircleHead->data = data;
  linkedListCircleHead->next = linkedListCircleHead;
}

LinkedListCircleNode* LinkedListCircleGetByIndex(int index)
{
  LinkedListCircleNode *p = linkedListCircleHead;
  return p;
}

/// insert by index
void LinkedListCirclePush(int data)
{
  if(linkedListCircleHead == NULL)
  {
    return;
  }

  LinkedListCircleNode *p = linkedListCircleHead;
  while(p->next != linkedListCircleHead)
  {
    p = p->next;
  }

  LinkedListCircleNode *newNode = (LinkedListCircleNode *)malloc(sizeof(LinkedListCircleNode));
  newNode->next = linkedListCircleHead;
  newNode->data = data;

  p->next = newNode;
}

void LinkedListCircleInsertHead(int data)
{
  if(linkedListCircleHead == NULL)
  {
    return;
  }

  LinkedListCircleNode *p = linkedListCircleHead;
  while(p->next != linkedListCircleHead)
  {
    p = p->next;
  }

  LinkedListCircleNode *newNode = (LinkedListCircleNode *)malloc(sizeof(LinkedListCircleNode));
  newNode->next = linkedListCircleHead;
  newNode->data = data;

  p->next = newNode;
  linkedListCircleHead = newNode; 
}

void LinkedListCircleInsertAfter(int insertAfter, int data)
{

}

/// delete by index 
int LinkedListCirclePop()
{
  return 0;
}

int LinkedListCircleDeleteHead()
{
  return 0;
}

void LinkedListCircleDeleteByKey(int key)
{

}

void LinkedListCircleClear(LinkedListCircleNode *deleteNode)
{
  if(deleteNode == linkedListCircleHead)
  {
    return;
  }

  LinkedListCircleNode *preNode = deleteNode;
  LinkedListCircleClear(deleteNode->next);
  deleteNode->data   = 0;

  free(preNode->next);
  preNode->next = NULL;
}

void LinkedListCircleUnInit()
{
  if(linkedListCircleHead == NULL)
  {
    return;
  }

  LinkedListCircleNode *p       = linkedListCircleHead;
  LinkedListCircleNode *current = linkedListCircleHead;

  /// 和LinkedList不同的是要刪除當下的node，不能先刪除下一個，會造成開頭沒辦法free
  do
  {
    p = current->next;
    free(current);
    current = p;

  }while(p != linkedListCircleHead);
  linkedListCircleHead = NULL;
}

void PrintMyLinkedListCircle()
{
  printf("LinkedLis start\n");
  if(linkedListCircleHead == NULL)
  {
    return;
  }

  LinkedListCircleNode *p = linkedListCircleHead;
  do
  {
    printf("..%d..\n", p->data);
    p = p->next;
  }while(p != linkedListCircleHead);

  printf("LinkedList end\n");
}

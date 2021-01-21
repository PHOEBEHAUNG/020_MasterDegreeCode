#include "Global.h"

///=========================================================///
/// LinkedList
///=========================================================///
LinkedListNode *linkedListHead = NULL;

void LinkedListInit(int data)
{
  linkedListHead         = (LinkedListNode *)malloc(sizeof(LinkedListNode));
  linkedListHead->data   = data;
  linkedListHead->next   = NULL;
}

LinkedListNode* LinkedListGetByIndex(int index)
{
  if(linkedListHead == NULL)
  {
    return NULL;
  }

  LinkedListNode *p = linkedListHead;
  int pos = 0;
  while(pos < index)
  {
    if(p->next == NULL)
    {
      break;
    }
    p = p->next;
    pos ++;
  }

  return p;
}

void LinkedListPush(int data)
{
  if(linkedListHead == NULL)
  {
    return;
  }

  LinkedListNode *p = linkedListHead;
  while(p->next != NULL)
  {
    p = p->next;
  }
  p->next   = (LinkedListNode *)malloc(sizeof(LinkedListNode));
  
  p = p->next;
  p->data   = data;
  p->next = NULL;
}

void LinkedListInsertHead(int data)
{
  if(linkedListHead == NULL)
  {
    return;
  }
  
  LinkedListNode *head = (LinkedListNode *)malloc(sizeof(LinkedListNode));
  head->data = data;
  head->next = linkedListHead;
  linkedListHead = head;
}

void LinkedListInsertAfter(LinkedListNode *preNode, int data)
{
  if(preNode == NULL)
  {
    return;
  }

  LinkedListNode *node = (LinkedListNode *)malloc(sizeof(LinkedListNode));
  node->data = data;
  node->next = preNode->next;
  preNode->next = node;
}

int LinkedListPop()
{
  int delVal = -1000;
  if(linkedListHead == NULL)
  {
    return delVal;
  }

  LinkedListNode *p = linkedListHead;
  LinkedListNode *preNode = NULL;
  while(p->next != NULL)
  {
    preNode = p;
    p = p->next;
  }

  delVal = p->data;

  p->data = 0;
  free(p);

  preNode->next = NULL;
  printf("Delete Data : %d\n", p->data);
  return delVal;
}

int LinkedListDeleteHead()
{
  if(linkedListHead == NULL)
  {
    return -1000;
  }

  int value = 0;
  LinkedListNode *preNode = NULL;
  
  value = linkedListHead->data;
  if(linkedListHead->next == NULL)
  {
    linkedListHead->data = 0;
    free(linkedListHead);
    linkedListHead = NULL;
  }
  else
  {
    preNode = linkedListHead;
    linkedListHead = linkedListHead->next;
    preNode->data = 0;
    free(preNode);
    preNode = NULL;
  }
  return value;
}

void LinkedListDeleteByKey(int key)
{
  if(linkedListHead == NULL)
  {
    return;
  }
  LinkedListNode *preNode = linkedListHead;
  LinkedListNode *node    = linkedListHead;
  LinkedListNode *temp    = linkedListHead;

  int index = 0;
  
  while(node->data != key && node->next != NULL)
  {
    temp = preNode;
    preNode = node;
    node = node->next;
    index ++;
  }

  if(index == 0)
  {
    LinkedListDeleteHead();
    return;
  }

  if(node->data == key)
  {
    preNode->next = node->next;
    node->data = 0;
    node->next = NULL;
    free(node);
    node = NULL;
  }
}

bool LinkedListSearch(int key)
{
  return false;
}

void LinkedListClear(LinkedListNode *deleteNode)
{
  if(deleteNode == NULL)
  {
    return;
  }

  LinkedListNode *preNode = deleteNode;
  LinkedListClear(deleteNode->next);
  deleteNode->data   = 0;

  free(preNode->next);
  preNode->next = NULL;
}

void LinkedListUnInit()
{
  LinkedListClear(linkedListHead);

  if(linkedListHead->next == NULL)
  {
    linkedListHead->data   = 0;
    free(linkedListHead);
    linkedListHead = NULL;
  }
}

void PrintMyLinkedList()
{
  printf("LinkedLis start\n");
  
  if(linkedListHead == NULL)
  {
    printf("LinkedList end\n");
    return;
  }

  LinkedListNode *p = linkedListHead;
  while(p)
  {
    printf("..%d..\n", p->data);
    p = p->next;
  }
  printf("LinkedList end\n");
}
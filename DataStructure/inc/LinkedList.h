#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include "Global.h"

// A linked list node 
typedef struct LinkedListNodeSt 
{ 
  int data;
  LinkedListNodeSt* next; 
}LinkedListNode; 

extern LinkedListNode* linkedListHead;

extern void LinkedListInit(int data);
extern LinkedListNode* LinkedListGetByIndex(int index);

/// insert by index
extern void LinkedListPush(int data);
extern void LinkedListInsertHead(int data);
extern void LinkedListInsertAfter(LinkedListNode *preNode, int data);

/// delete by index 
extern int LinkedListPop();
extern int LinkedListDeleteHead();
extern void LinkedListDeleteByKey(int key);

/// Find Length of a Linked List (Iterative and Recursive)
/// Search an element in a Linked List (Iterative and Recursive)
/// Nth node from the end of a Linked List
/// Write a function that counts the number of times a given int occurs in a Linked List
/// Detect loop in a linked list

extern void LinkedListUnInit();
extern void PrintMyLinkedList();

#endif ///<  __LINKEDLIST_H__

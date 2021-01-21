#ifndef __LINKEDLISTDOUBLE_H__
#define __LINKEDLISTDOUBLE_H__

#include "Global.h"

// A linked list node 
typedef struct LinkedListDoubleNodeSt 
{ 
  int data;
  LinkedListDoubleNodeSt* next; 
  LinkedListDoubleNodeSt* previous; 
}LinkedListDoubleNode; 

extern LinkedListDoubleNode* linkedListDoubleHead;

extern void LinkedListDoubleInit(int data);
extern LinkedListDoubleNode* LinkedListDoubleGetByIndex(int index);

/// insert by index
extern void LinkedListDoublePush(int data);
extern void LinkedListDoubleInsertHead(int data);
extern void LinkedListDoubleInsertAfter(LinkedListDoubleNode *preNode, int data);

/// delete by index 
extern int LinkedListDoublePop();
extern int LinkedListDoubleDeleteHead();
extern void LinkedListDoubleDeleteByKey(int key);
extern void LinkedListDoubleDeleteByIndex(int index);

/// Find Length of a Linked List (Iterative and Recursive)
/// Search an element in a Linked List (Iterative and Recursive)
/// Nth node from the end of a Linked List
/// Write a function that counts the number of times a given int occurs in a Linked List
/// Detect loop in a linked list

extern void LinkedListDoubleUnInit();
extern void PrintMyLinkedLisDouble();

#endif ///<  __LINKEDLISTDOUBLE_H__

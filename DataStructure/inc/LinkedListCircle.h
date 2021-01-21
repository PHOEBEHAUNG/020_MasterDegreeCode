#ifndef __LINKEDLISTCIRCLE_H__
#define __LINKEDLISTCIRCLE_H__

#include "Global.h"

// A linked list node 
typedef struct LinkedListCircleNodeSt 
{ 
  int data;
  LinkedListCircleNodeSt* next; 
}LinkedListCircleNode; 

extern LinkedListCircleNode* linkedListCircleHead;

extern void LinkedListCircleInit(int data);
extern LinkedListCircleNode* LinkedListCircleGetByIndex(int index);

/// insert by index
extern void LinkedListCirclePush(int data);
extern void LinkedListCircleInsertHead(int data);
extern void LinkedListCircleInsertAfter(LinkedListCircleNode *preNode, int data);

/// delete by index 
extern int LinkedListCirclePop();
extern int LinkedListCircleDeleteHead();
extern void LinkedListCircleDeleteByKey(int key);

/// Find Length of a Linked List (Iterative and Recursive)
/// Search an element in a Linked List (Iterative and Recursive)
/// Nth node from the end of a Linked List
/// Write a function that counts the number of times a given int occurs in a Linked List
/// Detect loop in a linked list

extern void LinkedListCircleUnInit();
extern void PrintMyLinkedListCircle();

#endif ///<  __LINKEDLISTCIRCLE_H__

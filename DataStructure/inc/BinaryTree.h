#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include "Global.h"

struct TreeNode 
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  struct TreeNode *next;
};

typedef struct TreeQueue
{
    struct TreeNode **data; //Pointer to a Tree_Node
    struct TreeQueue* next; //Pointer to next Queue_Node
}TreeQueue;

extern TreeNode *Root;
extern TreeQueue *Front;
extern TreeQueue *Rear;

extern TreeNode* connect1(TreeNode* root);
extern TreeNode* connect2(TreeNode* root);
extern int MaxDepth(TreeNode* root);

extern void PrintMyTree(TreeNode* x); /// 前序遍歷 Preorder Traversal
extern void PrintMyTreeWithNext(TreeNode* x); /// 前序遍歷 Preorder Traversal /// With next node 

/// 依據應用來Add ，像是大小
extern void AddToTreeByLevelOrderTraversal(int num);

extern void PrintMyTreeByPreorderTraversal(TreeNode* x);
extern void PrintMyTreeByInorderTraversal(TreeNode* x);
extern void PrintMyTreeByPostorderTraversal(TreeNode* x);
extern void PrintMyTreeByLevelOrderTraversal(TreeNode* x);

extern void PrintMyTreeByDFS(TreeNode* x); /// 前中後 三種
extern void PrintMyTreeByBFS(TreeNode* x); /// 層序

#endif ///<  __BINARYTREE_H__

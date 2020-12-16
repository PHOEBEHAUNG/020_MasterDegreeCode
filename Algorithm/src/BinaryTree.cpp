#include "Global.h"

TreeNode *Root=NULL;
TreeQueue *Front=NULL, *Rear=NULL;

/// Populating Next Right Pointers in Each Node
/// 完整二元樹
TreeNode* connect1(TreeNode* root) 
{	
  //Root being null means tree doesn't exist.
  if(root == NULL) 
  {
    return NULL;
  }

  if((root->left != NULL))
  {
    root->left->next = root->right;
  }

  if(root->right != NULL)
  {
    if(root->next != NULL)
    {
      root->right->next = root->next->left;
    }
    else
    {
      root->right->next = NULL;
    }
  }
  
  if(root->right != NULL)
  {
    connect1(root->right);
  }
  
  if(root->left != NULL)
  {
    connect1(root->left);
  }

  return root;
}

/// Populating Next Right Pointers in Each Node II
/// 非完整二元樹
TreeNode* connect2(TreeNode* root) 
{	
  //Root being null means tree doesn't exist.
  if(root == NULL) 
  {
    return NULL;
  }

  /**
   * 如果某節點的next 已經被指定
   * 則往被指定的結的找尋 left & right (next level)
   * 依序找尋 left -> right -> next 
   * 來指定給前一個點的next 
   */
  TreeNode* p = root->next;
  while (p) 
  {
    if (p->left) 
    {
      p = p->left;
      break;
    }
    if (p->right) 
    {
      p = p->right;
      break;
    }
    p = p->next;
  }
  
  if(root->right != NULL)
  {
    root->right->next = p;
  }

  if(root->left != NULL)
  {
    if(root->right != NULL)
    {
      root->left->next = root->right;
    }
    else
    {
      root->left->next = p;
    }
  }
  /// 必須先找到右邊的next 才能指定給左邊的next 
  if(root->right != NULL)
  {
    connect2(root->right);
  }
  
  if(root->left != NULL)
  {
    connect2(root->left);
  }

  return root;
}

int MaxDepth(TreeNode* root)
{
  // Root being null means tree doesn't exist.
  if (root == NULL) 
  {
    return 0;
  }

  // Get the depth of the left and right subtree 
  // using recursion.
  int leftDepth = MaxDepth(root->left); 
  int rightDepth = MaxDepth(root->right); 

  // Choose the larger one and add the root to it.
  if (leftDepth > rightDepth)
  {
    return (leftDepth + 1);
  }        
  else
  {
    return (rightDepth + 1); 
  }          
}

void Enqueue( TreeNode **data)
{
    TreeQueue* temp;
    temp = (TreeQueue*)malloc(sizeof(TreeQueue));
    temp->data = data;
    temp->next = NULL;
    if(Front==NULL)
    { 
        Front = Rear = temp; 
    }
    else
    {
        Rear->next = temp;
        Rear = temp;
    }
}

TreeNode** Dequeue()
{
    if(Rear!=NULL)
    {
        if(!Front->next)
        {
            TreeNode **p;
            p = Front->data;
            free(Front);
            Front=Rear=NULL;
            return p;
        }
        else
        {
            TreeNode **p;
            TreeQueue* q;
            q = Front;
            p = Front->data;
            Front = Front->next;
            free(q);
            return p;
        }
    }
    return NULL;
}

void AddToTreeByLevelOrderTraversal(int num)
{
    if(!Root)
    {
        Root = (TreeNode*)malloc(sizeof(TreeNode));
        Root->val = num;
        Root->left = Root->right = NULL;
        Enqueue(&Root->left);
        Enqueue(&Root->right);
    }
    else
    {
        TreeNode** t;
        t = Dequeue();
        (*t) = (TreeNode*)malloc(sizeof(TreeNode));
        (*t)->val = num;
        (*t)->left = (*t)->right = NULL;
        Enqueue(&(*t)->left);
        Enqueue(&(*t)->right);
    }
}

/// 前序遍歷 Preorder Traversal
void PrintMyTree(TreeNode* x)
{
  if(x)
  {
    if(x->val != -1000)
    {  
      printf("..%d..\n", x->val);
    }
    if(x->left)
    {
      PrintMyTree(x->left);
    }

    if(x->right)
    {
      PrintMyTree(x->right);
    }
  }
}

/// 前序遍歷 Preorder Traversal 
/// With next node 
void PrintMyTreeWithNext(TreeNode* x)
{
  if(x)
  {
    if(x->val != -1000)
    {      
      printf("..%d..\n", x->val);
    }
    if(x->next == NULL)
    {
      printf("..%d..\n", -1000);
    }

    if(x->left)
    {
      PrintMyTreeWithNext(x->left);
    }

    if(x->right)
    {
      PrintMyTreeWithNext(x->right);
    }    
  }
}

///======================================================///
/// 依照root 擺在前中後三個位置來區
///======================================================///
/// 前序遍歷 Preorder Traversal
/// root -> left -> right
void PrintMyTreeByPreorderTraversal(TreeNode* x)
{
  if(x)
  {
    if(x->val != -1000)
    {  
      printf("..%d..\n", x->val);
    }
    if(x->left)
    {
      PrintMyTree(x->left);
    }

    if(x->right)
    {
      PrintMyTree(x->right);
    }
  }
}

/// 中序遍歷 Inorder Traversal
/// left -> root -> right
void PrintMyTreeByInorderTraversal(TreeNode* x)
{
  if(x)
  {
    if(x->left)
    {
      PrintMyTreeByInorderTraversal(x->left);
    }

    if(x->val != -1000)
    {      
      printf("..%d..\n", x->val);
    }

    if(x->right)
    {
      PrintMyTreeByInorderTraversal(x->right);
    }    
  }
}

/// 後序遍歷 Postorder Traversal
/// left -> right -> root
void PrintMyTreeByPostorderTraversal(TreeNode* x)
{
  if(x)
  {
    if(x->left)
    {
      PrintMyTreeByPostorderTraversal(x->left);
    }

    if(x->right)
    {
      PrintMyTreeByPostorderTraversal(x->right);
    } 

    if(x->val != -1000)
    {      
      printf("..%d..\n", x->val);
    }
  }
}

TreeQueue *LevelOrderFront=NULL, *LevelOrderRear=NULL;
void Enqueue2( TreeNode **data)
{
  TreeQueue* temp;
  temp = (TreeQueue*)malloc(sizeof(TreeQueue));
  temp->data = data;
  temp->next = NULL;

  if(LevelOrderFront==NULL)
  { 
    LevelOrderFront = LevelOrderRear = temp; 
  }
  else
  {
    LevelOrderRear->next = temp;
    LevelOrderRear = temp;
  }
}

TreeNode** Dequeue2()
{
  if(LevelOrderRear!=NULL)
  {
    if(!LevelOrderFront->next)
    {
      TreeNode **p;
      p = LevelOrderFront->data;
      free(LevelOrderFront);
      LevelOrderFront = LevelOrderRear = NULL;
      return p;
    }
    else
    {
      TreeNode **p;
      TreeQueue* q;
      q = LevelOrderFront;
      p = LevelOrderFront->data;
      LevelOrderFront = LevelOrderFront->next;
      free(q);
      return p;
    }
  }
  return NULL;
}

int levelNodeConut = 1;
/// 層序遍歷 Level-order Traversal
void PrintMyTreeByLevelOrderTraversal(TreeNode* x)
{
  if(x == NULL)
  {
    return;
  }
  TreeNode** t;
  TreeNode* n = x;
  int count = 1;
  levelNodeConut = 1;
  
  Enqueue2(&n);
  if(n->val != -1000)
  {  
    printf("..%d..\n", n->val);
  }

  while(true)
  {
    if(count == 0)
    {
      break;
    }
    
    count = 0;
    for(int i = 0; i < levelNodeConut; i++)
    {
      t = Dequeue2();
      n = (*t);

      // printf("..%d..\n", n->left->val);
      // printf("..%d..\n", n->right->val);
      
      // n = (*t)->right;
      // printf("..%d..\n", (*t)->val);

      if((*t)->left != NULL)
      {
        Enqueue2(&(*t)->left);
        if((*t)->val != -1000)
        {  
          printf("..%d..\n", (*t)->left->val);
        }
        count ++;
      }

      if((*t)->right != NULL)
      {
        Enqueue2(&(*t)->right);
        if((*t)->val != -1000)
        {  
          printf("..%d..\n", (*t)->right->val);
        }
        count ++;
      }
    }
    levelNodeConut = count;
  }
}

/// 深度優先搜尋 Depth-first Search
/// 亦 前中後序
void PrintMyTreeByDFS(TreeNode* x, int mode)
{

}

/// 廣度優先搜尋 Breath-first Search 
/// 亦 層序遍歷 Level-order Traversal
void PrintMyTreeByBFS(TreeNode* x)
{

}
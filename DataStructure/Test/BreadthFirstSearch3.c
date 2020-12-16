#include <sstream>

// Tree node storing data with two other tree pointers
typedef struct Tree_Node
{
    int data; //data for tree_node
    struct Tree_Node* Left_Child; //pointer to left child
    struct Tree_Node* Right_Child; //pointer to right child
}Tree_Node;

Tree_Node *Root=NULL;
//Queue which will store addresses of Tree_Nodes
typedef struct Queue
{
    struct Tree_Node **data; //Pointer to a Tree_Node
    struct Queue* next; //Pointer to next Queue_Node
}Queue;
Queue *Front=NULL, *Rear=NULL;

void Enqueue( Tree_Node **data)
{
    Queue* temp;
    temp = (Queue*)malloc(sizeof(Queue));
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

Tree_Node** Dequeue()
{
    if(Rear!=NULL)
    {
        if(!Front->next)
        {
            Tree_Node **p;
            p = Front->data;
            free(Front);
            Front=Rear=NULL;
            return p;
        }
        else
        {
            Tree_Node **p;
            Queue* q;
            q = Front;
            p = Front->data;
            Front = Front->next;
            free(q);
            return p;
        }
    }
    return NULL;
}

void AddToTree(int num)
{
    if(!Root)
    {
        Root = (Tree_Node*)malloc(sizeof(Tree_Node));
        Root->data = num;
        Root->Left_Child = Root->Right_Child = NULL;
        Enqueue(&Root->Left_Child);
        Enqueue(&Root->Right_Child);
    }
    else
    {
        Tree_Node** t;
        t = Dequeue();
        (*t) = (Tree_Node*)malloc(sizeof(Tree_Node));
        (*t)->data = num;
        (*t)->Left_Child = (*t)->Right_Child = NULL;
        Enqueue(&(*t)->Left_Child);
        Enqueue(&(*t)->Right_Child);
    }
}

void PrintMyTree(Tree_Node* x)
{
    if(x)
    {
    printf("..%d..\n", x->data);
    if(x->Left_Child)
    PrintMyTree(x->Left_Child);
    if(x->Right_Child)
    PrintMyTree(x->Right_Child);
    }
}

int main(){
    int iArrElement[7] = {3,9,20,-1000,-1000,15,7};
    int n = 7;
    // printf("Enter How many nodes ");
    // scanf("%d", &n);
    for(int i=0; i<n; i++) 
    { 
        AddToTree(iArrElement[i]); 
    }
    PrintMyTree(Root);
    return 0;
}
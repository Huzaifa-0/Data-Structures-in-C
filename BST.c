#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *right ,*left;
};
typedef struct node *BTREE;

BTREE newNode(int data)
{
    BTREE node = (BTREE)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

BTREE insert(BTREE root,int data)
{
    if(root != NULL)
    {
        if(data < root->data)
        root->left=insert(root->left,data);
        else
        root->right=insert(root->right,data);
    }
    else
    root=newNode(data);
    return root;
}

void inorder(BTREE root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf(" %d \t",root->data);
        inorder(root->right);
    }
}

BTREE deleteNode(BTREE root,int key)
{
    BTREE p,q;
    if(root == NULL)
    return NULL;
    if(root->data == key)
    {
        // First case
        if(root->right == root->left)
        {
            free(root);
            return NULL;
        }
        else
        {
            //second case if left node is null...
            if(root->left == NULL)
            {
                p = root->right;
                free(root);
                return p;
            }
            // if right node is null....
            else if(root->right)
            {
                p = root->left;
                free(root);
                return p;
            }
            //third case 
            else
            {
                p = q = root->right;
                while(p->left != NULL)
                p = p->left;
                p->left = root->left;
                free(root);
                return q;
            } 
        }
    }
    else if(root->data < key)
      root->right = deleteNode(root->right,key);
      else
      root->left =  deleteNode(root->left,key);
      return root;
}

int size(BTREE root)
{
    if(root==NULL)
    return 0;
    else
    return root->data +size(root->left)+size(root->right);
}

int leaves(BTREE root)
{
    if(root != NULL)
    {
        if(root->left==root->right)
        return 1;
        else
        return leaves(root->left)+leaves(root->right);
    }
    else
    return 0;
}

void smallerThan(BTREE root, int value)
{
    if(root != NULL)
    {
        if(root->data >= value)
           smallerThan(root->left, value);
        else
        {
            smallerThan(root->left, value);
            printf("%d\t",root->data);
            smallerThan(root->right, value);
        }
    }
}

int pathsum(BTREE root, int sum)
{
    int pathSum;
    if(root == NULL) 
    return (sum == 0);
    else
    {
        pathSum = sum - root -> data;
        return (pathsum(root -> left, pathSum) || pathsum(root -> right, pathSum));
    }
}

int Min(int a,int b)
{
    return (a < b) ? a : b;
}
int Max(int a,int b)
{
    return (a > b) ? a : b;
}
int min(BTREE root)
{
    BTREE current = root;
    while(current->left != NULL)
    {
        current = current->left;
    }
    return (current->data);
}

int max(BTREE root)
{
    BTREE current = root;
    while(current->right != NULL)
    {
        current = current->right;
    }
    return (current->data);
}

/* Helper function for getLevel().  It returns level of the data if data is 
   present in tree, otherwise returns 0.*/
int getLevelUtil(BTREE root, int data, int level) 
{ 
    if (root == NULL) 
        return 0; 
  
    if (root->data == data) 
        return level; 
  
    int downlevel = getLevelUtil(root->left, data, level+1); 
    if (downlevel != 0) 
        return downlevel; 
  
    downlevel = getLevelUtil(root->right, data, level+1); 
    return downlevel; 
} 
  
/* Returns level of given data value */
int getLevel(BTREE root, int data) 
{ 
    return getLevelUtil(root,data,1); 
} 

int depth_lvl(BTREE root , int d)
{
    if(root == NULL)
    return 0;
    else if(d == 0)
    return 1;
    else
    return depth_lvl(root->left,d-1) + depth_lvl(root->right,d-1);
}

int minDepth(BTREE root) 
{ 
    // Corner case. Should never be hit unless the code is  
    // called on root = NULL 
    if (root == NULL) 
        return -1; 
  
    // Base case : Leaf Node. This accounts for height = 1. 
    if (root->left == NULL && root->right == NULL) 
    return 0; 
  
    // If left subtree is NULL, recur for right subtree 
    if (!root->left) 
    return minDepth(root->right) + 1;  
  
    // If right subtree is NULL, recur for left subtree 
    if (!root->right) 
    return minDepth(root->left) + 1; 
  
    return Min(minDepth(root->left), minDepth(root->right)) + 1; 
}

int height(BTREE root)
{
    if(root==NULL)
    return -1;
    else
    {
        int L_height , R_height;
        L_height = height(root->left);
        R_height = height(root->right);
        
        if(R_height > L_height)
        return (R_height+1);
        else
        return (L_height+1);
    }
}

int oneChild(BTREE root)
{
    if(root ==NULL)
    return 0;
    if(root->left != NULL && root->right == NULL)
    return 1 + oneChild(root->left);

    else if(root->left == NULL && root->right != NULL)
    return 1 + oneChild(root->right);

    else
    return oneChild(root->left) + oneChild(root->right);
}

void leftChild(BTREE root)
{
    if(root !=NULL)
    {
           leftChild(root->left); 
           if(root->left != NULL && root->right == NULL)
              printf("%d\t",root->data);
           leftChild(root->right);
    }
}

void main()
{
    BTREE myroot = NULL;
    int i;
    printf("Please enter the node value \n");
    scanf("%d",&i);
    while(i != -1)
    {
        myroot=insert(myroot,i);
        scanf("%d",&i);
    }
    inorder(myroot);
    printf("\nthe Min value is : %d\n",min(myroot));
    printf("the Max value is : %d\n",max(myroot));
    printf("the Size of the tree is : %d\n",size(myroot));
    printf("the number of Leaves in the tree is : %d\n",leaves(myroot));
    printf("the Height of this tree is : %d\n",height(myroot));
    printf("the tree has (....%d....) Parents with one child \n",oneChild(myroot));
    printf("the number of node at Third Level depth is : %d\n",depth_lvl(myroot,3));
    printf("the path in the root is : %d\n",pathsum(myroot,340));
    printf("the min depth in the tree is : %d\n",minDepth(myroot));
    printf("Level of node 90 is %d\n",getLevel(myroot,90));
    smallerThan(myroot,92);
    printf("\n");
    leftChild(myroot);
    printf("\n");
    //deleteNode(myroot,160);
    //inorder(myroot);
    
}
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int height;
    struct node *left,*right;
};
typedef struct node *AVL;
AVL newNode(int data)
{
    AVL node = (AVL)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 0;
    return node;
}
int height(AVL root)
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
int max(int a,int b)
{
    return (a > b) ? a : b;
}
AVL leftRotation(AVL z)
{
    AVL temp = z->right;
    z->right = temp->left;
    temp->left = z;
    z->height = max(height(z->left),height(z->right))+1;
    temp->height = max(height(temp->left),height(temp->right))+1;
}

AVL rightRotation(AVL z)
{
    AVL temp = z->left;
    z->left = temp->right;
    temp->right = z;
    z->height = max(height(z->left),height(z->right))+1;
    temp->height = max(height(temp->left),height(temp->right))+1;
}
AVL rightLeftRotation(AVL z)
{
    z->right = rightRotation(z->right);
     return (leftRotation(z));
}
AVL leftRightRotation(AVL z)
{
    z->left = leftRotation(z->left);
     return (rightRotation(z));
}

AVL insert(AVL root,int data)
{
    if(root != NULL)
    {
        if(data < root->data)
           root->left=insert(root->left,data);
        else if(data > root->data)
           root->right=insert(root->right,data);
        else
           return root;
        root->height =max(height(root->left),height(root->right))+1;

        if(height(root->left)-height(root->right) > 1 && data < root->left->data)
           return rightRotation(root);

        if(height(root->left)-height(root->right) > 1 && data > root->left->data)
           return leftRightRotation(root);

        if(height(root->left)-height(root->right) < -1 && data > root->right->data)
           return leftRotation(root);
           
        if(height(root->left)-height(root->right) < -1 && data < root->right->data)
           return rightLeftRotation(root);
    }
    else
        root = newNode(data);

    return root;
}

void main()
{
    AVL myroot = NULL;
    int i;
    printf("Please enter the node value \n");
    scanf("%d",&i);
    while(i != -1)
    {
        myroot=insert(myroot,i);
        scanf("%d",&i);
    }
    printf("the Height of this tree is : %d\n",height(myroot));
}
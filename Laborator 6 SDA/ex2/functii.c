#include <stdio.h>
#include <stdlib.h>
#include "structura.h"

extern unsigned int n;

int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int Node_Height(tree_node *root)
{
    int hs, hd;
    if (root==NULL) 
        return -1;
    hs = Node_Height(root->left);
    hd = Node_Height(root->right);
    return 1+((hs>hd) ? hs : hd);
}
/* int Node_Height(tree_node *root)
{
    if(root==NULL) 
        return -1;
    else
        return root->val;
} */

tree_node *Rotation_L(tree_node *root)
{
    tree_node *rright=root->right;
    tree_node *minright=rright->left;

    rright->left=root;
    root->right=minright;
    root->height=1+max(Node_Height(root->left),Node_Height(root->right));
    rright->height=1+max(Node_Height(rright->left),Node_Height(rright->right));

    return rright;
}

tree_node *Rotation_R(tree_node *root)
{
    tree_node *rleft=root->left;
    tree_node *maxleft=rleft->right;

    rleft->right=root;
    root->left=maxleft;
    root->height=1+max(Node_Height(root->left),Node_Height(root->right));
    rleft->height=1+max(Node_Height(rleft->left),Node_Height(rleft->right));

    return rleft;
}

tree_node *Rotation_LR(tree_node *root)
{
    root->left=Rotation_L(root->left);
    return Rotation_R(root);
}

tree_node *Rotation_RL(tree_node *root)
{
    root->right=Rotation_R(root->right);
    return Rotation_L(root);

}

tree_node *Node_Create(int val)
{
    tree_node *node=NULL;
    node=(tree_node*)malloc(sizeof(tree_node));
    node->val=val;
    node->left=NULL;
    node->right=NULL;
    node->height=0;

    return node;
}

tree_node *Node_Insert(tree_node *root, int val)
{
    if(root==NULL)
        return Node_Create(val);
    else
    {
        if(val < root->val)  root->left=Node_Insert(root->left,val);
        else root->right=Node_Insert(root->right,val);
    }

    root->height=1+max(Node_Height(root->left),Node_Height(root->right));

    int E=Node_Height(root->left)-Node_Height(root->right);

    if(E > 1 && val < root->left->val)
    return Rotation_R(root);
    if(E < -1 && val > root->right->val)
        return Rotation_L(root);
    if(E > 1 && val > root->left->val)
        return Rotation_RL(root);
    if(E < -1 && val < root->right->val)
       return Rotation_LR(root);

    return root;
}

void Tree_Create(tree_node **root, int* v)
{
    for(unsigned int i=0;i<n;i++)
       *root=Node_Insert(*root,v[i]);   
}

void Print_Inorder(tree_node *root)
{
    if(root!=NULL)
    {
        Print_Inorder(root->left);
        printf("%d ", root->val);
        Print_Inorder(root->right);
    }
}


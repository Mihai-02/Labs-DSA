#include <stdio.h>
#include <stdlib.h>
#include "structuri.h"

extern unsigned int n;

//Functia creaza un nod de tipul tree_node
tree_node *Node_Create(int val)
{
    tree_node *node=NULL;
    node=(tree_node*)malloc(sizeof(tree_node));
    node->val=val;
    node->left=NULL;
    node->right=NULL;

    return node;
}

//Functia insereaza un nod in arborele cu radacina root astfel incat arborele ramane BST
tree_node *Node_Insert(tree_node *root, int val)
{
    if(root==NULL)
    {
        return Node_Create(val);
    }
    else
    {
        if(val < root->val)  root->left=Node_Insert(root->left,val);
        else root->right=Node_Insert(root->right,val);
    }

    return root;
}

//Functia creaza arborele cu radacina root prin introducerea tuturor valorilor din vectorul v ca noduri
void Tree_Create(tree_node **root, int* v)
{
    for(unsigned int i=0;i<n;i++)
        *root=Node_Insert(*root,v[i]);
    
}

//Functia construieste un vector "a" care contine elementele arborelui parcurs in inorder
void Inorder_BST(tree_node *root, int *a, int *i)
{
    if(root!=NULL)
    {
        Inorder_BST(root->left, a, i);
        a[*i]=root->val;
        (*i)++;
        Inorder_BST(root->right, a, i);
    }
}

//Functia verifica daca arborele cu radacina root este BST
int Check_BST(tree_node *root)
{
    int i=0;

    int *a;
    a=(int*)malloc(n*sizeof(int));

    Inorder_BST(root, a, &i);
    unsigned int ok=1;

    /* printf("\n========================\n");      //Afisare vector cu elementele ordonate conform parcurgerii arborelui in inorder
    for(unsigned int i=0;i<n;i++)
        printf("%d ", a[i]);

    printf("\n========================\n"); */
    for(unsigned int i=0;i<n-1;i++)
        if(a[i]>a[i+1])
            ok=0;

    return ok;
}
tree_node *Minim(tree_node *root)
{
    tree_node *aux=root;
    
    while(aux->left!=NULL)
        aux=aux->left;

    return aux;
}

tree_node *Node_Search(tree_node *root, int val)
{
    if(root == NULL || val == root->val)
        return root;
    
    if(val > root->val)
        return Node_Search(root->right,val);
    else
        return Node_Search(root->left,val);

}

//Functia sterge un nod din arborele cu radacina root astfel incat arborele ramane BST
tree_node *Node_Delete(tree_node *root, int val)
{
    if(root==NULL)
        return root;

    if(val > root->val)root->right=Node_Delete(root->right,val);
    else if(val < root->val)root->left=Node_Delete(root->left,val);

    else if(root->left==NULL)
    {
        tree_node *tp=root;
        root=root->right;
        free(tp);
        return root;
    }
    else if(root->right==NULL)
    {
        tree_node *tp=root;
        root=root->left;
        free(tp);
        return root;
    }

    else
    {
        tree_node *nod_min=Minim(root->right);
        root->val=nod_min->val;
        root->right=Node_Delete(root->right,nod_min->val);

    }
    return root;
}

//Functia afiseaza nodurile arborelui in inorder (SRD)
void Print_Inorder(tree_node *root)
{
    if(root!=NULL)
    {
        Print_Inorder(root->left);
        printf("%d ", root->val);
        Print_Inorder(root->right);
    }
}

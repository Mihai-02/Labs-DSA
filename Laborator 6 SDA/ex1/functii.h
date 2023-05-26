#include "structuri.h"
tree_node *Node_Insert(tree_node *root, int val);
void Tree_Create(tree_node **root, int* v);
int Check_BST(tree_node *root);
tree_node *Minim(tree_node *root);
tree_node *Node_Search(tree_node *root, int val);
tree_node *Node_Delete(tree_node *root ,int val);
void Print_Inorder(tree_node *root);
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functii.h"


unsigned int n=5;

int main()
{
    srand(time(NULL));
    int *v;
    v=(int*)malloc(n*sizeof(int));

    FILE *fp;
    if((fp=fopen("input.txt","rt"))==NULL)
    {
        printf("Fisierul nu a putut fi deschis.\n");
        exit(1);
    }

    for(unsigned int i=0;i<n;i++)
        fscanf(fp,"%d", &v[i]);

    tree_node *root=NULL;
    Tree_Create(&root,v);

    //Cautarea unei valori aleatorii in arbore
    int val_rand=rand()%20;                     

    if(Node_Search(root,val_rand)!=NULL)
        printf("Valoarea aleatoare < %d > se afla in arbore.\n\n",val_rand);
    else    //Daca valoarea aleatoare generata nu se afla in arborele initial, aceasta va fi adaugata (ex de folosire Node_Insert din main)
    {
        printf("Valoarea aleatoare < %d > nu se afla in arbore.\n\n",val_rand);
        root=Node_Insert(root,val_rand);
        n++;
    }
    
    printf("\n");
    Print_Inorder(root);

    //Stergerea unei valori care exista in arbore
    do
    {
        val_rand=rand()%20;
    } while (Node_Search(root,val_rand)==NULL);
    root=Node_Delete(root,val_rand);
    n--;

    
    printf("\nDupa stergere:\n");
    Print_Inorder(root);
    printf("\n");

    if(Check_BST(root))                     //Verificarea arborelui rezultat (BST)
        printf("Arborele este BST.\n");
    else
        printf("Arborele nu este BST.\n");

    //root->left->val=35;               //TEST
    //printf("\nDupa modificare...\n\n");

    //if(Check_BST(root))                      //Verificarea arborelui modificat (nu e BST)
    //    printf("Arborele este BST.\n");
    //else
    //    printf("Arborele nu este BST.\n");

    return 0;
}

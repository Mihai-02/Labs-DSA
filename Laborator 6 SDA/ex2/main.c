#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functii.h"

unsigned int n=6;

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

    Print_Inorder(root);

    return 0;
}


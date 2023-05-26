#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

int main(int argc, char *argv[])
{
    node_t *head=NULL;
    int x;

    FILE *fp;
    if((fp=fopen(argv[1],"rt"))==NULL)
    {
        printf("Fisierul nu a putut fi deschis.");
        exit(1);
    }

    while(!feof(fp))
    {
        fscanf(fp,"%d", &x);
        head=append_node(head,x);
    }

    fclose(fp);

    print_list(head);
    
    printf("\nIntroduceti o valoare de eliminat din lista:");
    scanf("%d", &x);   

    head=remove_node(head,x);

    printf("\nNoua lista\n");
    print_list(head);
    return 0;
}
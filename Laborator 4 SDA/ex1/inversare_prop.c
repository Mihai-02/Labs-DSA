#include <stdio.h>
#include <stdlib.h>
#include "functii.h"


int main()
{
    FILE *fp;
    if((fp=fopen("input.txt", "rt"))==NULL)
    {
        printf("Fisierul nu a putut fi deschis.");
        exit(1);
    }

    stack_t *stack=NULL;
    stack=stack_create();

    char cuv[25];
    while(!feof(fp))
    {
        fscanf(fp,"%s",cuv);
        stack_push(stack,cuv);
    }

    fclose(fp);

    afisare_ordine_inversa(stack);
    
    return 0;
}
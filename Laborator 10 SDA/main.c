#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "functii.h"

int main()
{
    Graph *g;
    Muchie *arbore_minim_ex_1;
    g=graph_create();
    merge_sort(g->m,0,g->nr_muchii-1);

    arbore_minim_ex_1=Kruskal(g);

        int sum=0;

    printf("---------------------------------------\n    Arbore minim de acoperire ex 1\n---------------------------------------\n");
    for (unsigned int i=0;i<g->nr_vf-1 ;i++)
    {
        printf("%d %d %d\n", arbore_minim_ex_1[i].v1, arbore_minim_ex_1[i].v2, arbore_minim_ex_1[i].cost);
        sum+=arbore_minim_ex_1[i].cost;
    }
    printf("\nSuma 1: %d\n", sum);
/*============================================
             KRUSKAL GRAF TRENURI
============================================*/
    node* toate_head=NULL;
    citire_din_fisiere(&toate_head);

    char **vector_unice=NULL;
    int n_unice=0,mch=0;
    create_unique_vect(toate_head, &vector_unice, &n_unice);

    int **matrAdia,**matrCost;
    matrAdia = (int**)malloc(n_unice*sizeof(int*));
    if(matrAdia==NULL)
    {
        printf("Alocarea de memorie a esuat.");
        exit(1);
    }
    for (int k=0;k < n_unice;k++)
        matrAdia[k] = (int*)calloc(n_unice,sizeof(int));
    if(matrAdia==NULL)
    {
        printf("Alocarea de memorie a esuat.");
        exit(1);
    }

    matrCost = (int**)malloc(n_unice*sizeof(int*));
    if(matrCost==NULL)
    {
        printf("Alocarea de memorie a esuat.");
        exit(1);
    }
    for (int k=0;k < n_unice;k++)
        matrCost[k] = (int*)calloc(n_unice,sizeof(int));
    if(matrCost==NULL)
    {
        printf("Alocarea de memorie a esuat.");
        exit(1);
    }
    for(unsigned int i=0;i<n_unice;i++)
        for(unsigned int j=0;j<n_unice;j++)
           if(i!=j)
                matrCost[i][j]=INT_MAX;

    while(toate_head->next != NULL)
    {
        int indice1, indice2;
        indice1=get_code(vector_unice, n_unice, toate_head->nume_statie);
        indice2=get_code(vector_unice, n_unice, toate_head->next->nume_statie);
        if(strcmp(toate_head->cod_tren, toate_head->next->cod_tren) == 0)
        {
            if(matrAdia[indice1][indice2]!=1)
            {
                matrAdia[indice1][indice2]=1;
                matrAdia[indice2][indice1]=1;
                matrCost[indice1][indice2]=toate_head->next->kilometri-toate_head->kilometri;
                matrCost[indice2][indice1]=toate_head->next->kilometri-toate_head->kilometri;
                mch++;
            }
        }
        toate_head=toate_head->next;
    }

    Graph *graf_tren;
    graf_tren=(Graph*)malloc(sizeof(Graph));
    if(graf_tren==NULL)
    {
        printf("Alocarea de memorie pentru graf a esuat.\n");
        exit(1);
    }
    graf_tren->nr_vf=n_unice;
    graf_tren->nr_muchii=mch;
    graf_tren->m=NULL;
 
    graf_tren->m=(Muchie*)malloc(graf_tren->nr_muchii*sizeof(Muchie));
    if(g->m==NULL)
    {
        printf("Alocarea de memorie pentru vectorul de muchii a esuat.\n");
        exit(1);
    }
    int k=0;
     
    for(unsigned int i=0;i<graf_tren->nr_vf;i++)
        for(unsigned int j=i+1;j<graf_tren->nr_vf;j++)
            if(matrAdia[i][j]==1)
            {
                graf_tren->m[k].v1=i;
                graf_tren->m[k].v2=j;
                graf_tren->m[k].cost=matrCost[i][j];
                k++;
            }
 
    merge_sort(graf_tren->m,0,graf_tren->nr_muchii-1);

    Muchie *arbore_minim_ex_2;

     arbore_minim_ex_2=Kruskal(graf_tren);

    FILE *fp;
    fp=fopen("Rezulatat_graf_trenuri.txt", "wt");
    if(fp==NULL)
    {
        printf("Fisierul nu a putut fi deschis.");
        exit(1);
    }

        sum=0;

    for(unsigned int i=0; i<graf_tren->nr_vf-1; i++)
    {
        fprintf(fp, "%s - %s; Cost:%d\n", vector_unice[arbore_minim_ex_2[i].v1], vector_unice[arbore_minim_ex_2[i].v2], arbore_minim_ex_2[i].cost);
        sum+=arbore_minim_ex_2[i].cost;
    }
    printf("\nSuma 2: %d\n", sum);
  
    return 0;
}
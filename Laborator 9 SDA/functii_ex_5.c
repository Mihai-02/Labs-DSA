/*==========================================================================================
        EX 5: DIJKSTRA si afisarea drumului minim de la Bucuresti la Targu Jiu
==========================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "structuri.h"

int suma(int a[], int n)
{
    int sum=0;
    for(unsigned int i=0;i<n;i++)
        sum+=a[i];
    return sum;
}

void Dijkstra(Graph *g, int i_sursa, int *cost, int *parinte)
{
    int *MN,*ME;
    MN=(int*)malloc(g->vf*sizeof(int));
    ME=(int*)calloc(g->vf,sizeof(int));

    for(unsigned int j=0;j<g->vf;j++)
    {
        cost[j]=INT_MAX;
        MN[j]=1;
    }
    cost[i_sursa]=0;

    while(suma(MN,g->vf)!=0)    //cat timp exista noduri in MN
    {
        int cost_min=INT_MAX, i_C=0;
        for(unsigned int i=0;i<g->vf;i++)
            if(cost[i]<=cost_min && ME[i]==0)
            {
                cost_min=cost[i];
                i_C=i;
            }
        ME[i_C]=1;
        int nod_C=i_C;
        for(unsigned int v=0; v<g->vf;v++)
            if(g->m_cost[i_C][v]!=0)
            {
                if(ME[v]==0 && cost[i_C]!=INT_MAX && cost[i_C]+g->m_cost[i_C][v] < cost[v])
                {
                    cost[v] = cost[i_C]+g->m_cost[i_C][v];
                    parinte[v]=nod_C;
                }
            }
        MN[i_C]=0;
    }

/*  printf("\n");
    for(unsigned int i=0;i<g->vf;i++)
            printf("%d ",cost[i]);
    printf("\n\n");
    for(unsigned int i=0;i<g->vf;i++)
            printf("%d ",parinte[i]);
    printf("\n\n"); */

}

void ruta_natal(int *v_cost, int *par,char *oras_n, int i_natal, node *unic_head)
{
//AFISAREA RUTEI DE LA BUCURESTI LA TARGU JIU IN FISIERUL ruta.txt

    char statie_curent[40];
    node* copy;

    FILE *fp;
    fp=fopen("ruta.txt","wt");
    if(fp==NULL)
    {
        printf("Fisierul ruta.txt nu a putut fi deschis.");
        exit(1);
    }
    fprintf(fp,"Drumul de cost minim de la Bucuresti la %s: %dkm\nStatii:\n", oras_n, v_cost[i_natal]);

    int kk=i_natal;
    do
    {
        copy=unic_head;
        while(copy!=NULL && copy->i!=kk)
            copy=copy->next;
        strcpy(statie_curent,copy->nume_statie);
        fprintf(fp,"%s\n",statie_curent);
        kk=par[kk];
    }while(kk!=0);
    fprintf(fp,"Bucuresti Nord\n");
    fclose(fp);
}
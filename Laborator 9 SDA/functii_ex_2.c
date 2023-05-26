/*==================================
        EX 2: creare grafuri
==================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structuri.h"


void aflu_i_oras_curent(node* head, char statie[], int *i)
{
    while(head!=NULL && strcmp(statie,head->nume_statie))
        head=head->next;
    *i=head->i;
}

Graph* graph_create(int orientat, node* lista_km, node* lista_unice, int n)
{
    int i;
    Graph *g=(Graph*)malloc(sizeof(Graph));
    if(g==NULL)
    {
        printf("Alocarea de memorie a esuat.");
        exit(1);
    }
    
    g->vf=n;
    g->muchii=0;

    //ALOCARE MEMORIE MATRICE DE ADIACENTA

    g->m_adi = (int**)malloc(n*sizeof(int*));
    if(g->m_adi==NULL)
    {
        printf("Alocarea de memorie a esuat.");
        exit(1);
    }
    for (i=0;i < g->vf;i++)
        g->m_adi[i] = calloc(g->vf,sizeof(int));
    if(g->m_adi==NULL)
    {
        printf("Alocarea de memorie a esuat.");
        exit(1);
    }

    //ALOCARE MEMORIE MATRICE DE COSTURI

    g->m_cost = (int**)malloc(n*sizeof(int*));
    if(g->m_cost==NULL)
    {
        printf("Alocarea de memorie a esuat.");
        exit(1);
    }
    for (i=0;i < g->vf;i++)
        g->m_cost[i] = calloc(g->vf,sizeof(int));
    if(g->m_cost==NULL)
    {
        printf("Alocarea de memorie a esuat.");
        exit(1);
    }

    int i_pred,i_curent;
    node* statie_pred=lista_km;
    aflu_i_oras_curent(lista_unice,lista_km->nume_statie,&i_pred);
    lista_km=lista_km->next;
    while(lista_km!=NULL)
    {
        aflu_i_oras_curent(lista_unice,lista_km->nume_statie,&i_curent);
        if(!strcmp(lista_km->cod_tren,statie_pred->cod_tren))        //Acelasi tren
        {
            if (orientat==0)
            {
                if(g->m_adi[i_pred][i_curent]!=1)
                {
                    g->m_adi[i_pred][i_curent]=1;
                    g->m_adi[i_curent][i_pred]=1;
                    g->muchii++;
                    g->m_cost[i_pred][i_curent]=lista_km->kilometri-statie_pred->kilometri;
                    g->m_cost[i_curent][i_pred]=lista_km->kilometri-statie_pred->kilometri;
                }
            }
            else
            {
                if(g->m_adi[i_pred][i_curent]!=1)
                {
                    g->m_adi[i_pred][i_curent]=1;
                    g->muchii++;
                    g->m_cost[i_pred][i_curent]=lista_km->kilometri-statie_pred->kilometri;
                }
            }
        }
        i_pred=i_curent;
        statie_pred=lista_km;
        lista_km=lista_km->next;
    }
    return g;
}
/*===============================================================
        EX 6: Statia cea mai departe de Bucuresti + drumul
===============================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "structuri.h"

void departe(int *v_cost, node* unic_head, int n, int *par, char *statie_max, int *i_max)
{
    int cost_max=v_cost[0];

    for(unsigned int i=1;i<n;i++)
        if(v_cost[i]>cost_max)
        {
            cost_max=v_cost[i];
            *i_max=i;
        }

    node* copy=unic_head;

    while(copy!=NULL && *i_max!=copy->i)
        copy=copy->next;

    strcpy(statie_max,copy->nume_statie);
}

void afisare_drum_max(int j, char *statie, int cost_max, node* unic_head, int *par)
{
    node* copy;

    FILE *fp;
    fp=fopen("departe.txt","wt");
    if(fp==NULL)
    {
        printf("Fisierul departe.txt nu a putut fi deschis.");
        exit(1);
    }

    fprintf(fp,"Cea mai departe statie de Bucuresti este %s la %dkm.\nStatii:\n",statie, cost_max);

    int kk=j;
    do
    {
        copy=unic_head;
        while(copy!=NULL && copy->i!=kk)
            copy=copy->next;
        strcpy(statie,copy->nume_statie);
        fprintf(fp,"%s\n",statie);
        kk=par[kk];
    }while(kk!=0);
    fprintf(fp,"Bucuresti Nord\n");

    fclose(fp);
}

/*===============================================================
        EX 7: Toate drumurile de la Bucuresti la Oradea
===============================================================*/

void p_DFS(Graph* g,int sursa, char** orase, int* color)
{
    for(unsigned int i=0;i<g->vf;i++)
        if(g->m_adi[sursa][i]==1 && color[i]==0)
        {
            color[i]=1;   //"gri"
            fprintf(fp,"%s\n", orase[i]);
            p_DFS(g,i,orase,color);
        }
    color[sursa]=2; //"negru"/vizitat
}

void toate_bucuresti_oradea(node* unic_head, int i_buc, int i_oradea)
{
    FILE *fp;
    fp=fopen("bucuresti_oradea.txt","wt");
    if(fp==NULL)
    {
        printf("Fisierul bucuresti_oradea.txt nu a putut fi deschis.");
        exit(1);
    }

    int *color;
    color=(int*)calloc(g->vf,sizeof(int));
    color[i_buc]=1;
    p_DFS(g, i_buc, orase, color);



    /* while(toate_head!=NULL)
    {
        if(!strcmp(toate_head->cod_tren,tren_curent))
        {
            if(!strcmp(toate_head->nume_statie,"Bucuresti Nord"))
                bucuresti=toate_head;
            if(!strcmp(toate_head->nume_statie,"Oradea"))
                oradea=toate_head;
        }  
        else
        {
            if(bucuresti!=NULL && oradea!=NULL)
            {
                fprintf(fp,"Trenul %s: ",tren_curent);
                while(bucuresti!=oradea->next)
                {
                    fprintf(fp, "%s; ", bucuresti->nume_statie);
                    
                    bucuresti=bucuresti->next;
                }
                fprintf(fp,"\n");
            }
            strcpy(tren_curent,toate_head->cod_tren);
            bucuresti=NULL;
            oradea=NULL;
            if(!strcmp(toate_head->nume_statie,"Bucuresti Nord"))
                bucuresti=toate_head;
        }
        toate_head=toate_head->next;
    } */
}
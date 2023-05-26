#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functii.h"

int main()
{
    node *toate_head=NULL, *unic_head=NULL;
    int unic_nr=0;

    //EX 1
    citire_din_fisiere(&toate_head);

    create_unique_list(toate_head,&unic_head,&unic_nr);

    //EX 2
    Graph *graf_neorientat = graph_create(0, toate_head, unic_head, unic_nr);//0-neorientat
    Graph *graf_orientat = graph_create(1, toate_head, unic_head, unic_nr);//1-orientat

    //printf("Neorientat:\nNoduri:%d\nMuchii:%d\n",graf_neorientat->vf, graf_neorientat->muchii);
    //printf("Orientat:\nNoduri:%d\nMuchii:%d\n",graf_orientat->vf, graf_orientat->muchii);

    //EX 3
    dist_min_max(toate_head);
    
    //EX 4
    total_km(toate_head);

    //EX 5
    int *v_cost,*par;
    v_cost=(int*)malloc(graf_neorientat->vf*sizeof(int));
    par=(int*)malloc(graf_neorientat->vf*sizeof(int));

    node* headcopy=unic_head;

    char oras_sursa[40]="Bucuresti Nord";                                  
    int i_sursa=0;
    while( headcopy!=NULL && strcmp(oras_sursa,headcopy->nume_statie))
    {
        headcopy=headcopy->next;
    }  
    if(headcopy==NULL)
        printf("Orasul nu exista.\n");
    else
    {
        i_sursa=headcopy->i;
        Dijkstra(graf_neorientat,i_sursa,v_cost,par);

        char oras_n[30];
        strcpy(oras_n,"Targu Jiu");

        headcopy=unic_head;
        int i_natal=0;
        while( headcopy!=NULL && strcmp(oras_n,headcopy->nume_statie))
        {
            headcopy=headcopy->next;
        }
        i_natal=headcopy->i;
        if(headcopy==NULL)
            printf("Orasul nu exista.\n");
        else
            ruta_natal(v_cost,par,oras_n,i_natal,unic_head);

    }
 
    //EX 6
    int i_max;
    char statie_max[40];
    departe(v_cost,unic_head,graf_neorientat->vf,par,statie_max,&i_max);
    afisare_drum_max(i_max,statie_max,v_cost[i_max],unic_head,par);

    //EX 7
    int i_buc=0,i_oradea=0;

    headcopy=unic_head;                                  
    while( headcopy!=NULL && strcmp(oras_sursa,"Bucuresti Nord"))
    {
        headcopy=headcopy->next;
    }  
    if(headcopy==NULL)
        printf("Orasul nu exista.\n");
    else
        i_buc=headcopy->i;


    headcopy=unic_head;                                  
    while( headcopy!=NULL && strcmp(oras_sursa,"Oradea"))
    {
        headcopy=headcopy->next;
    }  
    if(headcopy==NULL)
        printf("Orasul nu exista.\n");
    else
        i_oradea=headcopy->i;

    if(i_oradea!=0 && i_buc!=0)
        toate_bucuresti_oradea(unic_head, i_buc, i_oradea);

    //EX 8
    char statie_1[40],statie_2[40];
    int dist_max=0,max_temp,i_max_temp;

    node* copycopy;

    headcopy=unic_head;
    while(headcopy!=NULL)
    {

        strcpy(oras_sursa,headcopy->nume_statie);
        i_sursa=headcopy->i;
        Dijkstra(graf_neorientat,i_sursa,v_cost,par);
        max_temp=0;
        for(unsigned int i=0;i<graf_neorientat->vf;i++)
        {
            if(v_cost[i]>max_temp)
            {
                max_temp=v_cost[i];
                i_max_temp=i;
            }
        }

        if(max_temp>dist_max)
        {
            dist_max=max_temp;
            strcpy(statie_1,oras_sursa);

            copycopy=unic_head;
            while(copycopy->i!=i_max_temp)
                copycopy=copycopy->next;
                
            strcpy(statie_2,copycopy->nume_statie);

        }
        headcopy=headcopy->next;
    }

    FILE *fp;
    fp=fopen("drum_lung.txt","wt");
    if(fp==NULL)
    {
        printf("Fisierul drum_lung.txt nu a putut fi deschis.");
        exit(1);
    }

    fprintf(fp, "Distanta maxima: %dkm\n",dist_max);
    fprintf(fp,"%s - %s", statie_1,statie_2);
  
    return 0;
}
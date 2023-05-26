#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functii.h"

char** citire_fisiere(int *k)
{
    int ok,n=50;
    char **oras;

    oras=(char**)malloc(n*sizeof(char*));
    if(oras==NULL)
    {
            printf("Alocare esuata.");
             exit(1);
    }

    FILE *fp;
    if((fp=fopen("trains/_all_files.txt","rt"))==NULL)
    {
        printf("Fisierul nu a putut fi deschis.");
        exit(1);
    }
    FILE *train;
    while(!feof(fp))
    {
        char nume[30];
        strcpy(nume,"trains/");
        char temp[30];
        fscanf(fp, "%s", temp);
        strcat(nume, temp);

        if((train=fopen(nume,"rt"))==NULL)
        {
            printf("Fisierul %s nu a putut fi deschis.", nume);
            exit(1);
        }

        char nume_oras[50];

        while(fgets(nume_oras, 50, train))
        {
            ok=1;
            nume_oras[strlen(nume_oras)-2]='\0';
            for(unsigned int i=0;i<*k;i++)
                if(!strcmp(oras[i],nume_oras))
                    ok=0;
            if(ok)
            {
                if(*k>=n)
                {
                    n*=2;
                    oras=(char**)realloc(oras,n*sizeof(char*));
                    if(oras==NULL)
                    {
                        printf("Alocare esuata.");
                        exit(1);
                    }
                }
                oras[*k]=strdup(nume_oras);
                (*k)++;
            } 
        }
        fclose(train);
    } 
    fclose(fp); 


    oras=(char**)realloc(oras,*k*sizeof(char*));
    if(oras==NULL)
    {
        printf("Alocare esuata.");
        exit(1);
    }

    return oras;
}


Graph* graph_create(int orientat, char** orase, int n)
{
    int i;
    Graph *g=(Graph*)malloc(sizeof(Graph));
    if(g==NULL)
    {
        printf("Alocarea de memorie a esuat.");
        exit(1);
    }

    g->vf=n;
    g->matrice = (int**)malloc(n*sizeof(int*));
    if(g->matrice==NULL)
    {
        printf("Alocarea de memorie a esuat.");
        exit(1);
    }
    for (i=0;i < g->vf;i++)
        g->matrice[i] = calloc(g->vf,sizeof(int));
    if(g->matrice==NULL)
    {
        printf("Alocarea de memorie a esuat.");
        exit(1);
    }
    g->muchii = 0;

    FILE *fp;
    if((fp=fopen("trains/_all_files.txt","rt"))==NULL)
    {
        printf("Fisierul nu a putut fi deschis.");
        exit(1);
    }

    FILE *train;
    while(!feof(fp))
    {
        char nume[30];
        strcpy(nume,"trains/");
        char temp[30];
        fscanf(fp, "%s", temp);
        strcat(nume, temp);

        if((train=fopen(nume,"rt"))==NULL)
        {
            printf("Fisierul %s nu a putut fi deschis.", nume);
            exit(1);
        }
 
        char nume_oras[50],nume_oras_pred[50];
        int i_oras,i_pred;

        fgets(nume_oras_pred, 50, train);
        nume_oras_pred[strlen(nume_oras_pred)-2]='\0';
        i=0;
        while(strcmp(orase[i],nume_oras_pred))
            i++;
            
        i_pred=i;

        while(fgets(nume_oras, 50, train))
        {
            nume_oras[strlen(nume_oras)-2]='\0';
            i=0;
            while(strcmp(nume_oras,orase[i]))
                i++;
            i_oras=i;

            if (orientat==0)
            {
                if(g->matrice[i_oras][i_pred]!=1)
                {
                    g->matrice[i_oras][i_pred]=1;
                    g->muchii++;
                }
                if(g->matrice[i_pred][i_oras]!=1)
                {
                    g->matrice[i_pred][i_oras]=1;
                    g->muchii++;
                }
            }
            else
            {
                if(g->matrice[i_pred][i_oras]!=1)
                {
                    g->matrice[i_pred][i_oras]=1;
                    g->muchii++;
                }
            }
            i_pred=i_oras;
            strcpy(nume_oras_pred,nume_oras);
        }
 
        fclose(train);
    }
    if(orientat==0)
        g->muchii/=2;
    fclose(fp);
    return g;
}


void graph_print(Graph *g)
{
    for(int i=0; i < g->vf; i++) 
    {
        for(int j=0; j < g->vf; j++)
            printf("%d ",g->matrice[i][j]);
    printf("\n");
    }
}

void most_visited_plus_second(Graph* g, char** orase)
{
    int grad_nod,grad_max=0,grad_second_max=0,i_max=0,i_second_max=0;
    for(int i=0;i<g->vf;i++)
    {
        grad_nod=0;
        for(int j=0;j<g->vf;j++)
            if(g->matrice[i][j]==1)
                grad_nod++;
        if(grad_nod>=grad_max)
        {
            grad_second_max=grad_max;
            i_second_max=i_max;
            grad_max=grad_nod;
            i_max=i;
        }
        else if(grad_nod>=grad_second_max)
        {
            grad_second_max=grad_nod;
            i_second_max=i;
        }
    }
    FILE *fp;
    if((fp=fopen("primul.txt","wt"))==NULL)
    {
        printf("Fisierul nu a putut fi deschis.");
        exit(1);
    }
    fprintf(fp,"%s",orase[i_max]);

    fclose(fp);

    if((fp=fopen("aldoilea.txt","wt"))==NULL)
    {
        printf("Fisierul nu a putut fi deschis.");
        exit(1);
    }
    fprintf(fp,"%s",orase[i_second_max]);
}

void my_city(Graph* g, char** orase)
{
    char city[50];
    printf("Introduceti numele orasului vostru:");
    fgets(city, 50, stdin);
    city[strlen(city)-1]='\0';

    int k=0;
    while( k < g->vf && strcmp(city,orase[k]))
        k++;

    if(k>=g->vf)
    {
        printf("Orasul nu exista.\n");
        return;
    }
    
    int gr=0;
    for(int j=0;j<g->vf;j++)
    {
        if(g->matrice[k][j]==1)
        gr++;
    }
    FILE *fp;
    if((fp=fopen("orasul_meu.txt","wt"))==NULL)
    {
        printf("Fisierul nu a putut fi deschis.");
        exit(1);
    }
    fprintf(fp,"%d", gr);
}


void BFS(Graph* g, int sursa, char** orase)
{   
    FILE *fp;
    if((fp=fopen("parcurgere_bfs.txt","wt"))==NULL)
    {
        printf("Fisierul nu a putut fi deschis.");
        exit(1);
    }

    //0-alb, 1-gri, 2-negru
    int *culoare, v;
    culoare=(int*)calloc(g->vf,sizeof(int));

    culoare[sursa]=1;   //"gri"

    fprintf(fp,"%s\n",orase[sursa]);

    queue_t *Q=queue_create();

    enqueue(Q,sursa);

    while(!queue_empty(Q))
    {
        v=dequeue(Q);
        for(unsigned int i=0;i<g->vf;i++)
            if(g->matrice[v][i]==1 && culoare[i]==0)
            {
                culoare[i]=1;   //"gri"
                fprintf(fp,"%s\n", orase[i]);
                enqueue(Q,i);
            }
        culoare[v]=2;
    }  
    fclose(fp);
}

void p_DFS(Graph* g,int sursa, char** orase, int* color, FILE* fp)
{
    for(unsigned int i=0;i<g->vf;i++)
        if(g->matrice[sursa][i]==1 && color[i]==0)
        {
            color[i]=1;   //"gri"
            fprintf(fp,"%s\n", orase[i]);
            p_DFS(g,i,orase,color,fp);
        }
    color[sursa]=2; //"negru"/vizitat
}

void DFS(Graph *g, int sursa, char** orase)
{
    int *color;
    color=(int*)calloc(g->vf,sizeof(int));

    FILE *fp;
    if((fp=fopen("parcurgere_dfs.txt","wt"))==NULL)
    {
        printf("Fisierul nu a putut fi deschis.");
        exit(1);
    }

    color[sursa]=1; //"gri"

    fprintf(fp,"%s\n",orase[sursa]);

    p_DFS(g, sursa, orase, color, fp);
}

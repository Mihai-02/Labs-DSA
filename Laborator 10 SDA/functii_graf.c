#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "structuri.h"

void merge(Muchie *m, int l, int mid, int r)
{
    Muchie *v1, *v2;
    int n1,n2;
    n1=mid-l+1;
    n2=r-mid;
    v1=(Muchie*)malloc(n1*sizeof(Muchie));
    v2=(Muchie*)malloc(n2*sizeof(Muchie));

    for(unsigned int i=0;i<n1;i++)
        v1[i]=m[l+i];
    for(unsigned int i=0;i<n2;i++)
        v2[i]=m[mid+1+i];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2)
    {
        if(v1[i].cost<=v2[j].cost)
        {
            m[k++]=v1[i];
            i++;
        }
        else
        {
            m[k++]=v2[j];
            j++;
        }
    }

    while(i<n1)
        m[k++]=v1[i++];
    while(j<n2)
        m[k++]=v2[j++];

}

void merge_sort(Muchie *m, int l, int r)
{
    if(l<r)
    {
        int mid=l+(r-l)/2;
        merge_sort(m,l,mid);
        merge_sort(m,mid+1,r);
        merge(m,l,mid,r);
    }
}

Graph* graph_create()
{
    Graph *g;
    g=(Graph*)malloc(sizeof(Graph));
    if(g==NULL)
    {
        printf("Alocarea de memorie pentru graf a esuat.\n");
        exit(1);
    }

    FILE *fp;
    fp=fopen("graf.txt","rt");
    if(fp==NULL)
    {
        printf("Nu a fost gasit nici un fisier cu un graf.\n");
        exit(1);
    }
    char line[200];
    while(fgets(line,200,fp) && line[0]=='#');  //Comentarii
    
    g->nr_vf=atoi(line);                       //nr varfuri (numarul din stringul line de dinainte de caracterul ' ')
    g->nr_muchii=atoi(strchr(line,' ')+1);     //nr varfuri (numarul din stringul line de dupa caracterul ' ')

 
    g->m=(Muchie*)malloc(g->nr_muchii*sizeof(Muchie));
    if(g->m==NULL)
    {
        printf("Alocarea de memorie pentru vectorul de muchii a esuat.\n");
        exit(1);
    }

    int k=0;

    while( !feof(fp) )
    {
        fscanf(fp,"%d %d %d", &g->m[k].v1, &g->m[k].v2, &g->m[k].cost );
        k++;
    }
    return g;
}
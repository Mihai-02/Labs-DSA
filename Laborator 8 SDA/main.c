#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functii.h"

int main()
{
    char **orase;
    int k=0;

/*============================================
                    EX 1
=============================================*/
    orase=citire_fisiere(&k);

/*============================================
                    EX 2
=============================================*/
    Graph *graf_neorientat = graph_create(0, orase, k);//0-neorientat
    Graph *graf_orientat = graph_create(1, orase, k);//1-orientat

/*============================================
                    EX 3
=============================================*/
    FILE *fp;
    if((fp=fopen("noduri.txt","wt"))==NULL)
    {           
        printf("Fisierul nu a putut fi deschis.");
        exit(1);
    }
    fprintf(fp, "%d noduri", graf_neorientat->vf);
    fclose(fp);
    if((fp=fopen("muchii.txt","wt"))==NULL)
    {
        printf("Fisierul nu a putut fi deschis.");
        exit(1);
    }
    fprintf(fp, "%d muchii", graf_neorientat->muchii);

    fclose(fp);

    printf("Noduri(orientat):%d\nMuchii(orientat):%d\n", graf_orientat->vf, graf_orientat->muchii);

/*============================================
                    EX 4
=============================================*/

    most_visited_plus_second(graf_neorientat,orase);

/*============================================
                    EX 5
=============================================*/
    my_city(graf_neorientat,orase);                                   

/*============================================
                    EX 6
=============================================*/
    char* oras_sursa="Bucuresti Nord";                                  
    int j=0;
    while( k < graf_neorientat->vf && strcmp(oras_sursa,orase[j]))  
        j++;
    if(j>=graf_neorientat->vf)
        printf("Orasul nu exista.\n");
    else
    {
        BFS(graf_neorientat,j,orase);
        DFS(graf_neorientat,j,orase);
    }
    return 0;
}
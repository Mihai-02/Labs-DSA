#include <stdio.h>
#include <stdlib.h>
#include "structuri.h"

Muchie* Kruskal(Graph *g)
{
    int *comp_conex;
    comp_conex=(int*)malloc(g->nr_vf*sizeof(int));
    for(unsigned int i=0;i<g->nr_vf;i++)
        comp_conex[i]=i+1;

    Muchie *muchii_arbore_min;
    int n_arbore=0;
    muchii_arbore_min=(Muchie*)malloc((g->nr_vf-1)*sizeof(Muchie));

    int comp_min,comp_max;
    for(unsigned int i=0; n_arbore<g->nr_vf-1; i++)
    {
        if( comp_conex[g->m[i].v1-1] != comp_conex[g->m[i].v2-1] )
        {
            muchii_arbore_min[n_arbore].v1=g->m[i].v1;
            muchii_arbore_min[n_arbore].v2=g->m[i].v2;
            muchii_arbore_min[n_arbore].cost=g->m[i].cost;
            n_arbore++;
        }

        if( comp_conex[g->m[i].v1-1] > comp_conex[g->m[i].v2-1] )
        {
            comp_max=comp_conex[g->m[i].v1-1];
            comp_min=comp_conex[g->m[i].v2-1];
        }
        else
        {
            comp_min=comp_conex[g->m[i].v1-1];
            comp_max=comp_conex[g->m[i].v2-1];
        }
        
        for(unsigned int i=0;i<g->nr_vf;i++)
            if(comp_conex[i]==comp_max)
                comp_conex[i]=comp_min;
        
    }
    
    return muchii_arbore_min;
}
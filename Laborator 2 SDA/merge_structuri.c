#include <stdlib.h>
#include "structura.h"

unsigned int compar(timp a, timp b)
{
    if(a.ora<b.ora)
        return 1;
    else if(a.ora==b.ora && a.min<b.min)
        return 1;
    else if(a.ora==b.ora && a.min==b.min && a.sec==b.sec)
        return 1;
    else
        return 0;
}

void merge(timp v[], unsigned int l, unsigned int m, unsigned int r)
{
    int nl=m-l+1,nr=r-m;
    timp *vecl,*vecr;
    vecl=(timp*)malloc(nl*sizeof(timp));
    vecr=(timp*)malloc(nr*sizeof(timp));
    for(unsigned int i=0; i<nl; i++)
        vecl[i]=v[l+i];
    for(unsigned int i=0; i<nr; i++)
        vecr[i]=v[m+1+i];
    unsigned int i_l=0,i_r=0,k=l;
    while(i_l<nl && i_r<nr)
    {
        if(!compar(vecl[i_l],vecr[i_r]))
        {
            v[k]=vecr[i_r];
            k++;
            i_r++;
        }
        else
        {
            v[k]=vecl[i_l];
            k++;
            i_l++;
        }
    }
    while(i_l<nl)
    {
        v[k]=vecl[i_l];
        k++;
        i_l++;
    }
    while(i_r<nr)
    {
        v[k]=vecr[i_r];
        k++;
        i_r++;
    }
}

void merge_structuri(timp v[], unsigned int l,unsigned int r)
{
    if(l<r)
    {
        unsigned int mij=l+(r-l)/2;
        merge_structuri(v,l,mij);
        merge_structuri(v,mij+1,r);
        merge(v,l,mij,r);
    }
}

#include <stdlib.h>

extern unsigned int nr_pasi_merge;


void interclasare(int v[], unsigned int l, unsigned int mij, unsigned int r)
{
    int nl=mij-l+1,nr=r-mij;
    int *vecl,*vecr;
    vecl=(int*)malloc(nl*sizeof(int));
    vecr=(int*)malloc(nr*sizeof(int));
    for(unsigned int i=0;i<nl;i++)
    {
                vecl[i]=v[l+i];
    }
    for(unsigned int i=0;i<nr;i++)
        vecr[i]=v[mij+1+i];
    unsigned int i_l=0,i_r=0,k=l;
    while(i_l<nl && i_r<nr)
    {
        nr_pasi_merge++;
        if(vecl[i_l]>vecr[i_r])
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


void B(int v[], unsigned int l, unsigned int r)     //MERGE SORT
{
    if(l<r)
    {
        int mij=l+(r-l)/2;
        B(v,l,mij);
        B(v,mij+1,r);
        interclasare(v,l,mij,r);
    }
}

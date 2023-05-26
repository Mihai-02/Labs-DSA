#include "functii.h"

void radix_neg(int* v, int n)
{
    int minim=v[0];
    for(unsigned int i=0;i<n;i++)
        if(v[i]<minim)
            minim=v[i];
    
    for(unsigned int i=0;i<n;i++)
        v[i]-=minim;

    radixSort(v,n);

    for(unsigned int i=0;i<n;i++)
        v[i]+=minim;
}
#include <stdlib.h>

void sortare_O_n(unsigned short int v[], unsigned int n)
{
    unsigned short int *fr;
    fr=(unsigned short int*)calloc(1000,sizeof(unsigned short int));
    for(unsigned int i=0;i<n;i++)
        fr[v[i]]++;
    unsigned int k=0;
    for(unsigned int i=0;i<1000;i++)
    {
        while(fr[i]!=0)
        {
            fr[i]--;
            v[k]=i;
            k++;
        }
    }
}

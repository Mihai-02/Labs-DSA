#include <string.h>
void insertion_cuvinte(char v[][5], unsigned int n)
{
    char aux[5];
    for(int i=0;i<n;i++)
    {
        int j=i-1;
        strcpy(aux,v[i]);
        while(j>=0 && strcmp(aux,v[j])<0)
        {

           strcpy(v[j+1],v[j]);
            j--;
        }
        strcpy(v[j+1],aux);
    }
}

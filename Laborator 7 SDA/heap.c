#include <stdio.h>

extern int nr_cerne;

void schimba(int *a,int i,int j)
{
    int aux=a[i];
    a[i] = a[j];
    a[j] = aux;
}
void cerne(int *a,int n,int k)
{
    int fiuStanga = 2*k+1, fiuDreapta = 2*k+2, pozMax = fiuStanga;
    if(fiuStanga >= n)
        return;
    if(fiuDreapta < n) 
    {
        if(a[fiuDreapta] > a[fiuStanga])
            pozMax = fiuDreapta;
    }
    if(a[k] < a[pozMax]) 
    {
        schimba(a,k,pozMax);
        cerne(a,n,pozMax);
        nr_cerne++;
    }
}
void makeHeap(int *a, int n)
{
    for(int i = n / 2;i >= 0;i--) 
    {
        cerne(a,n,i);
        nr_cerne++;
    }
}
void heapSort(int *a, int n)
{
    makeHeap(a,n);
    printf("Nr cerne make heap:%d\n",nr_cerne);
    while(n > 1)
    {
        schimba(a,0,n-1);
        n--;
        cerne(a,n,0);
        nr_cerne++;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functii.h"

int nr_cerne=0;

int main()
{
    srand(time(NULL));

    int *v, *a;
    unsigned int n=1e6;
    v=(int*)malloc(n*sizeof(int));
    a=(int*)malloc(n*sizeof(int));
    for(unsigned int i=0;i<n;i++)
    {
        v[i]=rand();
        a[i]=v[i];
    }
    
    clock_t begin = clock();

    heapSort(v,n);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Nr cerne heap sort:%d\n", nr_cerne);

    printf("Heap:%g\n",time_spent);

    begin = clock();

    radixSort(a,n);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Radix:%g\n", time_spent);

    int *b,n_b=20;
    b=(int*)malloc(n_b*sizeof(int));
    for(unsigned int i=0;i<n_b;i++)
        b[i]=rand()*100%1000;

    radix_neg(b,n_b);

    printf("\n");
    for(unsigned int i=0;i<n_b;i++)
        printf("%d ", b[i]);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functii.h"

#define VERIF_AFIS 1

unsigned int nr_pasi_selection;
unsigned int nr_pasi_merge;

int main()
{
//      CERINTA 1

    unsigned int n=20;
    int *v1,*v2;
    v1=(int*)malloc(n*sizeof(int));
    v2=(int*)malloc(n*sizeof(int));
    srand(time(NULL));
    for(unsigned int i=0; i<n; i++)
        v1[i]=rand()%10000;
    for(unsigned int i=0; i<n; i++)
        v2[i]=v1[i];
/*     A(v1,n);
#if VERIF_AFIS==1
    printf("==============================CERINTA 1==============================\n");
    for(unsigned int i=0; i<n; i++)
        printf("%d ",v1[i]);
    printf("\n");
#endif // VERIF_AFIS
    printf("Numar de comparatii selection:%d\n", nr_pasi_selection); */
    B(v2,0,n-1);
#if VERIF_AFIS==1
    for(unsigned int i=0; i<n; i++)
        printf("%d ",v2[i]);
    printf("\n");
#endif // VERIF_AFIS
    printf("Numar de comparatii merge:%d\n", nr_pasi_merge);


//TEST QUICKSORT
    quicksort(v1,0,n-1);
    for(unsigned int i=0; i<n; i++)
        printf("%d ",v2[i]);  
    printf("\n"); 


//      CERINTA 2

    n=11;
    char t[11][5]= {"unu", "doi", "trei", "four", "five", "sase", "sapt", "opt", "noua", "zece", "elev"};
#if VERIF_AFIS==1
    printf("==============================CERINTA 2==============================\n");
    for(unsigned int i=0; i<n; i++)
        printf("%s ", t[i]);
#endif // VERIF_AFIS
    insertion_cuvinte(t,n);
#if VERIF_AFIS==1
    printf("\n");
    for(unsigned int i=0; i<n; i++)
        printf("%s ", t[i]);
    printf("\n");
#endif // VERIF_AFIS

//      CERINTA 3

    unsigned int k=15;
    timp *a;
    a=(timp*)malloc(k*sizeof(timp));
    for(unsigned int i=0; i<k; i++)
    {
        a[i].ora=rand()%24;
        a[i].min=rand()%60;
        a[i].sec=rand()%60;
    }
    merge_structuri(a,0,k-1);
    // quick_structuri(a,0,k-1);
#if VERIF_AFIS==1
    printf("==============================CERINTA 3==============================\n");
    for(unsigned int i=0; i<k; i++)
        printf("Ora: %d Minutul: %d Secunda: %d \n",a[i].ora,a[i].min,a[i].sec);
#endif // VERIF_AFIS

//      CERINTA 4

    n=30;
    unsigned short int *v;
    v=(unsigned short int*)malloc(n*sizeof(unsigned short int));
    for(unsigned int i=0; i<n; i++)
        v[i]=rand()%1000;
#if VERIF_AFIS==1
    printf("==============================CERINTA 4==============================\n");
    for(unsigned int i=0; i<n; i++)
        printf("%u ", v[i]);
    printf("\n");
#endif // VERIF_AFIS
    sortare_O_n(v,n);
#if VERIF_AFIS==1
    for(unsigned int i=0; i<n; i++)
        printf("%u ", v[i]);
#endif // VERIF_AFIS
    return 0;
}

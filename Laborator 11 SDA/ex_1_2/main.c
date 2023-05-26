#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* greedy(int suma, int *bancnote, int n)
{
    int *sol;
    int i_banc=n-1;
    sol=(int*)malloc(n*sizeof(int));
    while(suma!=0 && i_banc>=0)
    {
        sol[i_banc]=suma/bancnote[i_banc];
        suma=suma%bancnote[i_banc];
        i_banc--;
    }
    return sol;
}

int main()
{
    srand(time(NULL));

    //EX 1
    int bancnote[]={1, 5, 10, 50, 100}, n=sizeof(bancnote)/sizeof(bancnote[0]);
    int *sol;
    sol=(int*)malloc(n*sizeof(int));
    int suma=78;
    printf("==============\n     EX 1\n==============\n");
    printf("Suma:%d\n", suma);
    sol=greedy(suma, bancnote, n);

    for(int i=n-1;i>=0;i--)
        if(sol[i]!=0)
            printf("%d bancnote de %d de lei\n", sol[i], bancnote[i]);
            
    //EX 2
    suma=90;
    printf("==============\n     EX 2\n==============\n");
    printf("Suma:%d\n", suma);
    int bancnote2[]={1, 3, 5, 15, 30, 50, 150};
    n=sizeof(bancnote2)/sizeof(bancnote2[0]);
    int *sol2;
    sol2=(int*)malloc(n*sizeof(int));
    sol2=greedy(suma, bancnote2, n);

    for(int i=n-1;i>=0;i--)
        if(sol2[i]!=0)
            printf("%d bancnote de %d de lei\n", sol2[i], bancnote2[i]);
    //50 30 30 1 1          suma=112 nu merge
    //30 30 30              suma=90 nu merge
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void print_sol(int *vector_sol, int n)
{
    for(unsigned int i=0;i<n;i++)
        printf("%d ", vector_sol[i]);
    printf("\n");
}

void produs_AN(int *A, int n, int N, int* vector_sol, int k)
{
    if(k<N)
    {
        for(unsigned int i=0;i<n;i++)
        {
                vector_sol[k++]=A[i];
                produs_AN(A, n, N, vector_sol, k);
                vector_sol[--k]=0;
        }
    }
    else
        print_sol(vector_sol, N);
}

int main()
{
    int A[]={2,3,4};
    int n=sizeof(A)/sizeof(A[0]);   //dimensiunea vectorului de cifre posibile
    int N=4;                //NR de cifre al numerelor solutii
    int *vector_sol;
    vector_sol=(int*)calloc(N,sizeof(int));
    int k=0;
    produs_AN(A, n, N, vector_sol, k);
    return 0;
}
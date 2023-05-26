#include <stdio.h>
#include <stdlib.h>

void print_sol(int *vector_sol, int n)
{
    for(unsigned int i=0;i<n;i++)
        printf("%d ", vector_sol[i]);
    printf("\n");
}

int is_in_vector(int* vector_sol, int k, int x)
{
    for(unsigned int i=0;i<k;i++)
        if(vector_sol[i]==x)
            return 1;
    return 0;
}

void permutari(int n, int* vector_sol, int k)
{
    if(k<n)
    {
        for(unsigned int i=0;i<n;i++)
        {
            if(!is_in_vector(vector_sol,k,i+1))
            {
                vector_sol[k++]=i+1;
                permutari(n, vector_sol, k);
                vector_sol[--k]=0;
             }
        }
    }
    else
        print_sol(vector_sol, n);
}

int main()
{
    int n=4;
    int *vector_sol;
    vector_sol=(int*)calloc(n,sizeof(int));
    int k=0;
    permutari(n, vector_sol, k);
    return 0;
}

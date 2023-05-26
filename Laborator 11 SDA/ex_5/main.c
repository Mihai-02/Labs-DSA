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

void aranjamente(int N, int k, int i_sol, int* vector_sol)
{
    if(i_sol<k)
    {
        for(unsigned int i=1;i<=N;i++)
        {
            if(!is_in_vector(vector_sol,i_sol,i))
            {
                vector_sol[i_sol++]=i;
                aranjamente(N, k, i_sol, vector_sol);
                vector_sol[--i_sol]=0;
            }
        }
    }
    else
        print_sol(vector_sol, k);
}

int valid(int* vector_sol, int k, int x)
{
    for(unsigned int i=0;i<k;i++)
        if(vector_sol[i]>=x)
            return 1;
    return 0;  
}

void combinari(int N, int k, int i_sol, int* vector_sol)
{
    if(i_sol<k)
    {
        for(unsigned int i=1;i<=N;i++)
        {
            if(!valid(vector_sol,i_sol,i))
            {
                vector_sol[i_sol++]=i;
                combinari(N, k, i_sol, vector_sol);
                vector_sol[--i_sol]=0;
            }
        }
    }
    else
        print_sol(vector_sol, k);
}


int main()
{
    int N=6, k=4;
    int *vector_sol;
    vector_sol=(int*)calloc(k, sizeof(int));
    printf("Aranjamente de %d luate cate %d:\n", N, k);
    aranjamente(N, k, 0, vector_sol);
    vector_sol=(int*)calloc(k, sizeof(int));
    printf("combinari de %d luate cate %d:\n", N, k);
    combinari(N, k, 0, vector_sol);
    return 0;
}
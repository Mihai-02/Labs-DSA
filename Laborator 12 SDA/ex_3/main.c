#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

long long int fib_no_memo(long long int n)
{
    if(n==0 || n==1)
        return n;
    return fib_no_memo(n-1)+fib_no_memo(n-2);
}

long long int fib_memo(long long int n, long long int *mem)
{
    if(n==0 || n==1)
        return n;
    if(mem[n]==0)
        mem[n]=fib_memo(n-1, mem)+fib_memo(n-2, mem);
    return mem[n];
   
}

int main()
{
    int n=20;
    long long int fib_n;

    clock_t begin = clock();

    if(n>0)
        fib_n=fib_no_memo(n);
    else
        fib_n=pow(-1, abs(n))*fib_no_memo(-n);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Elementul al %d lea din sirul Fibonacci este %lld\n", n, fib_n);
    printf("Timp fara memoizare:%g\n\n", time_spent);

    n=20;

    begin = clock();

    long long int *mem;
    mem=(long long int*)malloc( (abs(n)+1) * sizeof(long long int));

    if(n>0)
        fib_n=fib_memo(n, mem);
    else
        fib_n=pow(-1, abs(n))*fib_memo(-n,mem);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Elementul al %d lea din sirul Fibonacci este %lld\n", n, fib_n);
    printf("Timp cu memoizare:%g\n", time_spent);

    return 0;
}
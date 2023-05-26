#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functii.h"

#define TEST_AFISARE 1

int main(int argc, char* argv[])
{
    srand(time(NULL));

    Data *vec;
    unsigned int n=atoi(argv[1]);

    vec=(Data*)malloc(n*sizeof(Data));

    for(unsigned int i=0;i<n;i++)       //Popularea sirului de numere cu valori aleatoare din intervalul [-1000,1000]
        vec[i]=rand()%2001-1001;

    stack_t *stack_temp, *stack_poz, *stack_neg;

    stack_temp=stack_create();
    stack_poz=stack_create();
    stack_neg=stack_create();

    for(unsigned int i=0;i<n;i++)
        stack_push(stack_temp, vec[i]);

    creare_stack_noi(stack_temp,stack_poz,stack_neg);


#if TEST_AFISARE==1
    for(unsigned int i=0;i<n;i++)
        printf("%d ", vec[i]);

    node *tp=stack_poz->top;

    printf("\nStack cu numere pozitive:\n");

    while(tp!=NULL)
    {
        printf("%d ", tp->val);
        tp=tp->next;
    }

    tp=stack_neg->top;

    printf("\nStack cu numere negative:\n");

    while(tp!=NULL)
    {
        printf("%d ", tp->val);
        tp=tp->next;
    }
    printf("\n");
#endif
    return 0;
}
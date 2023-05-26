#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "functii.h"

#define N 7
#define TEST_AFISARE 1

int main()
{
    srand(time(NULL));

    queue_t *q;
    q=queue_create();
    for(unsigned int i=0;i<N;i++)
        queue_push(q);

#if TEST_AFISARE==1
    printf("Coada initiala:\n");
    queue_print(q);
#endif

    Data elem;
    while(!queue_empty(q))
    {
        elem=queue_pop(q);
        printf("NOD ELIMINAT: [valoare: %d | prioritate:%u ]\n", elem.val, elem.priority);
        
#if TEST_AFISARE==1
        queue_print(q);
 #endif

    }
        
    return 0;
}
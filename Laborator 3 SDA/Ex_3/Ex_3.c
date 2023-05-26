#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "functii.h"

int main()
{
    srand(time(NULL));

    node_t *head;

    int nr_elem, x;
    nr_elem=rand()%15+5;    //5-15 elemente

    for(unsigned int i=1;i<=nr_elem;i++)
    {
        x=rand()%1000;  //numere intre 0 si 1000
        x*=pow(-1.0,rand()%2);  //numere negative si pozitive

        head=append_node(head,x);  
    }
    print_list(head);
    head=stergere_elemente_pare(head);
    printf("\nDupa stergere:\n");

    print_list(head);
    printf("\n");
    return 0;
}
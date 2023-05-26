#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functii.h"

int main()
{
    srand(time(NULL));

    pol *p1_head=NULL,*p2_head=NULL, *psum_head=NULL;
    int putere_max=rand()%10;   //impunerea ordinului maxim al polinomului
    creare_polinom(&p1_head,putere_max);
    creare_polinom(&p2_head,putere_max);
    pol *tp=p1_head;
    while(tp!=NULL)
    {
       printf("Putere %d si coeficient %d\n",tp->putere, tp->coeficient);
       tp=tp->next;
    }
    tp=p2_head;
    while(tp!=NULL)
    {
       printf("Putere %d si coeficient %d\n",tp->putere, tp->coeficient);
       tp=tp->next;
    }

    creare_suma(p1_head, p2_head, &psum_head, putere_max);

    printf("Polinomul suma:\n");
    tp=psum_head;
    while(tp!=NULL)
    {
       printf("Putere %d si coeficient %d\n",tp->putere, tp->coeficient);
       tp=tp->next;
    }
    return 0;
}
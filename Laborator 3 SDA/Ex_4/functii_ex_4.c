#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "structura.h"

pol *creare_cap(pol *list_head,int putere, int coef)
{
	pol *nod=NULL;
	nod=(pol*)malloc(sizeof(pol));
	if(nod==NULL)
	{
		printf("Alocare esuata");
		exit(1);
	}
	nod->putere=putere;
    nod->coeficient=coef;
	nod->next=list_head;
	list_head=nod;
	return list_head;
}

pol *adaugare_final(pol *list_head, int putere, int coef)
{
	pol *nod,*tp=list_head;
	nod=(pol*)malloc(sizeof(pol));
    if(nod==NULL)
    {   
        printf("Alocare esuata");
        exit(1);   
    }
    nod->putere=putere;
    nod->coeficient=coef;

	while(tp->next!=NULL)
		tp=tp->next;
	tp->next=nod;
	nod->next=NULL;

	return list_head;
}

void creare_polinom(pol **head, int putere)
{
	int coef;
	coef=rand()%20;
    coef*=pow(-1,rand()%2);
    *head=creare_cap(*head,putere,coef);
    putere--;
    while(putere>=0)
    {
		coef=rand()%20;
    	coef*=pow(-1,rand()%2);
        *head=adaugare_final(*head,putere,coef);
        putere--;
    }
}

void creare_suma(pol *p1_head, pol *p2_head, pol **psum_head, int putere)
{
	int sum;
	while(putere>=0)
	{
		sum=p1_head->coeficient+p2_head->coeficient;
		if(sum!=0)
		{
			if(*psum_head==NULL)
				*psum_head=creare_cap(*psum_head,putere,sum);
			else
				*psum_head=adaugare_final(*psum_head,putere,sum);
		}
		putere--;
		p1_head=p1_head->next;
		p2_head=p2_head->next;
	}
	//*psum_head=creare_cap(*psum_head,putere,sum);
}
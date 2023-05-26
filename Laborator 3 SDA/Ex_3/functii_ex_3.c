#include <stdio.h>
#include <stdlib.h>
#include "structura.h"

node_t *create(int val)
{
	node_t *nod;
	nod=(node_t*)malloc(sizeof(node_t));
	if(nod==NULL)
	{
		printf("Alocare esuata.");
		exit(1);
	}
	nod->val=val;
	nod->next=NULL;
	return nod;
}

node_t *prepend_node(node_t *list_head, int val)
{
	node_t *nou=NULL;
	nou=(node_t*)malloc(sizeof(node_t));
	if(nou==NULL)
	{
		printf("Alocare esuata");
		exit(1);
	}
	
	nou->val=val;
	nou->next=list_head;
	list_head=nou;
	return list_head;
}

node_t *append_node(node_t *list_head, int val)
{
	node_t *nou,*tp=list_head;
	nou=create(val);
	if(list_head==NULL)
		list_head=prepend_node(list_head,val);
	else
	{
		while(tp->next!=NULL)
			tp=tp->next;
		tp->next=nou;
		nou->next=NULL;
	}
	return list_head;
}

void print_list(node_t *list_head)
{
	node_t *tp=list_head;
	while(tp->next!=NULL)
	{
		printf("%d, ", tp->val);
		tp=tp->next;
	}
	printf("%d\n", tp->val);
}

node_t * stergere_elemente_pare(node_t *list_head)
{
    node_t *tp=list_head, *ant;

    while(tp->val%2==0) //cat timp capul este par
    {
        list_head=list_head->next;
        free(tp);
        tp=list_head;
    }
    
    ant=list_head;

    while(tp!=NULL)
    {
        if(tp->val%2==0)
       {
            ant->next=tp->next;
            free(tp);
            tp=ant->next;
       }      
        else
        {
            ant=tp;
            tp=tp->next;
        }
    }
  return list_head;
}
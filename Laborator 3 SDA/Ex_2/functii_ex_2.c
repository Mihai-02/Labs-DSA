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

node_t *remove_node(node_t *list_head, int val)
{
	node_t *ant, *tp=list_head;
	ant=tp;
	while(tp!=NULL && tp->val!=val)
	{
		ant=tp;
		tp=tp->next;
	}
	if(ant==tp)	//nodul cu valoarea 'val' este capul listei
		list_head=list_head->next;
	else if(tp!=NULL)
		ant->next=tp->next;
	else
		printf("Elementul nu se afla in lista.\n");	
	free(tp);
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
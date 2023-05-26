#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "structuri.h"

/*Functia creaza o coada goala*/
queue_t *queue_create()
{
	queue_t *queue = NULL;

	queue=(queue_t*)malloc(sizeof(queue_t));
	if(queue==NULL)
	{
		printf("Alocare esuata.");
		exit(1);
	}

	queue->length=0;
	queue->head=queue->tail=NULL;
	return queue;
}

/*Functia creeaza un nod pe care il initializeaza cu o valoare si o prioritate aleatorii*/
queue_node_t *queue_node_create()
{
    //Alocarea spatiului de memorie pentru noul nod
	queue_node_t *node = NULL;
	node=(queue_node_t*)malloc(sizeof(queue_node_t));
	if(node==NULL)
	{
		printf("Alocare esuata.");
		exit(1);
	}

	node->elem.val=rand()%2001-1001;    //Noului nod i se atribuie o valoare cuprinsa in intervalul[-1000,1000]
    node->elem.priority=rand()%11;      //Noului nod i se atribuie o prioritate cuprinsa in intervalul [0,10]	0-minim 10-maxim
	node->next=NULL;
	return node;
}


void queue_push(queue_t *queue)
{
	queue_node_t *node = NULL;

	//Creare nod
	node=queue_node_create();

	if(queue->length==0)		//Daca lista este goala
	{
		queue->tail=node;
		queue->head=queue->tail;
	}
	else			//Adaugarea nodului in lista astfel incat sa se mentina ordinea descrescatoare a prioritatii nodurilor dinspre head/inceput spre tail/sfarsit
	{
		if(queue->head->elem.priority < node->elem.priority)
		{
			node->next=queue->head;
			queue->head=node;
		}
		else
		{
			queue_node_t *tp=queue->head;
			while( tp->next!=NULL && (tp->next)->elem.priority > node->elem.priority)
				tp=tp->next;

			node->next=tp->next;
			tp->next=node;
		}
	}
    queue->length++;
}

void queue_print(queue_t *queue)
{
	//Parcurgere si afisare
	queue_node_t *tp=queue->head;
	while(tp!=NULL)
	{
		printf("Element:%4d | Prioritate:%u\n", tp->elem.val, tp->elem.priority);
		tp=tp->next;
	}
	printf("\n");
}


Data queue_pop(queue_t *queue)
{
	Data elem;

	if(queue->length==0)		//Daca lista este goala
    {
        elem.val=INT_MIN;
        elem.priority=UINT_MAX;
        return elem;
    }
    //Scoaterea nodului de la inceputul listei
    queue_node_t *tp=queue->head;
	queue->head=queue->head->next;

	elem.val=tp->elem.val;
	elem.priority=tp->elem.priority;

	free(tp);
	queue->length--;

	return elem;
}

int queue_empty(queue_t *queue)
{
	if(queue->length==0)
		return 1;
	else
		return 0;
}
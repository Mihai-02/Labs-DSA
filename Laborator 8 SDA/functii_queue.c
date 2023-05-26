#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "structuri.h"

queue_t *queue_create()
{
	queue_t *queue = NULL;

	queue=(queue_t*)malloc(sizeof(queue_t));
	if(queue==NULL)
	{
		printf("Alocare esuata.");
		exit(1);
	}

	queue->el_nr=0;
    queue->size=100;    //implicit

	queue->head=queue->tail=NULL;
	return queue;
}

int queue_empty(queue_t *queue)
{
    return(queue->el_nr==0);
}


queue_node_t *queue_node_create(int val)
{
	queue_node_t *node = NULL;

	node=(queue_node_t*)malloc(sizeof(queue_node_t));

	if(node==NULL)
	{
		printf("Alocare esuata.");
		exit(1);
	}

	node->val=val;
	node->next=NULL;
	return node;
}

void queue_increase_capacity(queue_t* queue)
{
    queue->size*=2;
}

void enqueue(queue_t *queue, int val)
{
	queue_node_t *node = queue_node_create(val);

    queue->el_nr++;
    if(queue->el_nr > queue->size)
        queue_increase_capacity(queue);

    if(queue->tail==NULL)
        queue->tail=node;
    else
    {
        queue->tail->next=node;
        queue->tail=node;
    }

    if(queue->head==NULL)
        queue->head=queue->tail;
}

void queue_print(queue_t *queue)
{
	queue_node_t *tp=queue->head;
	while(tp!=NULL)
	{
		printf("%d ", tp->val);
		tp=tp->next;
	}
	printf("\n");
}

int dequeue(queue_t *queue)
{
	int val = 0;

	if(queue_empty(queue))
		return INT_MIN;

    queue_node_t* tp;
    tp=queue->head;
    val=tp->val;

	//if(queue->head==queue->tail)		//coada are doar un element
	//	queue->tail=NULL;

    queue->head=(queue->head)->next;
	//free(tp);
	
	queue->el_nr--;

	return val;
}

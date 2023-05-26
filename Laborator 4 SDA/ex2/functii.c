#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "structuri.h"

stack_t *stack_create()
{
    stack_t *stack=NULL;
    stack=(stack_t*)malloc(sizeof(stack_t));
    stack->top=NULL;
    stack->length=0;

    return stack;
}

node *stack_node_create(Data val)
{
	node *nod=NULL;

	nod=(node*)malloc(sizeof(node));
	nod->val=val;
	nod->next=NULL;
	return nod;
}

void stack_push(stack_t *stack, Data val)
{
    node *nod=NULL;
    nod=stack_node_create(val);
    nod->next=stack->top;
    stack->top=nod;

    stack->length++;
}

int stack_empty(stack_t *stack)
{
    if(stack->length==0)
        return 1;
    else 
        return 0;
}

Data stack_pop(stack_t *stack)
{
	Data val;

	if(stack_empty(stack))
		val=INT_MIN;

	else
	{
		node *tp=stack->top;
		val=tp->val;
		stack->top=tp->next;
		free(tp);

		stack->length--;
	}

	return val;
}

void creare_stack_noi(stack_t *stack, stack_t *stack_poz, stack_t *stack_neg)
{
    Data aux;

    while(!stack_empty(stack))
    {
        aux=stack_pop(stack);
        if(aux>=0)
            stack_push(stack_poz,aux);
        else
            stack_push(stack_neg,aux);
    }
}

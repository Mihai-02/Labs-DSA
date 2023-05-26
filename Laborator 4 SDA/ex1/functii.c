#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "structuri.h"

stack_t *stack_create()
{
	stack_t *stack = NULL;

	//Alocare memorie pentru o stiva vida
	stack=(stack_t*)malloc(sizeof(stack_t));
	stack->top=NULL;
	stack->length=0;
	return stack;
}

node *stack_node_create(Data val)
{
	node *nod = NULL;

	//Alocare si initializare nod
	nod=(node*)malloc(sizeof(node));
	nod->val=(char*)malloc((strlen(val)-1)*sizeof(char));
	strcpy(nod->val, val);
	nod->next=NULL;
	return nod;
}

void stack_push(stack_t *stack, Data val)
{
	node *nod = NULL;

	//Creeare nod
	nod=stack_node_create(val);
	//Adaugare in stiva
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

	if(stack_empty(stack))	//Daca stiva este goala
		val=NULL;
	//Copiere valoare si stergere nod
	else
	{
		node *tp=stack->top;
		val=(char*)malloc((strlen(tp->val)-1)*sizeof(char));
		strcpy(val,tp->val);
		stack->top=tp->next;
		free(tp);

		stack->length--;
	}

	return val;
}

void afisare_ordine_inversa(stack_t *stack)
{
	FILE *fp;
	if((fp=fopen("output.txt","wt"))==NULL)
    {
        printf("Fisierul nu a putut fi deschis.");
        exit(1);
    }
	char cuv[25];

	while(!stack_empty(stack))
    {
    	strcpy(cuv,stack_pop(stack));
        fprintf(fp,"%s ", cuv);
    }
}
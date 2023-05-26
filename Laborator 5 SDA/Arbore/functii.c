#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structuri.h"

stack_node* stack_node_create(char val[])
{
    stack_node* new=NULL;
    new=(stack_node*)malloc(sizeof(stack_node));
    if(new==NULL)
    {
        printf("Alocare esuata.");
        exit(1);
    }
    new->val=(char*)malloc(strlen(val)*sizeof(char));

    new->next=NULL;
    strcpy(new->val,val);

    return new;
}

stack_s* stack_create()
{
    stack_s *stack=NULL;
    stack=(stack_s*)malloc(sizeof(stack_s));

    stack->elem_nr=0;
    stack->top=NULL;

    return stack;   
}

unsigned int stack_empty(stack_s *stack)
{
    return stack->elem_nr==0;
}

void stack_push(stack_s *stack, char val[])
{
    stack->elem_nr++;
    
    stack_node *new=NULL;
    new=stack_node_create(val);
    new->next=stack->top;
    stack->top=new;   
}

char* stack_pop(stack_s *stack)
{
    if(stack_empty(stack))
        return NULL;
    else
    {
        char *val;

        val=(char*)malloc(strlen(stack->top->val)*sizeof(char));

        strcpy(val,stack->top->val);
        stack_node *aux=stack->top;
        if(stack->elem_nr>1)
            stack->top=stack->top->next;
        free(aux);

        stack->elem_nr--;

        return val;
    }
}

void stack_print(stack_s *stack)
{
	//printf("\nLungime stiva:%d\n",stack->elem_nr);
	stack_node *tp=stack->top;
	while(tp!=NULL)
	{
		printf("%s ", tp->val);
		tp=tp->next;
	}
	printf("\n");
}

void parc(tree_node *root)
{
    if(root!=NULL)
    {
        parc(root->left);
        //printf("%s", root->v);
        parc(root->right);
    }
}

void tree_add(char* exp)
{
    tree_node *nod=(tree_node*)malloc(sizeof(tree_node));
    nod->v=exp[0];
    strcpy(exp,exp+1);

}
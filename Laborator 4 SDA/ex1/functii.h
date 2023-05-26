#include "structuri.h"
stack_t *stack_create();
node *stack_node_create(Data val);
void stack_push(stack_t *stack, Data val);
Data stack_pop(stack_t *stack);
int stack_empty(stack_t *stack);
void afisare_ordine_inversa(stack_t *stack);
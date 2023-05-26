#include "structuri.h"
stack_node* stack_node_create(char *val);
stack_s* stack_create();
void stack_push(stack_s *stack, char *val);
char* stack_pop(stack_s *stack);
void stack_print(stack_s *stack);
unsigned int stack_empty(stack_s *stack);
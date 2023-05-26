#include "structura.h"
node_t *prepend_node(node_t *list_head, int val);
node_t *append_node(node_t *list_head, int val);
node_t *create(int val);
node_t *remove_node(node_t *list_head, int val);
void print_list(node_t *list_head);
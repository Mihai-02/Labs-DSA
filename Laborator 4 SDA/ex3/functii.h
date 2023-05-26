#include "structuri.h"
queue_t *queue_create();
queue_node_t *queue_node_create();
void queue_push(queue_t *queue);
void queue_print(queue_t *queue);
Data queue_pop(queue_t *queue);
int queue_empty(queue_t *queue);
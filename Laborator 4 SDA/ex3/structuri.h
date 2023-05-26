typedef struct 
{
    int val;
    unsigned int priority;
}Data;


typedef struct queue_node_t{
	Data elem;
	struct queue_node_t *next;
} queue_node_t;


typedef struct {
	struct queue_node_t *head;
	struct queue_node_t *tail;
	unsigned int length;
} queue_t;
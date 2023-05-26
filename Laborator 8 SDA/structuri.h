//QUEUE
typedef struct queue_node_t
{
	int val;
	struct queue_node_t *next;
} queue_node_t;

typedef struct 
{
	struct queue_node_t *head;
	struct queue_node_t *tail;

    unsigned int size;
	unsigned int el_nr;
} queue_t;

//GRAF
typedef struct 
{
    int vf;
    int muchii;
    int **matrice;
}Graph;

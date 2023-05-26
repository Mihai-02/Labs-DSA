#include "structuri.h"
//QUEUE
queue_t *queue_create();
int queue_empty(queue_t *queue);
void enqueue(queue_t *queue, int val);
int dequeue(queue_t *queue);

//GRAF
char** citire_fisiere(int *k);
Graph* graph_create(int orientat, char** orase, int n);
void graph_print(Graph *g);
void most_visited_plus_second(Graph* g, char** orase);
void my_city(Graph *g, char** orase);

void BFS(Graph* g, int sursa, char** orase);
void DFS(Graph *g, int sursa, char** orase);
void p_DFS(Graph* g,int sursa, char** orase, int* color, FILE *fp);
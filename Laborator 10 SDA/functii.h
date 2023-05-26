#include "structuri.h"
Graph* graph_create();
void merge_sort(Muchie *m, int l, int r);
Muchie* Kruskal(Graph *g);
void citire_din_fisiere(node** toate_head);
void create_unique_vect(node *head,char **vect[], int *i);
int get_code(char *vect[], int n, char statie[]);
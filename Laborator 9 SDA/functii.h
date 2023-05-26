#include "structuri.h"
//EX 1
void citire_din_fisiere(node** toate_head);
void create_unique_list(node *head,node **newhead, int *i);
//EX 2
Graph* graph_create(int orientat, node* lista_km, node* lista_unice, int n);
void aflu_i_oras_curent(node* head, char statie[], int *i);
//EX 3
void dist_min_max(node* head);
//EX 4
void total_km(node* head);
//EX 5
void Dijkstra(Graph *g, int i_sursa, int *cost, int *parinte);
void ruta_natal(int *v_cost, int *par,char *oras_n, int i_natal, node *unic_head);
//EX 6
void departe(int *v_cost, node* unic_head, int n, int *par, char *statie_max, int *i_max);
void afisare_drum_max(int j, char *statie, int cost_max, node* unic_head, int *par);
//EX 7
void toate_bucuresti_oradea(node* toate_head, int i_buc, int i_oradea);
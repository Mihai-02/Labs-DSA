typedef struct{
    int v1, v2;
    int cost;
}Muchie;

typedef struct{
    int nr_vf, nr_muchii;
    Muchie *m;
}Graph;

//structura lista orase
typedef struct nod
{
    char nume_statie[30];
    char cod_tren[6];
    int kilometri;
    struct nod *next;
}node;
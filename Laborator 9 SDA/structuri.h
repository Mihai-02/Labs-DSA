//structura lista orase; campurile care nu sunt necesare unei liste sunt completate cu -1 de-a lungul intregii liste
typedef struct nod
{
    char nume_statie[30];
    char cod_tren[6];
    int kilometri;
    int i;
    struct nod *next;
}node;

//GRAF
typedef struct 
{
    int vf;
    int muchii;
    int **m_adi;
    int **m_cost;
}Graph;

//Lista rute distanta minima/maxima
typedef struct structura
{
    char ruta[75];
    struct structura *next;
}drum_t;
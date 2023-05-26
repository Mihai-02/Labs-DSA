typedef struct nod_arbore
{
    char v;
    struct nod_arbore *left;
    struct nod_arbore *right;
}tree_node;

typedef struct nod
{
    char* val;
    struct nod *next;
}stack_node;

typedef struct stiva
{
    stack_node *top;
    int elem_nr;
}stack_s;



typedef char* Data;

typedef struct elem
{
    Data val;
    struct elem* next;
}node;

typedef struct
{
    node *top;
    unsigned int length;
}stack_t;

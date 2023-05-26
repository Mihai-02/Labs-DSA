
typedef int Data;

typedef struct Node
{
    Data val;
    struct Node *next;
}node;

typedef struct 
{
    node *top;
    unsigned int length;
}stack_t;

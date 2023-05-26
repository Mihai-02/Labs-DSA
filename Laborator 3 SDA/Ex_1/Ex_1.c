#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

int main()
{
    dbnode *head=NULL;
    head=creare_lista_angajati(head);
    
    adaugare_dupa_al_treilea(&head);
    adaugare_inainte_mecanic(&head);
    stergere_dupa_nr_tel(&head);

    return 0;
}
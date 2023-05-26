#include "structura.h"
dbnode *creare_lista_angajati(dbnode *list_head);
dbnode *adaugare_angajat(dbnode** list_head, char Nume[], char Nr_tel[], char Post[]);
dbnode *prepend(dbnode *list_head, char Nume[],char Nr_tel[],char Post[]);
dbnode *create(char Nume[],char Nr_tel[],char Post[]);
void adaugare_dupa_al_treilea(dbnode** head);
void citire_angajat(char Nume[], char Nr_tel[], char Post[]);
void adaugare_inainte_mecanic(dbnode** head);
void stergere_dupa_nr_tel(dbnode** head);
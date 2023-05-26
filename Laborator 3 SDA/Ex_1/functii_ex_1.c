#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "functii.h"

void citire_angajat(char Nume[], char Nr_tel[], char Post[])
{
    unsigned int ok;
    printf("\tNume:");
    scanf("%s", Nume);
    do
    {
        printf("\tNumarul de telefon(10 cifre):");
        scanf("%s", Nr_tel);
        ok=1;
        for(unsigned int i=0;i<10;i++)
            if(!isdigit(Nr_tel[i]))
                ok=0;
    } while (strlen(Nr_tel)!=10 || ok==0);
    printf("\tPost:");
    scanf("%s", Post);
}

void adaugare_dupa_al_treilea(dbnode** head)
{
    dbnode *nou, *tp;
    char Nume[30],Nr_tel[11],Post[25];
    printf("\nIntroduceti un angajat de introdus dupa al treilea:\n");
    citire_angajat(Nume,Nr_tel,Post);
    
    nou=create(Nume,Nr_tel,Post);
    
    tp=(*head)->next->next;
    (tp->next)->prev=nou;
    nou->next=tp->next;
    tp->next=nou;
    nou->prev=tp;
    
}

void adaugare_inainte_mecanic(dbnode** head)
{
    dbnode *nou,*tp=*head;
    unsigned int ciclu_nou=0;
    char Nume[30],Nr_tel[11],Post[25];
    printf("\nIntroduceti un angajat de introdus inaintea mecanicului:\n");
    citire_angajat(Nume,Nr_tel,Post);

    nou=create(Nume,Nr_tel,Post);

    while(ciclu_nou==0 && strcmp((tp->next)->post,"mecanic") && strcmp((tp->next)->post,"Mecanic"))
    {
        tp=tp->next;
        if(tp==*head)
            ciclu_nou=1;
    }

    if(tp==*head && ciclu_nou==1)
    {
        printf("\nNu exista nici un mecanic in lista.\n");
        return;
    }
    else
    {
        if (tp->next==*head)
        {
            (*head)->prev=nou;
            nou->next=*head;
            *head=nou;
        }
        else
        {
            (tp->next)->prev=nou;
            nou->next=tp->next;
        }
        nou->prev=tp;
        tp->next=nou;
    }
}

void stergere_dupa_nr_tel(dbnode** head)
{
    unsigned int ok;
    char Nr_tel[11];
    do
    {
        printf("\nIntroduceti numarul de telefon al angajatului de sters(10 cifre):");
        scanf("%s", Nr_tel);
        ok=1;
        for(unsigned int i=0;i<10;i++)
            if(!isdigit(Nr_tel[i]))
                ok=0;
    } while (strlen(Nr_tel)!=10 || ok==0);


    unsigned int ciclu_nou=0;
    dbnode *tp=*head;
    while(ciclu_nou==0 && strcmp((tp->next)->nr_tel,Nr_tel))
    {
        tp=tp->next;
        if(tp==*head)
            ciclu_nou=1;
    }
        

    if(tp==*head && ciclu_nou==1)
    {
        printf("\nNu exista nici o persoana cu numarul de telefon introdus.\n");
        return;
    }
    else
    {
        if(tp->next==*head)
        {
            ((*head)->next)->prev=tp;
            tp->next=(*head)->next;
            free(*head);
            *head=tp->next;
        }
        else
        {
            dbnode *de_sters=tp->next;
            tp->next=de_sters->next;
            (de_sters->next)->prev=tp;
            free(de_sters);
        }
    }
}
/*===========================================================================================
        EX 1: citire date din fisiere si creare liste(toate statiile si statii unice)
===========================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structuri.h"

node* create_node(char s[], char cod[],char km[], int i)
{
    node *new=(node*)malloc(sizeof(node));
    strcpy(new->nume_statie,s);
    strcpy(new->cod_tren,cod);
    new->kilometri=atoi(km);
    new->i=i;
    new->next=NULL;
    return new;
}

node* add_at_beginning(node** head, char s[], char cod[],char km[], int i)
{
    node *new=create_node(s,cod,km,i);
    new->next=*head;
    *head=new;
    return *head;
}

void add_at_end(node*** head, char s[], char cod[],char km[], int i)
{
    node* tp=**head;
    if(**head==NULL)
        **head=add_at_beginning(*head,s,cod,km,i);
    else
    {
        while(tp->next!=NULL)
            tp=tp->next;
        node *new=create_node(s,cod,km,i);
        tp->next=new;
    }
}

int is_station_in_list(node* head, char statie[])
{
    if(head==NULL)
        return 0;
    while(head!=NULL)
    {
        if(!strcmp(head->nume_statie,statie))
            return 1;
        head=head->next;
    }
    return 0;
}

void citire_din_fisiere(node** toate_head)
{
    FILE *f,*g;
    char tren[25],statie[50],km[5],locatie[100];;


    f=fopen("_all_files.txt","rt");

    if(f==NULL)
    {
        printf("Fisierul nu a putut fi deschis.\n");
        exit(1);
    }

    while(fscanf(f,"%s",tren) == 1)
    {
        strcpy(locatie,"trains/");
        strcat(locatie,tren);
        g=fopen(locatie,"rt");
        if(g==NULL)
        {
            printf("Fisierul %s nu a putut fi deschis.\n",tren);
            exit(1);
        }

        tren[strlen(tren)-4]='\0';      //eliminare ".txt" din codul trenului

        while(fgets(statie,100,g))
        {
            statie[strlen(statie)-1]='\0';          //separare km si numele statiei
            strcpy(km,strchr(statie,',')+2);
            statie[strlen(statie)-strlen(km)-2]='\0';
            km[strlen(km)]='\0';


            add_at_end(&toate_head, statie, tren, km, -1);
        }
        fclose(g);
    }
    fclose(f);
}

void create_unique_list(node *head,node **newhead, int *i)
{
     while(head!=NULL)
    {
         if(!is_station_in_list(*newhead, head->nume_statie))
        {
            add_at_end(&newhead,head->nume_statie,head->cod_tren,"-1",*i);
            (*i)++;
         }
        head=head->next;
    }
}

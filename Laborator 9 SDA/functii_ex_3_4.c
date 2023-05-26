/*==================================================================================================
        EX 3: determinare distanta minima/maxima intre 2 statii consecutive si creare fisiere
==================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structuri.h"

drum_t* create_ruta(char tp[])
{
    drum_t *new=(drum_t*)malloc(sizeof(drum_t));
    strcpy(new->ruta,tp);
    new->next=NULL;
    return new;
}

drum_t* add_ruta_at_beginning(drum_t* head, char tp[])
{
    drum_t *new=create_ruta(tp);
    new->next=head;
    head=new;
    return head;
}

void add_ruta_at_end(drum_t** head, char tp[])
{
    drum_t* temp=*head;
    if(*head==NULL)
        *head=add_ruta_at_beginning(*head,tp);
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;
        drum_t *new=create_ruta(tp);
        temp->next=new;
    }
}

int is_ruta_in_list(drum_t* head, char tp[])
{
    if(head==NULL)
        return 0;
    while(head!=NULL)
    {
        if(!strcmp(head->ruta,tp))
            return 1;
        head=head->next;
    }
    return 0;
}

void print_rute(FILE *f, drum_t *head)
{
    while(head!=NULL)
    {
        fprintf(f, "%s\n", head->ruta);
        head=head->next;
    }
}


void dist_min_max(node* head)
{
    int dist_min,dist_max,d;

    node* statie_pred=head, *headcopy=head;
    head=head->next;

    dist_min=dist_max=head->kilometri-statie_pred->kilometri;

    while(head!=NULL)
    {
        if(!strcmp(head->cod_tren,statie_pred->cod_tren))
        {
            d=head->kilometri-statie_pred->kilometri;
            if(d>dist_max)
                dist_max=d;
            else if(d<dist_min)
                dist_min=d;
        }
        statie_pred=head;
        head=head->next;
    }

    drum_t *list_min=NULL, *list_max=NULL;
    char ruta_temp[75];

    statie_pred=headcopy;
    headcopy=headcopy->next;

    while(headcopy!=NULL)
    {
        if(!strcmp(headcopy->cod_tren,statie_pred->cod_tren))
        {
            d=headcopy->kilometri-statie_pred->kilometri;
            if(d==dist_max)
            {
                strcpy(ruta_temp,statie_pred->nume_statie);
                strcat(ruta_temp," - ");
                strcat(ruta_temp,headcopy->nume_statie);

                if(!is_ruta_in_list(list_max,ruta_temp))
                    add_ruta_at_end(&list_max,ruta_temp);
            }
            else if(d==dist_min)
            {
                strcpy(ruta_temp,statie_pred->nume_statie);
                strcat(ruta_temp," - ");
                strcat(ruta_temp,headcopy->nume_statie);

                if(!is_ruta_in_list(list_min,ruta_temp))
                    add_ruta_at_end(&list_min,ruta_temp);
            }
        }
        statie_pred=headcopy;
        headcopy=headcopy->next;
    }

    FILE *f_min, *f_max;
    f_min=fopen("min.txt","wt");

    if(f_min==NULL)
    {
        printf("Fisierul min nu a putut fi deschis.\n");
        exit(1);
    }

    f_max=fopen("max.txt","wt");

    if(f_max==NULL)
    {
        printf("Fisierul max nu a putut fi deschis.\n");
        exit(1);
    }

    fprintf(f_min,"Distanta minima: %d km\nStatii:\n",dist_min);
    fprintf(f_max,"Distanta maxima: %d km\nStatii:\n",dist_max);

    print_rute(f_min,list_min);
    print_rute(f_max,list_max);

    fclose(f_min);
    fclose(f_max);
}


/*=================================================================================================================
        EX 4: calcularea numarului total de km de cale ferata (calea ferata dintre doua statii consecutive e 
        luata in considerare o singura data, chiar daca aceleasi doua statii apar in doua sau mai multe fisiere 
        diferite in aceeasi ordine)
==================================================================================================================*/

void total_km(node* head)
{
    int suma=0;
    char ruta_temp[75];

    drum_t* drum_unice=NULL;
    node* statie_pred=head;
    head=head->next;

    while(head!=NULL)
    {
        if(!strcmp(head->cod_tren,statie_pred->cod_tren))
        {
            strcpy(ruta_temp,statie_pred->nume_statie);
            strcat(ruta_temp," - ");
            strcat(ruta_temp,head->nume_statie);
            if(!is_ruta_in_list(drum_unice,ruta_temp))
            {

                suma+=head->kilometri-statie_pred->kilometri;
            }
        }
        statie_pred=head;
        head=head->next;
    }

    FILE *f;
    f=fopen("total.txt","wt");
    if(f==NULL)
    {
        printf("Fisierul total nu a putut fi deschis.\n");
        exit(1);
    }

    fprintf(f,"Numar total de kilometri: %dkm",suma);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structuri.h"

node* create_node(char s[], char cod[],char km[])
{
    node *new=(node*)malloc(sizeof(node));
    strcpy(new->nume_statie,s);
    strcpy(new->cod_tren,cod);
    new->kilometri=atoi(km);
    new->next=NULL;
    return new;
}

node* add_at_beginning(node** head, char s[], char cod[], char km[])
{
    node *new=create_node(s,cod,km);
    new->next=*head;
    *head=new;
    return *head;
}

void add_at_end(node*** head, char s[], char cod[], char km[])
{
    node* tp=**head;
    if(**head==NULL)
        **head=add_at_beginning(*head,s,cod,km);
    else
    {
        while(tp->next!=NULL)
            tp=tp->next;
        node *new=create_node(s,cod,km);
        tp->next=new;
    }
}

void citire_din_fisiere(node** toate_head)
{
    FILE *f,*g;
    char tren[25],statie[50],km[5],locatie[100];


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


            add_at_end(&toate_head, statie, tren, km);
        }
        fclose(g);
    }
    fclose(f);
}

int is_station_in_list(char *vect[], char statie[], int i)
{
    for(int k=0;k<i;k++)
    {
        if(!strcmp(vect[k],statie))
            return 1;
    }
        
    return 0;
}

void add_in_vector(char ***vect[], char s[], int *i, int *size)
{
    if(*i+1 == *size)
    {
        (*size)*=2;
        **vect=(char**)realloc(**vect, *size*sizeof(char*));
    }
    (**vect)[*i]=(char*)malloc((strlen(s)+1)*sizeof(char));
    strcpy((**vect)[*i],s);
    (*i)++;
}

void create_unique_vect(node *head,char **vect[], int *i)
{
    int size=50;
    *vect=(char**)malloc(size*sizeof(char*));

    while(head!=NULL)
    {
         if(!is_station_in_list(*vect, head->nume_statie,*i))
            add_in_vector(&vect, head->nume_statie, i, &size);
        head=head->next;
    }
}

int get_code(char *vect[], int n, char statie[])
{
    for(unsigned int i=0;i<n;i++)
        if(!strcmp(statie, vect[i]))
            return i;
    return -1;
}


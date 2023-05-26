#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structura.h"

dbnode *create(char Nume[],char Nr_tel[],char Post[])
{
	dbnode *nod;
	nod=(dbnode*)malloc(sizeof(dbnode));
	if(nod==NULL)
	{
		printf("Alocare esuata.");
		exit(1);
	}
	nod->nume=(char*)malloc((strlen(Nume)+1)*sizeof(char));
	nod->nr_tel=(char*)malloc((strlen(Nr_tel)+1)*sizeof(char));
	nod->post=(char*)malloc((strlen(Post)+1)*sizeof(char));
	if(nod->nume==NULL || nod->nr_tel==NULL || nod->post==NULL)
	{
		printf("Alocare esuata.");
		exit(1);
	}
	strcpy(nod->nume,Nume);
	strcpy(nod->nr_tel,Nr_tel);
    strcpy(nod->post,Post);
	nod->next=NULL;
	return nod;
}

dbnode *prepend(dbnode *list_head, char Nume[],char Nr_tel[],char Post[])
{
	dbnode *nod=NULL;
	nod=(dbnode*)malloc(sizeof(dbnode));
	if(nod==NULL)
	{
		printf("Alocare esuata");
		exit(1);
	}
	nod->nume=(char*)malloc((strlen(Nume)+1)*sizeof(char));
	nod->nr_tel=(char*)malloc((strlen(Nr_tel)+1)*sizeof(char));
	nod->post=(char*)malloc((strlen(Post)+1)*sizeof(char));
	if(nod->nume==NULL || nod->nr_tel==NULL || nod->post==NULL)
	{
		printf("Alocare esuata.");
		exit(1);
	}
	strcpy(nod->nume,Nume);
	strcpy(nod->nr_tel,Nr_tel);
    strcpy(nod->post,Post);
	nod->next=list_head;
	list_head=nod;
	return list_head;
}

dbnode *adaugare_angajat(dbnode *list_head, char Nume[], char Nr_tel[], char Post[])
{
    dbnode *nou,*tp=list_head;
	nou=create(Nume,Nr_tel,Post);
	if(list_head==NULL)
		list_head=prepend(list_head,Nume,Nr_tel,Post);
	else
	{
		while(tp->next!=NULL)
			tp=tp->next;
		
		tp->next=nou;
		nou->next=NULL;
		nou->prev=tp;
	}
	return list_head;
}

dbnode *creare_lista_angajati(dbnode *list_head)
{
    FILE *fp;
    if((fp=fopen("angajati_ex_1.txt","rt"))==NULL)
    {
        printf("Fisierul nu a putut fi deschis.");
        exit(1);
    }

    char Nume[30],Nr_tel[11],Post[25];
    for(unsigned int i=1;i<=6;i++)
    {
        fscanf(fp,"%s %s %s", Nume, Nr_tel, Post);
        list_head=adaugare_angajat(list_head,Nume,Nr_tel,Post);
    }
	fclose(fp);
	dbnode *tp=list_head;
	while(tp->next!=NULL)
		tp=tp->next;
	tp->next=list_head;
	list_head->prev=tp;

    return list_head;
}
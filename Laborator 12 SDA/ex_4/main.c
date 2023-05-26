#include <stdio.h>
#include <stdlib.h>

int nr_tipuri;

int rest_no_memo(int rest, int *monede, int tip)
{
    if (tip>=nr_tipuri-1) 
        return 1;
    int cate_moduri=0;
    int val=monede[tip];
    int i, ce_ramane;
    for (i=0; i*val<=rest; i++)
    {
        ce_ramane=rest-i*val;
        cate_moduri+=rest_no_memo(ce_ramane, monede, tip+1); 
    }   
    return cate_moduri;
}

int rest_memo(int rest, int *monede, int tip, int **aux)
{
    if (aux[rest][tip]>0) 
        return aux[rest][tip];
    if(tip>=nr_tipuri-1) 
        return 1;
    int cate_moduri=0;
    int i,ce_ramane,val=monede[tip];
    for (i=0;i*val<=rest;i++) 
    {
        ce_ramane=rest-i*val;
        cate_moduri+=rest_memo(ce_ramane,monede,tip+1,aux);
    }
    aux[rest][tip]=cate_moduri;
    return cate_moduri;
}

int main()
{
    int n=50;
    int monede[]={25,10,5,1};
    nr_tipuri=sizeof(monede)/sizeof(monede[0]);
    printf("Fara memoizare - %d\n", rest_no_memo(n,monede,0));

    int **aux;

    aux=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n+1;i++)
        aux[i]=(int*)calloc(nr_tipuri,sizeof(int));
    printf("Cu memoizare - %d\n", rest_memo(n,monede,0,aux));
    return 0;
}

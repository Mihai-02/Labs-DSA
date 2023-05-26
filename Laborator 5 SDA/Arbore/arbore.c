#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "functii.h"

int main()
{
    FILE *fp;
    fp=fopen("expresii","rt");

    stack_s *operanzi_rez, *operatori;
    operanzi_rez=stack_create();
    operatori=stack_create();

    char expr[50],sir_de_un_car[1];
    fgets(expr,50,fp);

    //printf("%s\n", expr);

   // for(unsigned int i=0;i<strlen(expr);i++)
    //    printf("%c",expr[i]);
    printf("\n");
    for(unsigned int i=0;i<strlen(expr);i++)
    {
        //printf("%c",expr[i]);
        if(isdigit(expr[i]))           //termenul e operand
        {
            strncpy(sir_de_un_car,expr+i,1);
            stack_push(operanzi_rez,sir_de_un_car);
        } 
         else                           //termenul e operator
        {
            if(!stack_empty(operatori))
            {

                // daca operatorul curent are prioritate mai mare decat topul stivei
                if( (!strcmp(operatori->top->val,"+") || !strcmp(operatori->top->val,"-"))  || ((!strcmp(operatori->top->val,"*") || !strcmp(operatori->top->val,"/")) && (expr[i]=='*' || expr[i]=='/')) )
                   {
                        //printf("ok");
                        strncpy(sir_de_un_car,expr+i,1);
                        //printf("%s\n",sir_de_un_car);
                        stack_push(operatori,sir_de_un_car);
                    } 
                 else
                {
                     char op[1],temp[1];
                     char rez_tp[50];
                     strcpy(op,stack_pop(operatori));   //primul operator
                     strcpy(rez_tp,op);               
                     strcpy(temp,stack_pop(operanzi_rez));  //primul operand
                     strcat(rez_tp,temp);
                     strcat(rez_tp,op);                 //al doilea operator
                     strcpy(temp,stack_pop(operanzi_rez));
                     strcat(rez_tp,temp);               //al doilea operand

                     stack_push(operanzi_rez,rez_tp);
                     strncpy(sir_de_un_car,expr+i,1);
                     stack_push(operatori,sir_de_un_car);
                     //stack_push(operatori,expr[i]);
                }  
            }
            else
            {
                strncpy(sir_de_un_car,expr+i,1);
                //printf("%s\n",sir_de_un_car);
                stack_push(operatori,sir_de_un_car);
            } 
        } 
            
    }
    stack_print(operanzi_rez);
    stack_print(operatori);
    return 0;
}
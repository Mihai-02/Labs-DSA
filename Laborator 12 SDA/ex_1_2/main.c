#include <stdio.h>
#include <stdlib.h>
#include <math.h>       //Doar logaritmul foloseste math.h (pow), radicalul nu

double radical_2(double x, double s, double d)
{
    if(x<=0)
        printf("Input invalid\n");
    if(d-s<10e-6) 
        return d;
    else
    {
        double m=(s+d)/2;
        if(m*m<x)
            return radical_2(x,m,d);
        else if(m*m>x) 
            return radical_2(x,s,m); 
        else
            return m;
    }
}

double radical_3(double x, double s, double d)
{
    if(d-s<10e-6) 
        return d;
    else
    { 
    double m=(s+d)/2;
        if(m*m*m<x) 
            return radical_3(x,m,d);
        else if(m*m*m>x)
            return radical_3(x,s,m);
        else
            return m; 
       }
}

double logaritm(double x, double s, double d)
{
    if(x<=0)
        printf("Input invalid\n");
    if(d-s<10e-3) 
        return d;
    else
    { 
        double m=(s+d)/2;
        if(pow(10,m)<x)
            return logaritm(x,m,d);
        else if(pow(10,m)>x) 
            return logaritm(x,s,m);
        else
            return m; 
    }
}

int main()
{
    double n=90;
    double x=26;
    double y=2537;
    printf("sqrt(%g)=%.6f\n", n, radical_2(n,0,n));
    printf("cbrt(%g)=%.6f\n", x, radical_3(x,0,x));
    printf("log(%g)=%.3f\n", y, logaritm(y,0,y));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define BYTE 8
#define COUNT_BYTE 256

int obtineOctetul(int n,int byteNr)
{ 
    int bitsNr =  BYTE * byteNr;
    int mask = COUNT_BYTE - 1;
    return (n >> bitsNr) & mask;
}
void rad(int *a,int *b, int byteNr,int n)
{ 
    int i, count[COUNT_BYTE] = {0}, index[COUNT_BYTE] = {0};
    for(i = 0; i < n;i++) {
        int car = obtineOctetul(a[i],byteNr);
        count[car]++;
    }
    for(i = 1;i < COUNT_BYTE;i++)
        index[i] = index[i-1] + count[i-1];
    for(i = 0; i < n; i++) { 
        int car = obtineOctetul(a[i],byteNr);
        b[index[car]++] = a[i];
    }
}
void radixSort(int *a,int n)
{
    int *b=(int*)malloc(n*sizeof(int)), byteNr, k = sizeof(a[0]);
    for(byteNr = 0; byteNr < k; byteNr += 2) {
        rad(a, b, byteNr, n);
        rad(b, a, byteNr + 1, n);
    }
    free(b);
}
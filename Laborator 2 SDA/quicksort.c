void swap(int a, int b)
{
    int aux=a;
    a=b;
    b=aux;
} 

int partition(int *v, int l, int r)
{
    int piv=v[r];
    int i=l-1;

    for(unsigned int j=l;j<r;j++)
        if(v[j]<piv)
        {
            i++;
            swap(v[j],v[r]);
        }
    swap(v[i+1],v[r]);
    return i+1;
            
}

void quicksort(int *v, int l, int r)
{
    if(l<r)
    {
        int pivot=partition(v,l,r);
        quicksort(v, l, pivot-1);
        quicksort(v, pivot+1, r);
    }
        
}
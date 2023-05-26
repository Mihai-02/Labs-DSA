void A(int v[], unsigned int n)     //SELECTION SORT
{
    extern unsigned int nr_pasi_selection;
    nr_pasi_selection=0;
    int minim,i_min;
    for(unsigned int m=0;m<n-1;m++)
    {
        minim=v[m];
        i_min=m;
        for(unsigned int i=m+1;i<n;i++)
        {
            nr_pasi_selection++;
            if(v[i]<minim)
            {
                i_min=i;
                minim=v[i];
            }
        }
        v[i_min]=v[m];
        v[m]=minim;
    }
}

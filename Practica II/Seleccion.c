#include<stdio.h>

void main(){

    int v[10]={8,5,2,6,9,3,1,4,0,7};
    double tmp;
    int i, j, pos_min, n=10;

    for(i=0; i<=n-1; i++){
        pos_min=i;

        for(j=i+1; j<n; j++)
            if(v[j]<v[pos_min])
                pos_min=j;

        tmp=v[i];
        v[i]=v[pos_min];
        v[pos_min]=tmp;
    }

    printf("Lista Ordenada");

}

#include<stdio.h>

void main(){

    int v[10]={8,5,2,6,9,3,1,4,0,7};
    double tmp;
    int i, j, n=10;

    for(i=1; i<n; i++){
        tmp=v[i];

        for(j=i; (j>0) && (tmp<v[j-1]); j--)
            v[j]=v[j-1];

        v[j]=tmp;
    }

    printf("Lista Ordenada");
}

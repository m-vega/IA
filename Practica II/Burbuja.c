#include<stdio.h>

void main(){

    int v[10]={8,5,2,6,9,3,1,4,0,7};
    double tmp;
    int i, j, n=10;

    for(i=0; i<n-1; i++)
        for(j=n-1; j>i; j--)
            if(v[j]<v[j-1]){
                tmp=v[j];
                v[j]=v[j-1];
                v[j-1]=tmp;
            }

    printf("Lista Ordenada");
}

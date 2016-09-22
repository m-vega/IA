#include <stdio.h>

void main(){

    int v[10]={5,2,6,9,3,1,4,0,7,8}, n=10;
    int j,item,tmp,i,k;

    for(k=n-1; k>=0; k--){

        for(i=1; i<=k; i++){
            item=v[i];
            j=i/2;

            while(j>0 && v[j]<item){
                v[i]=v[j];
                i=j;
                j=j/2;
            }

            v[i]=item;
        }

        tmp=v[1];
        v[1]=v[k];
        v[k]=tmp;
    }

    printf("Lista Ordenada");
}

#include <stdio.h>

void main(){

    int v[10]={8,5,2,6,9,3,1,4,0,7}, n=10,i;

    quicksort(v, 0, n-1);

    printf("Lista Ordenada");
}

int pivot(int *v, int izq, int der)
{
    int i;
    int pivote, valor_pivote;
    int aux;

    pivote = izq;
    valor_pivote = v[pivote];
    for (i=izq+1; i<=der; i++){
        if (v[i] < valor_pivote){
                pivote++;
                aux=v[i];
                v[i]=v[pivote];
                v[pivote]=aux;

        }
    }
    aux=v[izq];
    v[izq]=v[pivote];
    v[pivote]=aux;
    return pivote;
}

void quicksort(int *v, int izq, int der)
{
     int pivote;
     if(izq < der){
        pivote=pivot(v, izq, der);
        quicksort(v, izq, pivote-1);
        quicksort(v, pivote+1, der);
     }
}

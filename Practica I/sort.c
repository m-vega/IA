#include<stdio.h>
#include <time.h>

void main(){

    //Declaracion de Variables
    int a,b,c=0,i,j,auxiliar,posicionValorMenor,valorMenor;
    int matriz[4][4]={{9,5,7,2},{0,1,5,6},{7,9,3,7},{3,2,4,5}};
    int arreglo[16];

    //Valores de Matriz a Arreglo
    for(a=0; a<4; a++){
        for (b=0; b<4; b++){
            arreglo[c]=matriz[a][b];
            c++;
        }
    }

    //Ordenar Arreglo
    for(i=0; i<16 ; i++){

        valorMenor = arreglo[i];

        for(j=i; j<16; j++){

            if(arreglo[j] <= valorMenor){
                valorMenor = arreglo[j];
                posicionValorMenor = j;
            }
    }

        auxiliar = arreglo[i];
        arreglo[i] = valorMenor;
        arreglo[posicionValorMenor] = auxiliar;
    }

    //Regresar los valores a Matriz
    c=0;
    b=0;
    
    for(a=0; a<4; a++){

        if(b==0)
            for (b=0; b<4; b++){
                matriz[a][b]=arreglo[c];
                c++;
            }

        else
            for (b; b>0; b--){
                matriz[a][b]=arreglo[c];
                c++;
            }
    }

    printf("Matriz Ordenada");
}
	
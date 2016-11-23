#include<stdio.h>

int siguienteRenglon(int actual, int m[][5]){
	
	int i, j;
	
	for(i=0; i<8 ;i++){
		
		for(j=0; m[actual][j] != 0; j++){

	    	if(i == m[actual][j])
	        	return i;

		}

	}

}


void profundidad(int inicial, int destino, int m[][5]){

    int j, actual, siguiente;

	actual=inicial;

	printf("%d ", actual+1);

    for(j=0; (j<5) && (m[actual][j] != 0); j++){

    	//printf("\n%d\n",m[actual][j]);

    	if(m[actual][j] == destino){
        	printf("%d \nHaz llegado al destino", destino);
        	return;
    	}

    }

    siguiente = siguienteRenglon(actual, m);
    profundidad(siguiente, destino, m);

}


void main(){

    int m[8][5] =
        {
            {2,3,6,8,0},
            {1,3,4,5,8},
            {1,2,4,0,0},
            {3,2,5,8,0},
            {2,4,8,0,0},
            {1,7,0,0,0},
            {6,8,0,0,0},
            {1,2,4,5,0}
        };

    int inicial, destino;

    printf("Ingrese la posicion en la que se encuentra: ");
    scanf("%d",&inicial);

    printf("Ingrese a donde quiere llegar: ");
    scanf("%d",&destino);

    if(inicial == destino){
        printf("Ya estas en el destino");
    }
    else{
        profundidad(inicial-1, destino, m);
    }

}

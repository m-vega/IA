/*
	Elaborado por: Manuel Vega y Jose Luis Alarez
	Fecha: 30 de agosto de 2016
*/

function sort(){

	var start = new Date().getTime();

	var c = 0;
	var matriz = [[9,5,7,2],[0,1,5,6],[7,9,3,7],[3,2,4,5]];
	var arreglo = [];

	var a, b;

	for(a=0; a<4; a++){
		for(b=0; b<4; b++){
			arreglo[c] = matriz[a][b];
			c++;
		}
	}

	var i, valorMenor, j, posicionValorMenor, auxiliar;

	for(i=0; i<16; i++){

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

	console.log(arreglo);

	c = 0;
	b = 0;

	for(a=0; a<4; a++){

		if(b == 0){
			for(b=0; b<4; b++){
				matriz[a][b] = arreglo[c];
				c++;
			}
		}
		else{
			for(b; b>0; b--){
				matriz[a][b] = arreglo[c];
				c++;
			}
		}	


	}

	var end = new Date().getTime();
	var time = end - start;
	alert('Tiempo de ejecucion: ' + time + " milisegundos");

}

sort();
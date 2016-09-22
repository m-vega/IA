/*
	Elaborado por: Manuel Vega y Jose Luis Alarez
	Fecha: 20 de septiembre de 2016
*/

function burbuja(){

	var start = new Date().getTime();

	var v = [8,5,2,6,9,3,1,4,0,7];
	var tmp;
	var i;
	var j;
	var n = 10;

	for(i=0; i<n-1; i++)
        for(j=n-1; j>i; j--)
            if(v[j]<v[j-1]){
                tmp=v[j];
                v[j]=v[j-1];
                v[j-1]=tmp;
            }

	var end = new Date().getTime();
	var time = end - start;
	alert('Tiempo de ejecucion: ' + time + " milisegundos");

}

burbuja();
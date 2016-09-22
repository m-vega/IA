/*
	Elaborado por: Manuel Vega y Jose Luis Alarez
	Fecha: 20 de septiembre de 2016
*/

function insercion(){

	var start = new Date().getTime();

	var v = [8,5,2,6,9,3,1,4,0,7];
	var tmp;
	var i;
	var j;
	var n = 10;

	for(i=1; i<n; i++){
        tmp=v[i];

        for(j=i; (j>0) && (tmp<v[j-1]); j--)
            v[j]=v[j-1];

        v[j]=tmp;
    }

	var end = new Date().getTime();
	var time = end - start;
	alert('Tiempo de ejecucion: ' + time + " milisegundos");

}

insercion();
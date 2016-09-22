/*
	Elaborado por: Manuel Vega y Jose Luis Alarez
	Fecha: 20 de septiembre de 2016
*/

function seleccion(){

	var start = new Date().getTime();

	var v = [8,5,2,6,9,3,1,4,0,7];
	var tmp;
	var i;
	var j;
	var pos_min;
	var n = 10;

	for(i=0; i<=n-1; i++){
        pos_min=i;

        for(j=i+1; j<n; j++)
            if(v[j]<v[pos_min])
                pos_min=j;

        tmp=v[i];
        v[i]=v[pos_min];
        v[pos_min]=tmp;
    }

	var end = new Date().getTime();
	var time = end - start;
	alert('Tiempo de ejecucion: ' + time + " milisegundos");

}

seleccion();
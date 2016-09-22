/*
	Elaborado por: Manuel Vega y Jose Luis Alarez
	Fecha: 20 de septiembre de 2016
*/

function heapsort(){

	var start = new Date().getTime();

	var v = [8,5,2,6,9,3,1,4,0,7];
	var tmp;
	var i;
	var j;
	var k;
	var item;
	var n = 10;

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

	var end = new Date().getTime();
	var time = end - start;
	alert('Tiempo de ejecucion: ' + time + " milisegundos");

}

heapsort();
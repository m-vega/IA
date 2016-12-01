#!/usr/bin/python

def ruta(a11,a12,b21,b22,lista,caracter):	
	if (a11==b21):	#Si estan en el mismo renglon
		if (a12<b22): #Si la columna de inicio esta a la izquierda de la columna final
			lista[a11][a12]=caracter #Coloca el caracter en la posicion en donde estas
			ruta(a11,a12+1,b21,b22,lista,caracter)
		if (a12>b22): #Si la columna de inicio esta a la derecha de la columna final
			lista[a11][a12]=caracter #Coloca el caracter en la posicion en donde estas
			ruta(a11,a12-1,b21,b22,lista,caracter)
		else: #Si la columna de inicio esta en la misma posicion o a la derecha de la columna final
			lista[a11][a12]=caracter #Coloca el caracter en la posicion en donde estas
	elif (a11<b21):  #Si el renglon de inicio es menor al renglon final
		lista[a11][a12]=caracter #Coloca el caracter en la posicion en donde estas
		ruta(a11+1,a12,b21,b22,lista,caracter)
	elif (a11>b21): #Si el renglon de inicio es mayor al renglon final
		lista[a11][a12]=caracter #Coloca el caracter en la posicion en donde estas
		ruta(a11-1,a12,b21,b22,lista,caracter)
	return lista

lista=[]
renglones, columna = 10, 10

for x in range(renglones):
	columnas=[]
	for y in range(columna):
		columnas.append(" ")
	lista.append(columnas)	

print "Imprimiendo tablero"
for x in range(renglones):	#Por estetica, imprimimos las matrices por filas. 
	print lista[x]

numero_puntos = int(raw_input('Ingrese el numero de pares de coordenadas que utilizara:'))
i = 0

while i < numero_puntos :
	caracter = raw_input('Ingrese el caracter del par de puntos: ')
	A11 = int(raw_input('Ingrese el renglon de la primer coordenada: '))
	A12 = int(raw_input('Ingrese la columna de la primer coordenada: '))
	A21 = int(raw_input('Ingrese el renglon de la segunda coordenada: '))
	A22 = int(raw_input('Ingrese la columna de la segunda coordenada: '))

	print ""
	solucion=ruta(A11,A12,A21,A22,lista, caracter)	#Buscamos el Camino de A1 a A2
	print ""
	print "Generando una Ruta desde el punto " + caracter + "1(" + str(A11) + "," + str(A12) + ") a " + caracter + "2(" + str(A21) + "," + str(A22) +")"
	print ""
	print "Ruta encontrada"
	for x in range(renglones):	#Por estetica imprimimos el resultado de la ruta, por filas. 
		print solucion[x]
	i = i + 1
	if i is numero_puntos:
		break


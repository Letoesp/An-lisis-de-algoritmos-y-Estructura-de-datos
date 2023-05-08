//base semana 1
#include <stdio.h>
#include <stdlib.h>

//lee los elementos de un arreglo desde un archivo
int main(){
	FILE * archivo; //puntero a tipo FILE
	//modo lectura
	archivo =fopen("entrada_arreglo1.in","r");
	
	int cantmax, elemento,i;	
	cantmax=0;
	
	fscanf(archivo, "%d", &cantmax); 
	int arreglolab1[cantmax];
	printf("cantidad de elementos %d \n", cantmax);
	
	for(i=0;i<cantmax;i++){
		fscanf(archivo,"%d",&elemento);
		arreglolab1[i]=elemento;
	}
	fclose(archivo);
	
	//muestra los elementos del arreglo	
	for (i=0; i<cantmax; ++i)
		printf("%d\t",arreglolab1[i]);
	printf("\n");

	//Ejercicio 1: muestre el valor del menor elemento de un arreglo
	//pseudocódigo
	//implementación
	
	//Ejercicio 2: mostrar el valor de la suma de los elementos de un arreglo 
	//pseudocódigo
	//implementación
	
	//Ejercicio 3: retorne el valor del promedio de los elementos de un arreglo 
	//pseudocódigo
	//implementación
	
	//Ejercicio 4: retorne la cantidad de elementos de un arreglo que se encuentran en otro arreglo
	//pseudocódigo
	//implementación
	
	//Ejercicio 5: dadas dos matrices, cuadradas, calcular y retornar la suma de las matrices
	//pseudocódigo
	//implementación
	
	//Ejercicio 6: dadas dos matrices, cuadradas, calcular y retornar la multiplicación de las matrices
	//pseudocódigo
	//implementación
	
	return 0;
}
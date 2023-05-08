//base semana 1 version 2
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
	printf("cantidad de elementos %d \n", cantmax);

    int *ptrArreglolab1;

    ptrArreglolab1 = (int *)malloc(cantmax*sizeof(int));

    if (ptrArreglolab1==NULL)
        printf ("Error");

	for(i=0;i<cantmax;i++){
		fscanf(archivo,"%d",&elemento);
		ptrArreglolab1[i]=elemento;
	}
	
	fclose(archivo);

	//muestra los elementos del arreglo
    for(i = 0; i < cantmax; i++)
    {
		//dos formas de acceder a los elementos del arreglo	
        printf("\n %d",*(ptrArreglolab1+i));
        printf("\n %d",ptrArreglolab1[i]);
    }

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
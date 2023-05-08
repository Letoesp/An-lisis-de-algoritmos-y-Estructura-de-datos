#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numElem=0;

// Intercambia dos elementos de un arreglo.
// int* arr    Arreglo 
// int  indice1     Indice del primer elemento.
// int 	indice2     Indice del segundo elemento.
void swap(int *arr, int indice1, int indice2)
{
    int aux = arr[indice1];
    arr[indice1] = arr[indice2];
    arr[indice2] = aux;
}


/* pseudocódigo
Seleccionv2(arregloA)
	n←tamaño(arregloA)
	Para i←1 hasta n-1 paso -1  
		indiceMejor←i
		valorMejor←arregloA[i] 
		Para j←i+1 hasta n paso 1  
			Si arregloA[ j ]<valorMejor entonces
				indiceMejor← j
				valorMejor←arregloA[j] 
		Si indiceMejor<>i entonces
			intercambiar(arregloA,i,indiceMejor)
*/
// Algoritmo de Ordenamiento: selección.
// {int*} arr      Arreglo a ordenar.
// {int}  largo    Largo del arreglo.
void Ordenamiento_seleccion(int *arr, int largo)
{
    int indice_menor = 0;
	int valor_menor=0;
    for(int i = 0; i < largo-1; i++){
        //menor
		indice_menor=i;
		valor_menor=arr[i];
		for(int j = i+1; j < largo; j++){
            if(arr[j] < valor_menor){
                indice_menor = j;
				valor_menor=arr[j];
            }
        }
		//swap
        if(indice_menor != i){
            swap(arr, i, indice_menor);
        }
    }
}


int main(int argc, char* argv[]){
	FILE * archivo;
	int elemento;
	int i;
	char nombreArchivo[20];
	strcpy (nombreArchivo, argv[1]);

	//ACT 1a: lee archivo y lo retorna en un arreglo
	//ACT 1b: Imprimir elementos del arreglo desordenado
	
	//ACT 2a: Imprimir elementos del arreglo ordenado
	//ACT 2b: Calculo de moda
	//ACT 2c: imprimir moda.	
    
	//ACT 3: Calculo de partición maxima 
	//ACT 3: imprimir particiones
	
	//ACT 4: Implementar Burbuja/Quicksort
	//ACT 3: Imprimir elementos del arreglo ordenado
	
	
    //free(arreglo);

	return 0;
}	
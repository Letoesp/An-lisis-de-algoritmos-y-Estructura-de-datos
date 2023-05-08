#include <stdio.h>
#include <stdlib.h>
#include "TDAgrafo.h"


int main()
{
	TDAgrafo* grafo = leerGrafoNoDirigidoPonderado("GrafoMST.in");
		
	printf("Matriz de adyacencia:\n");
	imprimirMatrizAdyacencia(grafo);
	printf("----------\n");


	TDAprimResultado* primResultado = MSTPrim(grafo, 3);
	printf("Resultado Prim :\n"); //arreglo padre y distancias 
	printf("Resultado Prim Peso del MST: \n");
	liberarPrimResultado(primResultado);

	liberarGrafo(grafo);	
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "TDAgrafo.h"
//lab 10
//nombre:leonardo espinoza
//seccion: c-3

int main(int argc, char *argv[]) 
{
	TDAgrafo* grafo;
	grafo=leerGrafoNoDirigido(argv[1]);
	nodo* aux;
	
	if (grafo!=NULL){
		printf("Matriz de adyacencia: \n");
		imprimirMatrizAdyacencia(grafo);
		printf("----------\n");
	}
	
    int verticeEntrada = atoi(argv[2]);

    printf("Recorrido en anchura (vertice=%d):\n", verticeEntrada);
     RecorridoAnchura(grafo, verticeEntrada);
	 printf("----------\n");
    
	printf("Recorrido en profundidad(vertice=%d):\n", verticeEntrada);
	 RecorridoProfundidad(grafo,verticeEntrada);
	 printf("---------\n");
	    liberarGrafo(grafo);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "TDAgrafo.h"
//Nombre:leonardo espinoza
//Sección:C-3
//Semana 9

int main(int argc, char *argv[]) 
{
	TDAgrafo* grafo;
	nodo* aux;
	grafo=leerGrafoNoDirigido(argv[1]);
	
	if (grafo!=NULL){
		printf("Matriz de adyacencia: \n");
		imprimirMatrizAdyacencia(grafo);
		printf("----------\n");
	}
	
	//Actividad
	int vertice=atoi(argv[2]);	
	 TDAlista* lista=obtenerAdyacentes(grafo,vertice);
	 aux=lista->inicio;
	 printf("\n adyacentes de vertice %d : ",vertice);
	 while(aux!=NULL){
		 printf(" %d ",aux->dato);
		 aux=aux->puntero;
    }		

	//Actividad 1
	 printf("\n secuencia : ");
	 aux=lista->inicio;
	 while(aux!=NULL){
		 printf(" %d ",aux->dato);
		 aux=aux->puntero;
	 }
	
	 if (EsCamino(grafo, lista))
		 printf(" ES camino");
	 else
		 printf(" NO ES camino");

	//Actividad 2
	
	//Actividad 3
	
	//Actividad 4
	
	//Actividad 5
		
	free(grafo);
	//free(lista);
	return 0;
}




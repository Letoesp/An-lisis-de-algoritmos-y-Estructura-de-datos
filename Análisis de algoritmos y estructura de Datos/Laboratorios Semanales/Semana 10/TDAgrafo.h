#include <stdio.h>
#include <stdlib.h>
#include "TDAlista.h"
#include "TDAcola.h"
#include "TDApila.h"
//lab10
//nombre:leonardo espinoza
//sección c-3

/*------------- estructura de datos -------------*/

typedef struct matrizGrafo {
	int cvertices;
	int** adyacencias;
} TDAgrafo;


/*----------------- operaciones -----------------*/

TDAgrafo* crearGrafoVacio(int vertices)
{
	TDAgrafo* grafo = (TDAgrafo*)malloc(sizeof(TDAgrafo));
	grafo->cvertices = vertices;
	grafo->adyacencias = (int**)malloc(vertices * sizeof(int*));
	int i,j;

	for (i = 0; i < vertices; i++) {
		grafo->adyacencias[i] = (int*)malloc(vertices * sizeof(int));
		//Inicializa en cero
		for(j=0;j<vertices;j++){
			grafo->adyacencias[i][j] = 0;
		}
	}

	return grafo;
}

void imprimirMatrizAdyacencia(TDAgrafo* grafo)
{
	int i, j;

	for (i = 0; i < grafo->cvertices; i++) {
		for (j = 0; j < grafo->cvertices; j++) {
			printf("%d ", grafo->adyacencias[i][j]);
		}
		printf("\n");
	}
}

int adyacenciaNodos(TDAgrafo * grafo, int vertA, int vertB)
{
	if (grafo->adyacencias[vertA - 1][vertB - 1] == 1) {
		return 1;
	}
	return 0;
}


//NoDirigido NoPonderado
TDAgrafo* leerGrafoNoDirigido(char *nombreArchivo){
	//para abrir archivo
	FILE*pf;
	pf = fopen(nombreArchivo, "r");
	int n_vertices, m_aristas;
	int i, j, k;

	if (pf == NULL){
		printf("Error de archivo\n");
		return NULL;
	}
	else{
		//Cantidad de nodos y aristas
		fscanf(pf, "%d %d", &n_vertices, &m_aristas);
		TDAgrafo *G = crearGrafoVacio(n_vertices);

		//dependiendo de las lineas de archivo,
		// 1 para grafo no dirigido no ponderado
		for(k=0; k < m_aristas; ++k){
			fscanf(pf,"%d %d",&i, &j);
			G->adyacencias[i-1][j-1] = 1;
			G->adyacencias[j-1][i-1] = 1;
		}
		fclose(pf);

		return  G;
	}
}

/* Devuelve la lista de adyacencias un vertice dado.
 * Entrada(s)  {TDAgrafo*} grafo         Grafo a utilizar.
 * Entrada(s)  {int}       vertice       Vertice en el cual buscar las adyacencias.
 * Salida {TDAlista*}              Lista de adyacencias.*/
TDAlista* obtenerAdyacentes(TDAgrafo* grafo, int vertice)
{
	if(vertice > grafo->cvertices)
		return NULL;

	TDAlista *lista = crearListaVacia();

	for(int i = 0; i < grafo->cvertices; ++i){
		if(adyacenciaNodos(grafo, vertice, i+1)){
			insertarInicio(lista, i+1);
		}
	}

	return(lista);
}


/* Libera de la memoria un grafo dado.
 * Entrada(s)  {TDAgrafo*} grafo         Grafo a liberar.*/
void liberarGrafo(TDAgrafo* grafo)
{
	for(int i = 0; i < grafo->cvertices; ++i){
		free(grafo->adyacencias[i]);
	}
	free(grafo->adyacencias);
	free(grafo);
}

// Actividad 1 busqueda en Anchura
// RecorridoAnchura(grafo, vertice)
// Entrada: grafo, entero
// Salida: lista de recorrido (void)
// descripcion: esta funcion fue creada para recorrer en anchura un grafo

void RecorridoAnchura(TDAgrafo* grafo, int vertice){
	printf("\nBusqueda en anchura de %d:", vertice);
	int* array;
	int flag;
	array = (int*) malloc(grafo ->cvertices * sizeof(int));
	for(int i = 0; i < grafo->cvertices; i++){
		array[i] = 0;
	}
	TDAlista* lista;
	nodo* w;
	nodo* ptr = NULL;
	TDAcola* Q = crearColaVacia(3* grafo -> cvertices);
	array[vertice - 1] = 1;
	printf(" %d", vertice);
	encolar(Q, vertice);
	while(esColaVacia(Q) == 0){

		w = frente(Q);

		flag = w -> dato;
		desencolar(Q);

		lista = obtenerAdyacentes(grafo, flag);
		ptr = lista -> inicio;
		while(ptr != NULL){
			if(array[ptr -> dato -1] == 0){
				encolar(Q, ptr -> dato);
				array[(ptr->dato - 1)] = 1;
				printf(" %d", ptr -> dato);
			}
			ptr = ptr ->puntero;
		}
	}
}

//actividad 2:
//Entrada:grafo
//Salida: boolean
//Descripcion: verifica si un grafo es conexo o no(si posee camino entre todos sus vertices)
int esConexo( TDAgrafo *grafo){
	
}

//actividad 3:
//Entrada: grafo, entero
//salida: lista de recorrido(void)
//descripcion: esta funcion fue creada para recorrer profundidad de un grafo
void RecorridoProfundidad(TDAgrafo* grafo, int vertice){
	printf("\nBusqueda en profundidad de %d:", vertice);
	nodo* u;
	int* array;
	int flag;
	TDAlista* lista;
	nodo* ptr = NULL;
	array = (int*) malloc(grafo ->cvertices * sizeof(int));
	for(int i = 0; i < grafo->cvertices; i++){
		array[i] = 0;
	}
	TDApila* S = crearPilaVacia(3* grafo -> cvertices);
	apilar(S,vertice);
	while(esPilaVacia(S) == 0){
		u = tope(S);
		flag = u -> dato;
		desapilar(S);
		if(array[flag -1] == 0){  
			array[flag -1] = 1;
			printf(" %d ", flag);
			lista = obtenerAdyacentes(grafo, flag);
			ptr = lista -> inicio;
			while(ptr != NULL){
				if(array[ptr -> dato - 1] == 0){
					apilar(S, ptr -> dato);
				}
				ptr = ptr -> puntero;
			}
		}
	}
}



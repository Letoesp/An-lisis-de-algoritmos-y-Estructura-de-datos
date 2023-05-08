#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "TDAlista.h"


/*------------- estructura de datos -------------*/

typedef struct matrizGrafo 
{
	int cvertices;
	int** adyacencias;
}TDAgrafo;


/*----------------- operaciones -----------------*/

TDAgrafo* crearGrafoVacio(int vertices) 
{
	TDAgrafo* grafo = (TDAgrafo*)malloc(sizeof(TDAgrafo));
	grafo->cvertices = vertices;
	grafo->adyacencias = (int**)malloc(vertices * sizeof(int*));
	int i,j;
	for (i = 0; i < vertices; i++) 
	{
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
	
	for (i = 0; i < grafo->cvertices; i++) 
	{
		for (j = 0; j < grafo->cvertices; j++) 
		{
			printf("%d ", grafo->adyacencias[i][j]);
		}
		printf("\n");
	}
}

int adyacenciaNodos(TDAgrafo * grafo, int vertA, int vertB) 
{
	if (grafo->adyacencias[vertA - 1][vertB - 1] == 1) 
	{
		return 1;
	}
	return 0;
}

//NoDirigido NoPonderado
TDAgrafo* leerGrafoNoDirigido(char *nombreArchivo){
	FILE*pf;		   //para abrir archivo
	pf = fopen(nombreArchivo,"r");
	int n_vertices, m_aristas;
	int i,j,k;
	if (pf ==NULL){
		printf("Error de archivo\n");
		return NULL;
	}else{
		//Cantidad de nodos y aristas
		fscanf(pf, "%d %d", &n_vertices,&m_aristas); 		
		TDAgrafo *G=crearGrafoVacio(n_vertices);	
		//dependiendo de las lineas de archivo, 
		// 1 para grafo no dirigido no ponderado
		for(k=0;k<m_aristas;k++){
			fscanf(pf,"%d %d",&i, &j);
			G->adyacencias[i-1][j-1] = 1;
			G->adyacencias[j-1][i-1] = 1;
		}
		fclose(pf);
		return  G;	
	}
}

//Actividad 1

// obtenerAdyacentes(grafo, vertice)
// Entrada: grafo, entero
// salida: lista 
// descripcion: esta funcion devuelve una lista de adyacencias del vertice ingresado

TDAlista* obtenerAdyacentes(TDAgrafo* grafo, int vertice){

	TDAlista * adyacentes = crearListaVacia();

	for(int i = 0; i < grafo -> cvertices; ++i){
		if(adyacenciaNodos(grafo, vertice, i + 1)){
			insertarInicio(adyacentes, i + 1);
		}
	}
	return adyacentes;
}
//Actividad 1
// EsCamino(grafo, secuencia)
// Entrada: grafo, lista
// salida: booleano
// descripcion: esta funcion analiza si la secuencia es un camino del grafo o no
//Tenemos el primer nodo y el segundo, creamos un while comparando el primero con el segundo hasta el fin de
//la secuencia.
//
int EsCamino( TDAgrafo* grafo, TDAlista* secuencia ){
	if(!esListaVacia(secuencia)){
		nodo* primer = secuencia -> inicio;
		nodo* segundo = secuencia -> inicio->puntero;
    	while(segundo!=NULL){	
			if(adyacenciaNodos(grafo, primer -> dato, segundo -> dato) == 1){
				primer = primer -> puntero;
				segundo = segundo -> puntero;
			}else{				
				return 0;
			}
    	}
		return 1;
	}
}
//Actividad 2
int esCompleto(TDAgrafo* G);
//escompleto(grafo)
//entrada: grafo
//salida: booleano
//descripción: esta funcion analiza si el grafo ingresado es completo o no


//Actividad 3
int esComplemento(TDAgrafo* G1, TDAgrafo* G2);

//Actividad 5
int GradodeVertice(TDAgrafo* grafo, int vertice);
float GradoPromedio(TDAgrafo* grafo);
int EsRegular(TDAgrafo* grafo);

//Actividad 6
TDAgrafo* leerGrafoDirigidoPonderado(char *nombreArchivo);








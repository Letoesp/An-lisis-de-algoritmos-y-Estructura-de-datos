#include <stdio.h>
#include <stdlib.h>
#include "TDAlista.h"
#include "TDAlistaPrim.h"

#define INFINITO 123456789  //o podria ser un numero mayor a la suma de todas las aristas


/*------------- estructura de datos -------------*/

typedef struct matrizGrafo {
	int cvertices;
	int** adyacencias;
} TDAgrafo;

typedef struct tda_prim {
	int vertices;
	int verticeInicial;
	int *distancia;
	int *padre;
} TDAprimResultado;


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
			printf("%2d ", grafo->adyacencias[i][j]);
		}
		printf("\n");
	}
}

int adyacenciaNodos(TDAgrafo * grafo, int vertA, int vertB)
{
	return grafo->adyacencias[vertA - 1][vertB - 1];
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

/* Crea un grafo  dirigido ponderado a partir de datos de un archivo.
 * @param {char*} nombreArchivo     String que contiene el nombre del archivo.
 * @return {TDAgrafo*}              TDA del grafo. */
TDAgrafo* leerGrafoDirigidoPonderado(char *nombreArchivo){
	//para abrir archivo
	FILE*pf;
	pf = fopen(nombreArchivo, "r");
	int n_vertices, m_aristas;
	int i, j, k, p;
	if (pf == NULL){
		return NULL;
	}
	else{
		//Cantidad de nodos y aristas
		fscanf(pf, "%d %d", &n_vertices, &m_aristas);
		TDAgrafo *G = crearGrafoVacio(n_vertices);
		// 1 para grafo  dirigido no ponderado
		for(k=0; k < m_aristas; ++k){
			fscanf(pf,"%d %d %d",&i, &j, &p);
			G->adyacencias[i-1][j-1] = p;
		}
		fclose(pf);
		return  G;
	}
}

/* Devuelve la lista de adyacencias un vertice dado.
 * @param {TDAgrafo*} grafo         Grafo a utilizar.
 * @param {int}       vertice       Vertice en el cual buscar las adyacencias.
 * @return {TDAlista*}              Lista de adyacencias.*/
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
 * @param {TDAgrafo*} grafo         Grafo a liberar. */
void liberarGrafo(TDAgrafo* grafo)
{
	for(int i = 0; i < grafo->cvertices; ++i){
		free(grafo->adyacencias[i]);
	}
	free(grafo->adyacencias);
	free(grafo);
}

/* Algoritmo Prim. Obtiene MST para el grafo.
 * @param {TDAgrafo*} grafo         Grafo en el cual ejecutar Prim.
 * @param {int} vert_in             Vertice inicial para el algoritmo Prim.
 * @return {TDAprimResultado*}      Instancia de una estructura que contiene los resultados del algotirmo Prim.
 */
TDAprimResultado *MSTPrim(TDAgrafo *grafo, int vert_in)
{
	//Sugerencias 
	//usar estructura nueva TDAprimResultado para retornar todo lo necesario
	int n = grafo->cvertices;
	int i, v, u, d;
	TDAlistaPrim *listaPrim = crearListaPrimVacia();
	nodoPrim *auxNodo = NULL;
	nodo *nodoAux = NULL;
	TDAlista *auxLista;
	
	//usar estructura nueva TDAlistaPrim: lista con mas atributos, especiales para PRIM
	TDAprimResultado *prim = (TDAprimResultado*)malloc(sizeof(TDAprimResultado));
	prim->vertices = n;
	prim->verticeInicial = vert_in;
	prim->distancia = (int*)malloc(n * sizeof(int));
	prim->padre = (int*)malloc(n * sizeof(int));
}



//Función que retorna 0 si no existen vertices sin visitar
//En caso contrario, retorna 1
int SinVisitar(int* visitados, int largo)
{
	int i;
	for(i = 0; i < largo; i++)
	{
		if(visitados[i] == 0)
		{
			return 1;
		}
	}
	return 0;
}

//Función que retorna la posición del elemento que posea la minima distancia desde el vertice inicial, 
//que no haya sido visto.
int extraerMinimo(int* distancia, int* visitado, int n)
{
	int minimo = 9999;
	int indice = -1;
	int i;
	for(i = 0; i < n; i++)
	{
		if((distancia[i] < minimo) && (visitado[i] != 1))
		{
			minimo = distancia[i];
			indice = i;
		}
	}
	return indice + 1;
}

//Función que permite calcular la energia gastada al ingresar el mapa representado como grafo.
//Esta función contiene el algoritmo de dijkstra para resolver el problema.
int* Energiagastada(TDAgrafo* grafo, int inicio,int energia)
{
	int u;
	int w;
	int n = grafo -> cvertices;
    nodo* ptr;
	TDAlista* adyacentes;
//Se le asigna memoria al arreglo de antecesores igual a n+1
//Ya que el resultado se guardará en la ultima posición del arreglo.
	int* antecesor = (int*)malloc(sizeof(int)*(n + 1));
//Se les asigna memoria igual a n. 
	int* distancia = (int*)malloc(sizeof(int)*n);
	int* visitado = (int*)malloc(sizeof(int)*n);
	int i;
	for(i = 0; i < n; i++)
	{
		antecesor[i] = -1;
		visitado[i] = 0;
		if(grafo -> adyacencias[inicio - 1][i] > 0)
		{
			distancia[i] = grafo -> adyacencias[inicio - 1][i];
			antecesor[i] = inicio;
		}
		else
		{
			distancia[i] = 9999; 
		}
	}
	antecesor[inicio - 1] = 0;
	distancia[inicio - 1] = 0;
	visitado[inicio - 1] = 1;
	while(SinVisitar(visitado, n))
	{
		u = extraerMinimo(distancia, visitado, n); 
		visitado[u - 1] = 1;
		adyacentes = obtenerAdyacentes(grafo, u);
		ptr = adyacentes -> inicio;
		
		while(ptr != NULL)
		{
			w = ptr -> dato;
			if(distancia[w - 1] > distancia[u - 1] + grafo -> adyacencias[u - 1][w - 1])
			{
				distancia[w - 1] = distancia[u - 1] + grafo -> adyacencias[u - 1][w - 1];
				antecesor[w - 1] = u;
			}
			ptr = ptr -> siguiente;
		}
	}


//Se crea una variable que será el antecesor del ultimo vertice a recorrer
//Esta es la distancia real
	int distanciareal = antecesor[n-1]; 
//Se obtiene el costo real de energía, restando en 1 la distancia real.
	distanciareal = distancia[distanciareal - 1];
	antecesor[n] = distanciareal;
//Se calcula la energia restante restando la energía inicial con la distancia real.
   int Energiarestante= energia - distanciareal;
   printf("la energia restante es\n");
   printf("%d",Energiarestante);
//Impresión de arreglos de antecesores y distancias de dijkstra, se deja en comentarios
	/* 
	printf("\nAntecesores: \n");
	for(i = 0; i < n; i++)
	{
		printf("%d ", antecesor[i]);
	}
	printf("\nDistancias: \n");
	for(i = 0; i < n; i++)
	{
		printf("%d ", distancia[i]);
	}
	*/
	return antecesor;
}
//Función pequeña que calcula la cantidad de vertices de un grafo.
int vertices(TDAgrafo* grafo){
int n = grafo -> cvertices;

return n;
}

//Función que devuelve la ruta empleada por el mapa recibido.
int* rutarecorrida(int* antecesores, int vertices)
{
//Tenemos la ultima posición del camino
	int antecesor = antecesores[vertices - 1];
//Contador de niveles, parte de 0 y va aumentando.
	int niveles = 0;
	//Se recorre el camino.
	while (antecesor != 1)
	{
//Se suma la cantidad de niveles y se obtiene el siguiente antecesor
		niveles += 1;
		antecesor = antecesores[antecesor - 1]; 
	}
int* ruta = (int*)malloc(sizeof(int)*(niveles));

//Se reinicia valor del antecesor y se crea auxiliar para los niveles
	antecesor = antecesores[vertices - 1];
	int i = niveles;
//Ciclo while que recorre los niveles y va asignando la ruta recorrida.
	while (antecesor != 1)
	{
		ruta[i - 1] = antecesor;
		i -= 1;
		antecesor = antecesores[antecesor - 1];
	}
	
	//Se imprime la ruta recorrida
	printf("\nLa ruta recorrida es: \n");
	for(i = 0; i < niveles; i++)
	{
		printf("%d ", ruta[i]);
	}

	return ruta;
}
/* Libera de la memoria una instancia del la estructura que contiene
 * los resultados del algoritmo Prim.
 * @param {TDAprimResultado*} prim         Instancia de una estructura que contiene los resultados del algoritmo Prim.
 */
void liberarPrimResultado(TDAprimResultado *prim)
{
	free(prim->distancia);
	free(prim->padre);
	free(prim);
}


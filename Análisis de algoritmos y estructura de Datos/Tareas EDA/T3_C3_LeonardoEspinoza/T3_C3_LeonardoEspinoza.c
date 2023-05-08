//Tarea 3 EDA
//Nombre: Leonardo Espinoza
//Sección: C-3
//Entrada:
// Formato de entrada similar al laboratorio modelando el grafo
//Ejecución: por linea de comando se debe ingresar nombre archivo de entrada y unidad de energia iniciales
//Salida: Cantidad de energia gastada y ruta recorrida.
#include <stdio.h>
#include <stdlib.h>
#include "TDAgrafo.h"

/////////////////////////////////////////////////////////
int main(int argc, char *argv[]){
if (argc != 3)
    return 1;
//se saca la energía.
int energia;
energia= atoi(argv[2]);
printf("la energia ingresada es \n");
printf("%d\n",energia);
TDAgrafo* grafo = leerGrafoDirigidoPonderado(argv[1]);		
//printf("Matriz de adyacencia:\n");
//imprimirMatrizAdyacencia(grafo);
//printf("----------\n");
//Se aplica algoritmo de dijkstra haciendo llamado a la función Energia gastada
int* lista=Energiagastada(grafo,1,energia);
//Se aplica la función ruta que calcula la ruta recorrida por el algoritmo en el mapa.
rutarecorrida(lista,vertices(grafo));

liberarGrafo(grafo);	
return 0;
}
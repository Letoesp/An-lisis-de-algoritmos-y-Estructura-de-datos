#include <stdio.h>
#include <stdlib.h>

/*------------- estructura de datos -------------*/

typedef struct nodoGenerico
{
  char *dato;
  struct nodoGenerico* puntero;
}nodo;

typedef struct listaGenerica
{
  nodo* inicio;
}TDAlista;


/*------------- operaciones -------------*/

TDAlista* crearListaVacia()
{
  TDAlista* lista=(TDAlista*)malloc(sizeof(TDAlista));
  lista->inicio=NULL;
  return lista;
}

int esListaVacia(TDAlista* lista)
{
  if (lista->inicio == NULL)
    return 1;
  else
    return 0;
}

void recorrerLista(TDAlista* lista)
{
  if (!esListaVacia(lista))
  {
    nodo* auxiliar=lista->inicio;
    while (auxiliar!=NULL)
    {
      printf("%s ",auxiliar->dato);
      auxiliar=auxiliar->puntero;
    }
    printf("\n");
  }
  else
    printf("La lista está vacía\n");
}

void insertarInicio(TDAlista* lista, char* dato)
{
  nodo* nuevo=(nodo*)malloc(sizeof(nodo));
  nuevo->dato=dato;
  nuevo->dato=malloc(strlen(dato)+1);
  strcpy(nuevo->dato,dato);
  nuevo->puntero = lista->inicio;
  lista->inicio=nuevo;
}

void eliminarInicio(TDAlista* lista)
{
  nodo* auxiliar;
  if(!esListaVacia(lista))
  {
    auxiliar=lista->inicio;
    lista->inicio=lista->inicio->puntero;
    free(auxiliar);
  }
}


/*------------- Actividad 2 -------------*/
void liberarLista(TDAlista* lista){
 while(!esListaVacia(lista)){
  eliminarInicio(lista);
 }
}

int obtenerNumeroNodos(TDAlista* lista)
{int acum=0;
  if (!esListaVacia(lista))
  {
    nodo* auxiliar=lista->inicio;
    while (auxiliar!=NULL)
    {
      //printf("%s ",auxiliar->dato);
      acum=acum+1;
      auxiliar=auxiliar->puntero;
    }
    //printf("\n");
    //printf("el numero de nodos es: ");
    //printf("%d",acum);
    return acum;
  }
  else
    printf("La lista está vacía\n");
}


/*------------- Actividad 3 -------------*/
void insertarNodoFinal(TDAlista* lista, char* dato){
  nodo*auxiliar=lista->inicio;
  while(auxiliar->puntero !=NULL){
    auxiliar=auxiliar->puntero;//se recorre la lista hasta el final
  }
  nodo*nuevo=(nodo*)malloc(sizeof(nodo));
  nuevo->dato=dato;
  nuevo->dato=malloc(strlen(dato)+1);
  strcpy(nuevo->dato,dato);
  nuevo->puntero=NULL;
  auxiliar->puntero=nuevo;


}

void insertarNodoDespues(TDAlista* lista, char dato, int datoAnterior);
void eliminarFinal(TDAlista* lista);
void eliminarDato(TDAlista* lista, char dato);
nodo* obtenerNodo(TDAlista* lista, char posicion);





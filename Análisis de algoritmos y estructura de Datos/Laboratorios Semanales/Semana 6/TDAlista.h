#include <stdio.h>
#include <stdlib.h>
//nombre: Leonardo Espinoza
//Sección C-3
/*------------- estructura de datos -------------*/

typedef struct nodoGenerico
{
  int dato;
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
      printf("%d ",auxiliar->dato);
      auxiliar=auxiliar->puntero;
    }
    printf("\n");
  }
  else
    printf("La lista está vacía\n");
}

void insertarInicio(TDAlista* lista, int dato)
{
  nodo* nuevo=(nodo*)malloc(sizeof(nodo));
  nuevo->dato=dato;
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
/*------------- Actividad 3 -------------*/
int buscarDato(TDAlista* lista, int dato){
  if (!esListaVacia(lista))
  {
    nodo* auxiliar=lista->inicio;
    while (auxiliar!=NULL)
    {
      if(dato=auxiliar->dato)
        return 1;

      auxiliar=auxiliar->puntero;
    }
    printf("\n");
    return 0;
  }
  else
    printf("La lista está vacía\n");
}
/*------------- Actividad 4 -------------*/
int obtenerNumeroNodos(TDAlista* lista)
{int acum=0;
  if (!esListaVacia(lista))
  {
    nodo* auxiliar=lista->inicio;
    while (auxiliar!=NULL)
    {
      printf("%d ",auxiliar->dato);
      acum=acum+1;
      auxiliar=auxiliar->puntero;
    }
    printf("\n");
    printf("el numero de nodos es: ");
    printf("%d",acum);
  }
  else
    printf("La lista está vacía\n");
}

/*------------- Actividad 5 -------------*/
void insertarNodoFinal(TDAlista* lista, int dato);
void insertarNodoDespues(TDAlista* lista, int dato, int datoAnterior);
void eliminarFinal(TDAlista* lista);
void eliminarDato(TDAlista* lista, int dato);
nodo* obtenerNodo(TDAlista* lista, int posicion);

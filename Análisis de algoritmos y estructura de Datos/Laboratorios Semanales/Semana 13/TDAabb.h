#include <stdio.h>
#include <stdlib.h>

/*--------------- estructura de datos -----------------*/

typedef struct nodoABB
{
  int dato;
  struct nodoABB* padre;
  struct nodoABB* hijoIzquierdo;
  struct nodoABB* hijoDerecho;
}nodoABB;

typedef struct 
{
  nodoABB* inicio;
}TDAabb;


typedef struct nodoAB
{
  int dato;
  struct nodoAB* padre;
  struct nodoAB* hijoIzquierdo;
  struct nodoAB* hijoDerecho;
}nodoArbolBinario;

typedef struct 
{
  nodoArbolBinario* inicio;
}TDAarbolBinario;

/*--------------- operaciones de creación -----------------*/

TDAabb* crearABBVacio()
{
  TDAabb* abb=(TDAabb*)malloc(sizeof(TDAabb));
  abb->inicio=NULL;
  return abb;
}

int esABBvacio(TDAabb* abb)
{
  if (abb->inicio == NULL)
    return 1;
  else
    return 0;
}

/*--------------- operaciones de posicion -----------------*/

//devuelve NULO si el árbol está vacío
nodoABB* raizABB(TDAabb* arbol)
{
  if (arbol!=NULL)
    return arbol->inicio;
  return NULL;
}

nodoABB* padreNodoABB(TDAabb* arbol, nodoABB* nodo)
{
  if (nodo!=NULL)
    return nodo->padre;
}

int esHojaABB(TDAabb* arbol, nodoABB* nodo)
{
  if (!esABBvacio(arbol))
  {
    if ((nodo->hijoIzquierdo==NULL)&&(nodo->hijoDerecho==NULL))
      return 1;
  }
  return 0;
}

/*--------------- operaciones auxiliares -----------------*/

nodoABB* buscarMenorABB(TDAabb* arbol, nodoABB* nodo)
{
  nodoABB* aux;
  if (!esABBvacio(arbol))
  {
    aux=nodo;
    while (aux!=NULL)
    {
      if (aux->hijoIzquierdo!=NULL)
      {
        aux=aux->hijoIzquierdo;
      }
      else //aux es nodo que contiene dato
      {
        return aux;
      }
    }
  }
  return NULL;
}

/*--------------- operaciones de actualización -----------------*/

void insertarRaizABB(TDAabb* arbol, int dato)
{
  nodoABB* raiz=(nodoABB*)malloc(sizeof(nodoABB));
  raiz->dato=dato;
  raiz->hijoIzquierdo=NULL;
  raiz->hijoDerecho=NULL;
  raiz->padre=NULL;
  arbol->inicio=raiz;
}

void insertarNodoRecursivoABB(nodoABB* nodo, int dato)
{
  nodoABB* nuevo;

  nuevo=(nodoABB*)malloc(sizeof(nodoABB));
  nuevo->dato=dato;
  nuevo->hijoIzquierdo=NULL;
  nuevo->hijoDerecho=NULL;

  if (dato <= nodo->dato)  //vamos por la izquierda
  {
    if (nodo->hijoIzquierdo==NULL) // no hay un hijo a la izquierda
    {
      nodo->hijoIzquierdo=nuevo;
      nuevo->padre=nodo;
    }
    else  //si ya hay un hijo a la izquierda
    {
      insertarNodoRecursivoABB(nodo->hijoIzquierdo,dato);
    }
  }
  else //vamos por la derecha
  {
    if (nodo->hijoDerecho==NULL) // no hay un hijo a la izquierda
    {
      nodo->hijoDerecho=nuevo;
      nuevo->padre=nodo;
    }
    else  //si ya hay un hijo a la izquierda
    {
      insertarNodoRecursivoABB(nodo->hijoDerecho,dato);
    }
  }
}

void insertarNodoABB(TDAabb* arbol, int dato)
{
  if (!esABBvacio(arbol))
  {
    insertarNodoRecursivoABB(arbol->inicio,dato);
  }
  else
    insertarRaizABB(arbol,dato);
}
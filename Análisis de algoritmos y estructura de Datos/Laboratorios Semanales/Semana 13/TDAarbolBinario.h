#include <stdio.h>
#include <stdlib.h>

/*--------------- estructura de datos -----------------*/

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

TDAarbolBinario* crearArbolBinarioVacio()
{
  TDAarbolBinario* arbolBinario=(TDAarbolBinario*)malloc(sizeof(TDAarbolBinario));
  arbolBinario->inicio=NULL;
  return arbolBinario;
}

int esArbolBinarioVacio(TDAarbolBinario* arbolBinario)
{
  if (arbolBinario->inicio == NULL)
    return 1;
  else
    return 0;
}

/*--------------- operaciones de posicion -----------------*/

//devuelve NULO si el árbol está vacío
nodoArbolBinario* raizAB(TDAarbolBinario* arbol)
{
  if (arbol!=NULL)
    return arbol->inicio;
  return NULL;
}

// devuelve NULO si nodo no existe
nodoArbolBinario* padreNodoAB(TDAarbolBinario* arbol, nodoArbolBinario* nodo)
{
  if (nodo!=NULL)
    return nodo->padre;
}


int esHojaAB(nodoArbolBinario* nodo)
{
  if ((nodo->hijoIzquierdo==NULL)&&(nodo->hijoDerecho==NULL))
    return 1;
  return 0;
}

/*--------------- operaciones de búsqueda -----------------*/

nodoArbolBinario* buscarNodoRecursivoAB(nodoArbolBinario* nodo, int dato)
{
  nodoArbolBinario* aux;
  if (nodo!=NULL)
  {
    if (nodo->dato==dato)
      return nodo;
    else
    {
      aux=buscarNodoRecursivoAB(nodo->hijoIzquierdo,dato);
      if (aux!=NULL)
        return aux;
      return buscarNodoRecursivoAB(nodo->hijoDerecho,dato);
    }
  }
}

nodoArbolBinario* buscarNodoAB(TDAarbolBinario* arbol, int dato)
{
  nodoArbolBinario* aux;
  if (!esArbolBinarioVacio(arbol))
  {
    aux=arbol->inicio;
    return buscarNodoRecursivoAB(aux,dato);
  }
  else
    return NULL;
}

/*--------------- operaciones de actualización -----------------*/

void insertarRaizAB(TDAarbolBinario* arbol, int dato)
{
  nodoArbolBinario* raiz=(nodoArbolBinario*)malloc(sizeof(nodoArbolBinario));
  raiz->dato=dato;
  raiz->hijoIzquierdo=NULL;
  raiz->hijoDerecho=NULL;
  raiz->padre=NULL;
  arbol->inicio=raiz;
}

// tipoHijo={0 (izquierdo), 1 (derecho)}
void insertarNodoAB(TDAarbolBinario* arbol, int padre, int dato, int tipoHijo)
{
  nodoArbolBinario* nodoPadre;
  nodoArbolBinario* nuevo;

  if (!esArbolBinarioVacio(arbol))
  {
    //si existe nodoPadre
    nodoPadre=buscarNodoAB(arbol,padre);
    if (nodoPadre!=NULL)
    {
      if (tipoHijo==0)  //hijo izquierdo
      {
        if (nodoPadre->hijoIzquierdo==NULL) //está desocupado
        {
          nuevo=(nodoArbolBinario*)malloc(sizeof(nodoArbolBinario));
          nuevo->dato=dato;
          nuevo->hijoIzquierdo=NULL;
          nuevo->hijoDerecho=NULL;
          nuevo->padre=nodoPadre;
          nodoPadre->hijoIzquierdo=nuevo;
        }
        else
          printf("no se puede insertar %d como hijo izquierdo\n",dato);
      }
      else if (tipoHijo==1)  //hijo derecho
      {
        if (nodoPadre->hijoDerecho==NULL) //está desocupado
        {
          nuevo=(nodoArbolBinario*)malloc(sizeof(nodoArbolBinario));
          nuevo->dato=dato;
          nuevo->hijoIzquierdo=NULL;
          nuevo->hijoDerecho=NULL;
          nuevo->padre=nodoPadre;
          nodoPadre->hijoDerecho=nuevo;
        }
        else
          printf("no se puede insertar %d como hijo derecho\n",dato);
      }
      else
        printf("tipo de hijo incorrecto\n");
    }
    else
      printf("no existe nodo padre\n");
  }
  else
    insertarRaizAB(arbol,dato);
}
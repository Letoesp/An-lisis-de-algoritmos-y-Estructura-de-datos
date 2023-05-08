#include <stdio.h>
#include <stdlib.h>

/*--------------- estructura de datos -----------------*/

typedef struct Item
{ 
  char nombre;
  int tipo;
  struct Item* padre;
  struct Item* hijo;
}itemTreeSO;

typedef struct 
{
  itemTreeSO* inicio;
}TreeSO;

/*--------------- operaciones de creación -----------------*/

TreeSO* crearArbolBinarioVacio()
{
  TreeSO* arbolBinario=(TreeSO*)malloc(sizeof(TreeSO));
  arbolBinario->inicio=NULL;
  return arbolBinario;
}

int esArbolBinarioVacio(TreeSO* arbolBinario)
{
  if (arbolBinario->inicio == NULL)
    return 1;
  else
    return 0;
}

/*--------------- operaciones de posicion -----------------*/

//devuelve NULO si el árbol está vacío
itemTreeSO* raizAB(TreeSO* arbol)
{
  if (arbol!=NULL)
    return arbol->inicio;
  return NULL;
}

// devuelve NULO si nodo no existe
itemTreeSO* padreNodoAB(TreeSO* arbol, itemTreeSO* nodo)
{
  if (nodo!=NULL)
    return nodo->padre;
}


int esHojaAB(itemTreeSO* nodo)
{
  if ((nodo->hijo==NULL)&&(nodo->hijo==NULL))
    return 1;
  return 0;
}

/*--------------- operaciones de búsqueda -----------------*/

itemTreeSO* buscarNodoRecursivoAB(itemTreeSO* nodo, char nombre)
{
  itemTreeSO* aux;
  if (nodo!=NULL)
  {
    if (nodo->nombre==nombre)
      return nodo;
    else
    {
      aux=buscarNodoRecursivoAB(nodo->hijo,nombre);
      if (aux!=NULL)
        return aux;
      return buscarNodoRecursivoAB(nodo->hijo,nombre);
    }
  }
}

itemTreeSO* buscarNodoAB(TreeSO* arbol, int dato)
{
  itemTreeSO* aux;
  if (!esArbolBinarioVacio(arbol))
  {
    aux=arbol->inicio;
    return buscarNodoRecursivoAB(aux,dato);
  }
  else
    return NULL;
}

/*--------------- operaciones -----------------*/
itemTreeSO* cd(TreeSO* arbol, itemTreeSO* item,char nombre){
    itemTreeSO* aux;
  if (!esArbolBinarioVacio(arbol))
  {
    aux=arbol->inicio;
      if (item!=NULL)
  {
    if (item->nombre==nombre)
      return item;
  }
  else
    return NULL;
}
}
void ls();
void mkdir();
void mkfile();
void rm();
void tree();
void find();
void exit();

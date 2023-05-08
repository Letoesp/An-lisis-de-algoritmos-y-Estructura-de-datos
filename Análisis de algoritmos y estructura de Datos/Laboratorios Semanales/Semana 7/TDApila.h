#include <stdio.h>
#include <stdlib.h>
//nombre: Leonardo Espinoza
//Seccion C3
/*------------- estructura de datos -------------*/

typedef struct nodoGenerico
{
   int dato;
   struct nodoGenerico* puntero;
}nodo;

typedef struct
{
  int capacidad;
  int size;
  nodo* tope;
}TDApila;

/*------------- operaciones -------------*/

TDApila* crearPilaVacia(int capacidad)
{
  TDApila* pila=(TDApila*)malloc(sizeof(TDApila));
  pila->capacidad=capacidad;
  pila->size=0;
  pila->tope=NULL;
  return pila;
}

int esPilaVacia(TDApila* pila)
{
  if (pila->size == 0)
    return 1;
  else
    return 0;
}

nodo* tope(TDApila* pila)
{
  return pila->tope;
}


/*------------- Actividad 2 -------------*/
void apilar(TDApila* pila, int dato){
 nodo* nuevo=(nodo*)malloc(sizeof(nodo));
  nuevo->dato=dato;
  nuevo->puntero = pila->tope;
  pila->tope=nuevo;
  pila->size=pila->size+1;
}
void desapilar(TDApila* pila)
{
  nodo* auxiliar;
  if(!esPilaVacia(pila))
  {
    auxiliar=pila->tope;
    pila->tope=pila->tope->puntero;
    pila->size=pila->size-1;
    free(auxiliar);
  }
}

/*------------- Actividad 3 -------------*/
//crear como variable global el largo de la secuencia que será un arreglo
// secuencia es arreglo
// se va a realizar la reversa secuencia con 859362
//el resultado debe ser 263958





void reversaSecuencia(int* secuencia);
/*
int largo= 6;
pila=crearPilaVacia(largo);
for (i=0, largo)
  apilar(pila,secuencia(i))
for (i=0,largo)
  aux=(tope(pila))-> dato
  escribir(aux)
  desapilar(pila)
*/
//me da errores en la creación de la función con las constantes, pero aún así escribiré 
//el pseudocódigo de la idea del desarrollo de este. 
/*------------- Actividad 4 -------------*/

int esPalindroma(int* secuencia);

//12321

//24 42


//2442

//pila aux = 42
//pila main = 42



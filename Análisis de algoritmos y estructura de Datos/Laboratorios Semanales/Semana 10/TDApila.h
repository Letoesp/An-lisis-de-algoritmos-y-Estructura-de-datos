#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int capacidad;
	int size;
	nodo* tope;
} TDApila;


/*------------- Operaciones -------------*/

TDApila* crearPilaVacia(int capacidad)
{
	TDApila* pila = (TDApila*)malloc(sizeof(TDApila));
	pila->capacidad = capacidad;
	pila->size = 0;
	pila->tope = NULL;
	return pila;
}

int esPilaVacia(TDApila* pila)
{
	if (pila->size == 0)
		return 1;
	return 0;
}


/* Agrega un elemento a la pila.
 * @param {TDApila} pila       Pila en la que agregar el elemento.
 * @param {int}     dato       Dato que debe contener el nodo.
 * @return {int}               Retorna 0 o 1 dependiendo de si pudo apilar el elemento.
 */
void apilar(TDApila* pila, int dato)
{
	if(pila->size < pila->capacidad){
		nodo* nuevoNodo = (nodo*)malloc(sizeof(nodo));
		nuevoNodo->dato = dato;
		nuevoNodo->puntero = pila->tope;
		pila->tope = nuevoNodo;
		pila->size += 1;
	}
}

/* Quita el elemento tope de la pila.
 * @param {TDApila} pila       Pila en la que quitar el elemento.
 */
void desapilar(TDApila* pila)
{
	if(!esPilaVacia(pila)){
		nodo* tope = pila->tope;
		pila->tope = pila->tope->puntero;
		pila->size -= 1;
		free(tope);
	}
}

/* Retorna el nodo tope de la pila.
 * @param {TDApila} pila       Pila a revisar.
 * @return {nodo*}             La instancia del nodo tope actual.
 */
nodo* tope(TDApila* pila)
{
	return pila->tope;
}

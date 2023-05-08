#include <stdio.h>
#include <stdlib.h>

/*------------- Estructura de Datos -------------*/

typedef struct nodoPrimGenerico {
	int vertice;
	int peso;
	struct nodoPrimGenerico *siguiente;
} nodoPrim;

typedef struct {
	nodoPrim* inicio;
} TDAlistaPrim;


/*------------- Operaciones -------------*/

/* Crea una nueva instancia de la estructura nodo.
 * @param {int} vertice         Vertice inicial.
 * @param {int} peso            Peso asociado al vertice.
 * @return {nodoPrim*}          Instancia del nuevo nodo.
 */
nodoPrim* crearNodoPrim(int vertice, int peso)
{
	nodoPrim* nuevo = (nodoPrim*)malloc(sizeof(nodoPrim));
	nuevo->vertice = vertice;
	nuevo->peso = peso;
	nuevo->siguiente = NULL;
	return nuevo;
}

TDAlistaPrim* crearListaPrimVacia()
{
	TDAlistaPrim* lista=(TDAlistaPrim*)malloc(sizeof(TDAlistaPrim));
	lista->inicio=NULL;
	return lista;
}

int esListaPrimVacia(TDAlistaPrim* lista)
{
	if (lista->inicio == NULL)
		return 1;
	else
		return 0;
}

void eliminarInicioPrim(TDAlistaPrim* lista)
{
	nodoPrim* auxiliar;
	if(!esListaPrimVacia(lista))
	{
		auxiliar=lista->inicio;
		lista->inicio=lista->inicio->siguiente;
		free(auxiliar);
	}
}


/* Libera de la memoria los struct de lista y los nodos.
 * @param {TDAlistaPrim} lista      Lista a liberar. */
void liberarListaPrim(TDAlistaPrim* lista)
{
	while(!esListaPrimVacia(lista)){
		eliminarInicioPrim(lista);
	}
	free(lista);
}

/* Inserta un nuevo dato en la lista.
 * @param {TDAlistaPrim} lista      Lista en la cual insertar el dato.
 * @param {int} vertice             Numero o indentificador del vertice.
 * @param {int} distancia           Distancia asociada al vertice. */
void insertarListaPrim(TDAlistaPrim *lista, int vertice, int distancia)
{
	nodoPrim* nuevo = crearNodoPrim(vertice, distancia);
	nuevo->siguiente = lista->inicio;
	lista->inicio = nuevo;
}

/* Actualiza la distancia asociada al vertice.
 * @param {TDAlistaPrim} lista      Lista en la actualizar el dato.
 * @param {int} vertice             Numero o indentificador del vertice.
 * @param {int} nuevaDistancia      Nueva distancia asociada al vertice.*/
void actualizarListaPrim(TDAlistaPrim *lista, int vertice, int nuevaDistancia)
{
    nodoPrim *aux;
    for(aux = lista->inicio; aux != NULL; aux = aux->siguiente){
        if(aux->vertice == vertice){
            aux->peso = nuevaDistancia;
            break;
        }
    }
}

/* Verifica si un vertice dado se encuentra en la lista.
 * @param {TDAlistaPrim} lista      Lista en la cual buscar el vertice.
 * @param {int} vertice             Numero o indentificador del vertice a buscar.
 * @return {int}                    Retorna 0 o 1 dependiendo de si encontro el vertice en la lista.*/
int estaEnLista(TDAlistaPrim *lista, int vertice)
{
    if(esListaPrimVacia(lista)) return 0;

    nodoPrim *aux;
    for(aux = lista->inicio; aux != NULL; aux = aux->siguiente){
        if(aux->vertice == vertice){
            return 1;
        }
    }
    return 0;
}

/* Extrae de la lista el vertice con distancia minima.
 * @param {TDAlistaPrim} lista      Lista en la cual buscar el vertice.
 * @return {nodoPrim*}              Nodo con distancia minima.*/
nodoPrim *extraerMinimoPrim(TDAlistaPrim *lista)
{
    if(esListaPrimVacia(lista)) return NULL;
    // Obtener minimo
    nodoPrim *aux;
    nodoPrim *minimo = lista->inicio;
    for(aux = lista->inicio; aux != NULL; aux = aux->siguiente){
        if(aux->peso < minimo->peso){
            minimo = aux;
        }
    }

    // Quitar minimo de la lista
    if(lista->inicio == minimo){
        lista->inicio = lista->inicio->siguiente;
    }
    else{
        nodoPrim *aux1 = lista->inicio;
        nodoPrim *aux2 = aux1->siguiente;
        
        while(aux2 != NULL && aux2 != minimo){
            aux1 = aux2;
            aux2 = aux2->siguiente;
        }

        aux1->siguiente = aux2->siguiente;
        aux2->siguiente = NULL;
    }
    return minimo;
}

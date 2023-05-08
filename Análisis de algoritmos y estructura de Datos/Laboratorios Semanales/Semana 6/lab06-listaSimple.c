#include <stdio.h>
#include <stdlib.h>
#include "TDAlista.h"

int main()
{
  TDAlista* lista=crearListaVacia();
  recorrerLista(lista);

  ///////////////Actividad 3 ////////////////////7
insertarInicio(lista,20);
insertarInicio(lista,13);
insertarInicio(lista,6);
insertarInicio(lista,32);
insertarInicio(lista,11);
insertarInicio(lista,9);
recorrerLista(lista);
buscarDato(lista,6);

printf("%d",buscarDato(lista,6));
printf("\n");


printf("%d",buscarDato(lista,14));
printf("\n");
//actividad 4////////

obtenerNumeroNodos(lista);

  return 0;
}
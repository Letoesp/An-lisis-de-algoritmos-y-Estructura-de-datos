#include <stdio.h>
#include <stdlib.h>
#include "TDApila.h"

int main()
{
  TDApila* pila;

//actividad 1//
pila=crearPilaVacia(8);
if (esPilaVacia(pila)==1)
  printf("la pila esta vacia");
//actividad 3
//859362
int largo=6;
int*secuencia=(int*) malloc(sizeof(int)*largo);
secuencia[0]=8;
secuencia[1]=5;
secuencia[2]=9;
secuencia[3]=3;
secuencia[4]=6;
secuencia[5]=2;

  return 0;
}

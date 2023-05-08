#include <stdio.h>
//nombre: Leonardo Espinoza
//Sección: C3
//////////////////////////////////////////////////
//Actividad 4// Actividad que se entrega/////

void actividad4_referencia(long x, long y){
int *a;
int *b;
int a=&x;
int b=&y;
int resp=*a * *b;
printf("el valor de z es %d",resp);
}
void actividad4_valor(long x, long y){
int z;
z=x*y;
printf("el valor de z es %d",z);
}





int main()
{

actividad_4valor(5,6);
actividad_4referencia(5,6);


	return 0;
}
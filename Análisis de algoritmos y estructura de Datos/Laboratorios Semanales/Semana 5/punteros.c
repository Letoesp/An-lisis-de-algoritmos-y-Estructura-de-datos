#include <stdio.h>
//nombre: Leonardo Espinoza
//Sección: C3


/*	int m=10,n;
	int *z=&m ;
	printf("m es una variable entera y su valor es 10\n");
	printf("n es variable entera\n");
	printf("*z es un entero\n");	
	printf("z almacena la direccion de m = %p\n",z); 
		//z es un puntero, %p imprime direccion de memoria
	printf("*z almacena el valor de m = %i\n",*z); 
	printf("&m es la direccion de m = %p\n",&m); 
		//&m devuelve la direccion de la variable entera m
	printf("&n almacena la direccion de n = %p\n",&n);
	printf("&z almacena la direccion de z = %p\n",&z); 
		//&z devuelve la direccion, donde el puntero z es almacenado -> sigue siendo una 

*/		//direccion de memoria por lo tanto %p es el formato correcto para mostrar
///////////////////////////////////////////////////////////////////////////////////
//Actividad 1//
///////////////////////////////////////
int *ab; 
int m=29; 
ab=&m; 
m=34;
*ab=7;
//Actividad 2//
//////////////////////////////////////////


int multi(int fno,int sno){
int mult;
int*ptr;
int *qtr;
ptr=&fno;
qtr=&sno;
mult=*ptr * *qtr;
printf("%d",mult);
}

int fno=5;
int sno=6;
multi(fno,sno);
//////////////////////////////////////////////////
//Actividad 3//
void valor(int x){
	x=x+1;
}

void referencia(int*x){
	*x=*x+1;
}
//////////////////////////////////////////////////
//Actividad 4//









int main()
{



	return 0;
}
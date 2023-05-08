// Lab semana 2  
// clock
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main(int argc, char *argv[]){
	int num1=0;
	int num2=0;
	double num3=0;
	double resultado_c=0;
	double resultado_iterativo=0;
	double resultado_recursivo=0;
	clock_t cini, cfin, ciniIt, cfinIt, ciniRe, cfinRe;
	
	num1=atoi(argv[1]);
	num2=atoi(argv[2]);
	num3=num1;
	cini=clock();
	resultado_c=sqrt(num3);
	cfin=clock();

	ciniIt=clock();
	//resultado_iterativo=Raiz_Heron_iterativa(num1,num2);
	cfinIt=clock();

	ciniRe=clock();
	//resultado_recursivo=Raiz_Heron_recursiva(num1,num2);
	cfinRe=clock();

	printf("Resultado en c %d: %f\n",num1, resultado_c); 
	printf("clock_t C:  %.15f\n",(double)(cfin-cini)/CLOCKS_PER_SEC);

	printf("Resultado iterativo %d %d: %f\n",num1, num2, resultado_iterativo); 
	printf("clock_t iterativo:  %.15f\n",(double)(cfinIt-ciniIt)/CLOCKS_PER_SEC);

	printf("Resultado Recursivo %d %d: %f\n",num1, num2, resultado_recursivo); 
	printf("clock_t recursivo:  %.15f\n",(double)(cfinRe-ciniRe)/CLOCKS_PER_SEC);
	
	return 0;	
}

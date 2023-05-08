#include <stdio.h>
#include <stdlib.h>
#include "TDAaAVL.h"

int main() 
{
	TDAarbolAVL* arbolAVL=crearAVLVacio();
	insertarNodoAVL(arbolAVL,20);
	recorridoInordenAVL(arbolAVL);
	insertarNodoAVL(arbolAVL,5);
	recorridoInordenAVL(arbolAVL);
	insertarNodoAVL(arbolAVL,10);
	recorridoInordenAVL(arbolAVL);
	insertarNodoAVL(arbolAVL,15);
	recorridoInordenAVL(arbolAVL);
	insertarNodoAVL(arbolAVL,12);
	recorridoInordenAVL(arbolAVL);


	/////// actividad 2//////
	printf("Verificacion de balances (1 = balanceado, 0 = no balanceado)\n"); 
	int esBalanceado;
	//Balance para 20
	esBalanceado = esBalanceadoNodoAVL(arbolAVL,arbolAVL->inicio);
	printf("Balance = %d\n\n",esBalanceado);
	//Balance para 5
	esBalanceado = esBalanceadoNodoAVL(arbolAVL,arbolAVL->inicio->hijoIzquierdo);
	printf("Balance = %d\n\n",esBalanceado);
	//Balance para 10
	esBalanceado = esBalanceadoNodoAVL(arbolAVL,arbolAVL->inicio->hijoIzquierdo->hijoDerecho);
	printf("Balance = %d\n\n",esBalanceado);
	//Balance para 15
	esBalanceado = esBalanceadoNodoAVL(arbolAVL,arbolAVL->inicio->hijoIzquierdo->hijoDerecho->hijoDerecho);
	printf("Balance = %d\n\n",esBalanceado);
	//Balance para 12
	esBalanceado = esBalanceadoNodoAVL(arbolAVL,
	arbolAVL->inicio->hijoIzquierdo->hijoDerecho->hijoDerecho->hijoIzquierdo);
	printf("Balance = %d\n\n",esBalanceado);

	recorridoInordenAVL(arbolAVL);printf("\n");
	return 0;
}




#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h> 

/*
Laboratorio 1 
Leonardo Espinoza Ortiz
Sección C-3
La tarea se dividirá en 2 partes:
El objetivo será mostrar todas las combinaciones posibles entre N y R y mostrarlas
en pantalla
Luego de eso, cada vez que haya dos R consiguientes, se aplica una D en ese arreglo.



Entrada:
entero que será cantidad de azulejos 
nombre de archivo de salida

Salida: se debe mostrar un numero con la cantidad de D en el arreglo.
la cantidad de combinaciones.
y mostrar todas las combinaciones posibles de N y R
*/
///////////////////////////////////////////////////////////////////
//función que permite calcular la potencia de 2*n(2*n son todas las combinaciones de n)
int potenciados(int potencia)
{
    if (potencia <= 0)
    {
        return 1;
    }
    else
    {
        return 2 * potenciados( potencia - 1);
    }
}

///////////////////////////////////////////////
//función que crea la matriz con los espacios requeridos (todas las combinaciones disponibles)
//de cada azulejo
int ** crearMatriz (int n)
{
   
    int **matriz;
    int combi;
    combi = potenciados(n);

    matriz = (int **) malloc (combi*sizeof(int*)); 

    for (int i=0 ; i<combi; i++) {
            matriz[i] = (int*) malloc (sizeof(int)* n);
    }
    return matriz;
}
//////////////////////////////////////////////////////
//Se utilizará una interpretación de generación de números binarios para el desarrollo
//del ejercicio.
//la interpretación es 0 = N y 1 = R
//función que crea un azulejo base, este tendrá el largo de los azulejos y será siempre 0.
void azulejoBase(int* arreglo, int largo){
    for (int i = 0; i < largo; i++)
    {
        arreglo[i] = 0;
    }
}
///////////////////////////////////////////////////////////////
//función que será la condición de termino para la creación de todas las combinaciones.
int condicionDeTermino(int* arreglo, int largo){
    for (int i = 0; i < largo; i++)
    {
        if (arreglo[i] == 0)
        {
            return 0;
        }
    }
    return 1;
    
}

////////////////////////////////////////////////////////////////////
//función que creará la combinación de azulejos segun el largo de este.

int** combi(int* arreglo, int largo)
{
    int** combiArreglos = crearMatriz(largo);
    int auxAncho = 0;

    for (int j = 0; j < largo; j++)
    {
        combiArreglos[auxAncho][j] = arreglo[j];
    }
    auxAncho++;

    while (condicionDeTermino(arreglo, largo) == 0)//condición de termino es que todos sean rojos
    {
        
        if (arreglo[largo - 1] == 0)//si la ultima posición es negra, se pone roja
        {
            arreglo[largo - 1] = 1;
        for (int j = 0; j < largo; j++)
        {
            combiArreglos[auxAncho][j] = arreglo[j];//avanza a la siguiente fila
        }
        auxAncho++;
        }
        else//si la posición es roja
        {
            int largoAux = largo - 2;//avanza a la penultima posición
            while (arreglo[largoAux] == 1)//mientras sea roja
            {
                largoAux = largoAux - 1;//retrocede una posición
            }
            arreglo[largoAux] = 1;//se pone rojo
            largoAux = largoAux + 1;//avanza una posición
            for (int i = largoAux; i < largo; i++)//desde esta posición hacia la derecha se pone negro
            {
                arreglo[i] = 0;
            }
            for (int j = 0; j < largo; j++)
            {
                combiArreglos[auxAncho][j] = arreglo[j];//avanza a la siguiente  fila
            }
            auxAncho++;
        }   
    }
    return combiArreglos;
}
///////////////////////////////////////////////////////
//función que permite contar las doradas.
//si encuentra dos posiciones que valen 1 ( en su defecto dos rojas, RR)
//se suma a la variable doradas 1, así se irá contando todas dentro del arreglo.


int doradas(int** listaArreglos, int largo){
    int cantCombi = potenciados(largo);
    int totalDoradas = 0;
    
    for (int i = 0; i < cantCombi; i++)
    {
        for (int j = 0; j < largo - 1; j++)
        {
            if (listaArreglos[i][j] == 1)
            {
                if (listaArreglos[i][j + 1] == 1)
                {
                    totalDoradas = totalDoradas + 1;
                }
            }
        }
    }
    return totalDoradas;
}
/////////////////////////////////////////////////////////////////
//función que sirve para escribir en el archivo de salida
void escribir(int** listaArreglos, int largo,char* nombreArchivo, int cantDoradas)
{
    FILE* textoSalida = fopen(nombreArchivo, "w");
    int cantCombi = potenciados(largo);
    fprintf(textoSalida, "%d %d\n", cantDoradas, cantCombi);//se imprime la cantidad de doradas y de combinaciones
    
    for (int i = 0; i < cantCombi; i++)
    {
        for (int j = 0; j < largo - 1; j++)
        {
            if (listaArreglos[i][j] == 1)
            {
                if (listaArreglos[i][j + 1] == 1)
                {
                    fprintf(textoSalida, "R D ");
                }
                else
                {
                    fprintf(textoSalida, "R ");
                }
            }
            else
            {
                fprintf(textoSalida, "N ");
            }
        }
        if (listaArreglos[i][largo - 1] == 1)//se printea las ultimas posiciones de las filas.
            fprintf(textoSalida, "R");
        else
            fprintf(textoSalida, "N");
        
        fprintf(textoSalida, "\n");
    }
    fclose(textoSalida);
}
//////////////////////////////////////////////////////////
//Función main que permite desarrollar todo el problema propuesto.
//Se hace llamado por consola.

int main(int argc,char *argv[]){
    if (argc != 3)
        return 1;
    //El largo es igual al n.
    int largo;
    largo= atoi(argv[1]);
    char* salida = argv[2];
    //Se crea un arreglo vacio del largo pedido
	int* lista = (int*) malloc (sizeof(int)* largo);
    azulejoBase(lista,largo);
    int** matriz = combi(lista,largo);
    int totalDoradas = doradas(matriz, largo);
    escribir(matriz,largo,salida,totalDoradas);    


    //calculo tiempo
  int** resultado=0;
	clock_t cini, cfin, ciniIt, cfinIt, ciniRe, cfinRe;

    ciniIt=clock();
	resultado=combi(lista,largo);
	cfinIt=clock();

	
	printf("clock_t :  %.15f\n",(double)(cfinIt-ciniIt)/CLOCKS_PER_SEC);
    return 0;

}

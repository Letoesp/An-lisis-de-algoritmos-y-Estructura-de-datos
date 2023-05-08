#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include "TDAlista.h"
#include "TDApila.h"

const char* archivoEntrada; //Entrada.in
int n; //Cantidad de elementos en Entrada.in

//Definición de funciones

//Función que lee el archivo de entrada las guarda en una lista enlazada.
TDAlista* leerArchivoPorlinea(const char* filename, TDAlista*lista){ 
    FILE *in_file = fopen(filename, "r");//se abre el archivo
    if (!in_file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    struct stat sb;
    if (stat(filename, &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }
    char*file_contents=malloc(sb.st_size);
    fscanf(in_file,"%[^\n] " , file_contents);//se lee la primera linea y se inserta al inicio
    insertarInicio(lista,file_contents);
    printf(">%s\n",file_contents);
    while (fscanf(in_file,"%[^\n] " , file_contents)!= EOF){//se crea un ciclo while y mientras lee inserta siempre al final de la lista
        insertarNodoFinal(lista,file_contents);
        printf(">%s\n",file_contents);
        
    }
    
    fclose(in_file);
    return lista;
}
//Función que permite verificar si una L.E tiene sus etiquetas de forma ordenada y correctamente.
int verificacion(TDAlista* lista,int n){
  TDApila*pila=crearPilaVacia(n);//se crea la pila vacía
  char*beginDoc="\\begin{document}";
  char*beginCent="\\begin{center}";
  char*beginEnu="\\begin{enumerate}";
  char*beginIte="\\begin{itemize}";
//se crean las variables char por cada etiqueta.
  char*endDoc="\\end{document}";
  char*endCent="\\end{center}";
  char*endEnu="\\end{enumerate}";
  char*endIte="\\end{itemize}";
  if (!esListaVacia(lista))
  {
    nodo* auxiliar=lista->inicio;
    while (auxiliar!=NULL)//comienza el ciclo while
    {
       
      if(auxiliar->dato==beginDoc||auxiliar->dato==beginCent||auxiliar->dato==beginEnu||auxiliar->dato==beginIte){
        apilar(pila,auxiliar->dato);
         auxiliar=auxiliar->puntero;//si el dato es igual a una de las etiquetas begin, se apila en la pila vacia
      }
      else//si no es igual a las etiquetas begin, se pregunta si es igual a las etiquetas end
      {
        if (auxiliar->dato==endDoc)
        {
            if (tope(pila)!=beginDoc)
            {
                return 0;
            }
            desapilar(pila);
            
        }
        else
        {
            if (auxiliar->dato==endCent)
            {
                if(tope(pila)!=beginCent)
                {   
                    return 0;
                }
                desapilar(pila);

            }
            else
            {
                if (auxiliar->dato==endEnu)
                {
                    if (tope(pila)!=beginEnu)
                    {
                        return 0;
                    }
                    desapilar(pila);                
                }
                else
                {
                  if (auxiliar->dato==endIte)
                  {
                      if (tope(pila)!=beginIte)
                      {
                          return 0;
                      }
                    desapilar(pila);

                  }
                
                }
                
            }

            
        }
         auxiliar=auxiliar->puntero;
      }
    }
if (esPilaVacia(pila))//cuando termine el ciclo, se consulta si la pila está vacía o no.
   {
    return 1;
   }
else
{
return 0;//si queda algun elemento en la pila, significa que las etiquetas están desordenadas.

}
printf("\n");
return 0;
}
  else
    printf("La lista está vacía\n");
}



int main(int arc, char const *argv[]){
    archivoEntrada=argv[1];
   
   TDAlista* listaE = crearListaVacia();//se crea la lista vacía
    leerArchivoPorlinea(archivoEntrada,listaE);//se lee y se guarda el archivo a la lista enlazada
    //recorrerLista(listaE);
  int n= obtenerNumeroNodos(listaE);//se usa la función obtener numero de nodos para guardarlo en n
  if (verificacion(listaE,n)==1)//se comprueba con verificación si listaE está en orden o no.
  {
    printf("la lista está en un orden correcto de etiquetas");
  }
  else
  {
    printf("la lista esta mal implementada");
  }
  

//Fin del programa.
    return 0;
}
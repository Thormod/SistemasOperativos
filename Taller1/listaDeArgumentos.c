/*
* Este programa se encarga de mostrar la lista de argumentos
* pasados al programa
*/

#include <iostream>
#include <stdio.h>

using namespace std;
//argc hace referencia a la cantidad de argumentos enviados
//argv es un vector de punteros a caracteres que son los argumentos, terminados por 0

int main( int argc, char *argv[]){
	int i;
	cout<< "Numero total de argumentos "<< argc << endl;
    /* Recorre cada uno de los argumentos y los muestra en la salida estandar */
    for(int i = 0; i<argc; i++){
    	cout << "Argumento "<< i << " " << argv[i] << endl; 
    }

    return 0;
}
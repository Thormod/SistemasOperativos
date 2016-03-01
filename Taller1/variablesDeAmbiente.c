/*
* Manejo de argumentos
*/

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

// Para crear una variable de ambiente en unix:
// $tmp = valor ó $export tmp = valor

int main( int argc, char *argv[]){

	/* Blueprint getenv
	*	char *getenv(const char *nombre)
	*/

	// Permite obtener una variable de entorno previamente establecida
	// Char para almacenar la dirección de la variable
	char *env;

	// Esta función devuelve un puntero a posició al valor correspondiente de la variable
	// ó NULL si no existe dicha variable de ambiente
	env = getenv("LPRINTER");
	cout << "Variable: "<< env << endl;
	return 0;
}
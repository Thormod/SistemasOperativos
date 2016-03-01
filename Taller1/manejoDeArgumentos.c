/*
* Manejo de argumentos
*/

#include <iostream>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int main( int argc, char *argv[]){
	extern char *optarg;
	/* Blueprint getopt:
	*	int getopt(int argc, char* const argv[], const char *opstring)
	*/

	// Cuando getopt encuentra un carácter de opción, este es devuelto, actualizando la variable optid
	// y una variable estática nextchar de modo que pueda seguir la búsqueda al siguiente carácter de opción

	// optind: Es el indice en argv del primer elemento que no es opción.
	// opstring: Cadena que contine los carácteres de opción legitimos.
	// Si un carácter es seguido de dos puntos ":" quiere decir que la opción necesita un argumento


	extern int optind, opterr, optopt;

	int option;

	// Verificando los argumentos
	// getopt analiza los argumentos de la línea de comandos.
	// Si no hay más caracteres de opción arroja -1
	while((option = getopt(argc, argv, "p:gce")) != -1){
		// Devuelve el valor en código ASCII de la opción
		switch(option){
			case 'p':
				cout << "Activada la impresora: " << optarg << endl;
				break;
			case 'g':
				cout << "Entorno gráfico activo" << endl;
				break;
			case 'c':
				cout << "Entorno de consola activado" << endl;
				break;
			case 'e':
				cout << "Otra opción más para que revises mr. Mc." << endl;
				break;
			default:
				cout << "No se reconoce la opción" << endl;
				break;
		}
	}

	return 0;
}
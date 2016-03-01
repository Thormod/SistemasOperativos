/*
* Manejo de argumentos
*/

#include <iostream>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int main( int argc, char *argv[]){
	extern char *optarg;
	
	extern int optind, opterr, optopt;

	int option;
	int index = 1;

	while((option = getopt(argc, argv, "p:gce, u:")) != -1){
		cout << "option: "<< option << endl;
		switch(option){
			case 'p':
				cout << "p: Activada la impresora: " << optarg << endl;
				index++;
				break;
			case 'g':
				cout << "g: Entorno gráfico activo" << endl;
				break;
			case 'c':
				cout << "c: Entorno de consola activado" << endl;
				break;
			case 'e':
				cout << "e: Otra opción más para que revises mr. Mc." << endl;
				break;
			case 'u':
				cout << "u: Unity server activated on port: "<< optarg << endl;
				index++;
				break;
			default:
				cout << "No se reconoce la opción" << endl;
				break;
		}
		index++;
	}
    for(int i = index; i<argc; i++){
    	cout << "Archivo: "<< i << " " << argv[i] << endl; 
	}

	return 0;
}
/*
* LProcesoSinSeñal.c
*/

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define TIMEOUT 30

using namespace std;

int main( int argc, char *argv[]){
	int valor;

	/*
	* Entra en un ciclo infinito esperando ser terminado
	*/

	for(;;){
		cout << "Esperando señal" << endl;
		// Pone a dormir el programa
		sleep(TIMEOUT);
	}

	return 0;
}
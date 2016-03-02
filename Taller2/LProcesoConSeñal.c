/*
* LProcesoConSeñal.c
*/

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// headers
#include <signal.h>

#define TIMEOUT 30

using namespace std;

/*
* Código manejador de señales
*/
// Se encarga de mostrar que número de señal se ha capturado
// Solamente se puede capturar un manejador de señal por señal
void manejador(int senal){
	cout << "Llego: " << senal << endl;
}

/* Blueprint signal
*	void (*signal(int signum, void (*manejador)(int)))(int);
*/
int main( int argc, char *argv[]){

	/*
	* Establecemos los manejadores de señal
	*/
	// Esta es la manera de instalar un manejador, este instala el mismo manejador para varias señales
	signal(SIGINT, manejador);
	signal(SIGQUIT, manejador);
	signal(SIGTERM, manejador);

	/*
	* Entra en un ciclo infinito esperando ser terminado
	*/ 

	for(;;){
		cout << "Esperando señal" << endl;
		sleep(TIMEOUT);
	}
	return 0;
}
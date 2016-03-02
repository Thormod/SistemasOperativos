/*
* LCrearPThread.c
*/

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Headers
#include <pthread.h>

using namespace std;
// El argumento arg será el argumento que será pasado a la función que implemeta el hilo
void* funcion_hilo(void *arg){
	int valor = (int) arg;

	cout << "*********************************************" << endl;
	cout << "Hola mundo desde el hilo: " << valor << endl;
	sleep(valor);
	cout << "Va a terminar el hilo: " << valor << endl;
	cout << "*********************************************" << endl;

	valor *= 100;
	return (void *) valor;
}

int main( int argc, char *argv[], char *env[]){

	int nHilos = 0;
	int i;
	// Información de los hilos
	pthread_t *tablaDeHilos;
	int valorRetorno;

	if(argc != 2){
		cout << "Uso: " << nHilos << " - " << argv[0] << endl;
		exit(1);
	}

	// Convierte el argumento string en un entero string->integer
	nHilos = atoi(argv[1]);

	cout << "*********************************************" << endl;
	cout << "nHilos principio: " << nHilos << endl;
	cout << "*********************************************" << endl;


	if(nHilos == 0){
		cout << "Uso: " << nHilos << " - " << argv[0] << endl;
		exit(1);
	}

	//Solicito memoria dinámica para la tabla
	/* Blueprint malloc
	*	void* malloc (size_t size)
	*/
	// Asigna un bloque del tamaño (size) en bytes de memoria, retorna un puntero al inicio del bloque
	// El contenido de la nueva memoria asignada no está inicializada
	tablaDeHilos = (pthread_t *)malloc(sizeof(pthread_t) * nHilos);

	for(i = 0; i < nHilos; i++){
		/* Blueprint pthread_create
		*	int pthread_create(pthread_t *thread, pthread_attr_t *attr, void * (*start_routine) (void *), void * arg);
		*	thread: Apuntador de tipo pthread que contiene el identificador del hilo de ejecución.
		*	attr: Apuntador a un tipo de dato pthread_attr_t este indica que conjunto de atributos tendrá un hilo
		*	si un hilo puede obtener el estado de terminación de otro, que politica de planificación tiene, que parametros de planificación.
		*	start_routine: Apuntador a una función donde el hilo se ejecutará
		*/

		pthread_create((tablaDeHilos + 1), NULL, funcion_hilo, (void *) i);
	}
	for(i = 0; i < nHilos; i++){
		// Espera que un hilo termine su ejecución, espera que un hilo identificado por th termine tanto por
		// una llamada explicita a la función pthread_exit
		pthread_join(*(tablaDeHilos+i), (void**) &valorRetorno);
		cout << "Valor de retorno: " << valorRetorno << " del hilo: " << *(tablaDeHilos +i) << endl;
	}
	return 0;
}
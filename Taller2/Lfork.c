/*
* Lfork.c
*/

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// headers
#include <string.h>
#include <errno.h>
#include <sys/types.h>

using namespace std;

int main( int argc, char *argv[]){

	// Id del proceso hijo
	// pid_t representa el id del proceso, es un entero con signo
	pid_t pid;
	cout << "*********************************" << endl;
	cout << "Valor inicial id del proceso: " << pid << endl;
	// Crea un nuevo proceso
	// ejecución de fork()
	cout << "*********************************" << endl;
	pid = fork();
	cout << "Momento de ejecutar fork(): " << pid << endl;
	cout << "*********************************" << endl;
	// Verificamos si la creación del proceso falla
	if(pid == (pid_t)(-1)){
		cout << "Fallo al hacer el fork, errno = " << errno << endl;
		exit(13);
	}
	// Proceso creado exitosamente, puede devolver 0 o el id del proceso hijo
	else if(pid == 0){
		// Código del proceso hijo
		// Las siguientes lineas son ejecutadas por el proceso hijo
		cout << "PID: " << (long) getpid() << " El proceso hijo iniciado, el padre es " << (long) getppid() << endl;
		// Buscamos el identificador del proceso hijo
		cout << "ID proceso hijo: " << (long) getpid() << endl;
		// Buscamos el identificador del proceso padre
		cout << "ID proceso padre: " << (long) getppid() << endl;
		cout << "*********************************" << endl;
	}
	else{
		// Código del proceso padre
		// Las siguientes líneas son ejecutadas por el proceso hijo
		cout << "PID: "<< (long) getpid() << " PID del hijo iniciado: " << (long) pid << endl;
		// Buscamos el identificador del padre actual
		cout << "ID proceso padre: " << (long) getpid() << endl;
		// Identificador del hijo
		cout << "ID proceso hijo: " << (long) pid << endl;
		cout << "*********************************" << endl;
	}
	// Tiempo de espera para ambos procesos
	//sleep(1);
	return 0;
}
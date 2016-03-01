/*
* comando env
*/

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

// env muestra todas las variables de ambiente definidas para el programa en ejecución
int main( int argc, char *argv[], char *env[]){

	int i;
	for(i=0; env[i] != NULL; i++){
		cout << env[i] << endl;
	}
	return 0;
}
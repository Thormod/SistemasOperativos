/*
* Ejemplo variables de ambiente con argumentos
*/

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int main( int argc, char *argv[]){

	char *env;

	for(int i=1; i<argc; i++){
		env = getenv(argv[i]);
		if(env != NULL){
			cout << "Variable["<< argv[i] << "] = " << env << endl;
		}else{
			cout << "Variable["<< argv[i] << "] No está definida." << endl;
		}
	}
	return 0;
}
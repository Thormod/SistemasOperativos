/*
* comando errno
*/

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

using namespace std;

int main( int argc, char *argv[]){

	int saved_errno;
	saved_errno = errno;

	cout << "Errno: " << saved_errno << endl;

	// El archivo no existe
	errno = ENOENT;
	errno = 0;

	return 0;
}
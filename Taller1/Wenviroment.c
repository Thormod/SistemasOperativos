/*
* Variables de ambiente windows
*/

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

int main( int argc, char *argv[]){
	// LPVOID: Puntero a cualquier tipo
	LPVOID lpvEnviroment;
	// LPTSTR: Puntero a un string de 8 bits terminado en null
	// Variable temporal para guardar el valor de n caracter dentro del bloque de variables
	LPTSTR lpszVar;
	// Retorna un puntero a un bloque de memoria que contiene variables de ambiente del proceso que lo llama
	// No se puede modificar ya que está almacenado en un área de sólo lectura
	lpvEnviroment = GetEnviromentStrings();

	if(lpvEnviroment){
		for(lpszVar = lpvEnviroment; *lpszVar; lpszVar++){
			while(*lpszVar){
				putchar(*lpszVar++);
				putchar('\n');
			}
		}
	}
	/* Otra manera de recorrer el arreglo:
	*
	* DWORD GetEnviromentVariable(LPCTSTR lpName, LPTSTR lpBuffer, DWORD nSize);
	* lpName: Nombre de la variable a obtener
	* lpBuffer: Si la variable de ambiente existe, retorna el número TCHAR que conforma la variable de ambiente
	*/
	FreeEnviromentStrings(lpvEnviroment);

	return 0;
}
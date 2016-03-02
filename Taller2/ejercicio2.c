/*
* ejercicio1.c
*/

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// headers
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Execute the command using this shell program.  */
#define SHELL "/bin/sh"

using namespace std;

int main( int argc, char *argv[]){

     int retVal;
     pid_t pid;

     pid = fork();

     int i;


     if(pid == (pid_t)(-1)){
          cout << "Falló al hacer el fork - "<< errno << endl;
          exit(13);
     }
     else if(pid == 0){
          //execl("bin/ls", "ls", "-l", (char *) 0);
          execl(SHELL, SHELL, argv[1],"-l" , NULL);
          cout << "ERROR: No pudo ejecutar - " << errno << endl;
     }
     else{
          wait(&retVal);
          if(WIFEXITED(retVal)){
               switch(WEXITSTATUS(retVal)){
                    // Ejemplo let "var=1/0"
                    case 1:
                         cout << "Comando con errores generales" << endl;
                         break;
                    // /dev/null
                    case 126:
                         cout << "Comando invocado no puede ejecutarse" << endl;
                         break;
                    // comando ilegal
                    case 127:
                         cout << "Comando no encontrado" << endl;
                         break;
                    // exit 3.14151
                    case 128:
                         cout << "Argumento inválido para la salida" << endl;
                         break;
                    // Crl c
                    case 130:
                         cout << "Script terminado por Control-c" << endl;
                         break;
                    // Kill -9
                    default:
                         cout << "Señal de error fatal" << endl;
                         break;
               }
               cout << "El proceso terminó bien con estado: " << WEXITSTATUS(retVal) << endl;
          }
          else if(WIFSIGNALED(retVal)){
               cout << "ERROR: La señal capturada es: " << WTERMSIG(retVal) << endl;
          }
          else if(WIFSTOPPED(retVal)){
               cout << "ERROR: EL proceso se encuentra parado - " << WSTOPSIG(retVal) << endl;
          }
     }
     
     return 0;
}
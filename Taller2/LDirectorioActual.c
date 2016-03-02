/*
* LDirectorioActual.c
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

using namespace std;

int main( int argc, char *argv[]){

     int retVal;
     pid_t pid;

     // Ejecutamos el fork para ña creación de dos procesos
     pid = fork();

     // Se verifica que la operación del fork sea correcta
     if(pid == (pid_t)(-1)){
          // Termina el proceso al no poder realizar el fork
          cout << "Falló al hacer el fork - "<< errno << endl;
          exit(13);
     }
     // Ejecución del proceso hijo
     else if(pid == 0){
          // Se encarga de remplazar su imagen con la de otro programa
          // Esuna función de parámetros variables, el primer parámetro indica la ubicación del ejecutable
          // en este caso el programa de la utilidad ls
          // El segundo parámetro indica unicamente el nombre del programa por el que será reconocido en el sistema
          // Los siguientes parámetros son una lista de argumentos variables terminada en nulo
          // Cuando se invocan algunas de las llamadas del sistema exec la imagn del proceso es reemplazada con un nuevo programa.
          // Si existe un problema en el programa no se debe ejecutar las líneas posteriores          
          execl("bin/ls", "ls", "-l", (char *) 0);
          // Manejo de error de no ejecutar
          cout << "ERROR: No pudo ejecutar - " << errno << endl;
     }
     // Mientras el padre ejecutará las siguientes líneas:
     else{
          // Espera a que el hijo termine el proceso, esta función recibe la dirección de la variable entera donde
          // almacenará el valor de retorno, contiene la información que indica el estado de terminación del hijo
          wait(&retVal);
          // Macro que indica si el proceso terminó normalmente, indica si el proceso termino bien
          // Verifica si el hijo terminó bien
          if(WIFEXITED(retVal)){
               // WEXITSTATUS: Macro que retorna el valor devuelto por el hijo
               cout << "El proceso terminó bien con estado: " << WEXITSTATUS(retVal) << endl;
          }
          // Fue señalizado
          else if(WIFSIGNALED(retVal)){
               // Estas lineas son ejecutadas si el proceso hijo no termino por sus propios medios sinó que fue señalado
               // WTERMSIG: Determina la señal en la que terminó dicho proceso
               cout << "ERROR: La señal capturada es: " << WTERMSIG(retVal) << endl;
          }
          else if(WIFSTOPPED(retVal)){
               // Se ejecuta si el proceso hijo no terminó por sus propios medios y no recibió una señal de terminación
               // sino una señal para parar el proceso
               // WSTOPSIG: Muestra la señal que paró dicho proceso
               cout << "ERROR: EL proceso se encuentra parado - " << WSTOPSIG(retVal) << endl;
          }
     }
     
     return 0;
}
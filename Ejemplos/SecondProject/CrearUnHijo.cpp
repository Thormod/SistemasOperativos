
#include <iostream>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int
main() {

  pid_t hijo;

  hijo = fork();

  if (hijo == 0) { // Hijo
    cout << "Mi id: " << getpid() << " mi padre: " << getppid() << endl;
    return 0;
  }
  else { // Padre
    cout << "Mi id: " << getpid() << " mi padre: " << getppid() << endl;
  }
  return 1;
}

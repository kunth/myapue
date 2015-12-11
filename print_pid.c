#include "apue.h"

// diagram 1-6
// getpid() return value could be stored in a long int. 
int
main() {
  printf("this process ID = %ld, its parent ID = %ld\n", (long)getpid(), (long)getppid());
  return 0;
}

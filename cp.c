#include "apue.h"
#define BUFFSIZE 4096

//diagram 1-4
//STDIN_FILENO == 0
//STDOUT_FILENO == 1
int
main(void) {
  int n;
  char buf[BUFFSIZE];
  while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
    if (write(STDOUT_FILENO, buf, n) != n)
      fprintf(stderr, "write error\n");
  }
  if (n < 0) 
    fprintf(stderr, "read error\n");
  return 0;
}

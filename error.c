#include "apue.h"
#include <errno.h>

int
main(int argc, char* argv[]) {
  fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
  errno = 10;
  perror(argv[0]);
  return 0;
}

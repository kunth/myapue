#include "apue.h"

int
main() {
  fprintf(stdout, "user id = %d, group id = %d\n", getuid(), getgid());
  return 0;
}

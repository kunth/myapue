#include "apue.h"

// diagram 3-1
int
main() {
  if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
    printf("cannot lseek\n");
  else
    printf("seek OK\n");
  return 0;
}

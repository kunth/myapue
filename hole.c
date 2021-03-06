#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int
main() {
  int fd;
  if ((fd = creat("file.hole", FILE_MODE)) < 0) 
    fprintf(stderr, "creat error");

  if (write(fd, buf1, 10) != 10)
    fprintf(stderr, "buf1 write error");

  if (lseek(fd, 30, SEEK_SET) == -1)
    fprintf(stderr, "lseek error");

  if (write(fd, buf2, 10) != 10)
    fprintf(stderr, "buf2 write error");

  return 0;
}

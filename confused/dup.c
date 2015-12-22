#include <unistd.h>
#include <stdio.h>

int
main(){
  int fd_in = dup(0);
  if (fd_in == -1) {
    printf("fd_in dup failed\n");
  } else {
    printf("dup(0) = %d\n", fd_in);
  }
  int fd_out;
  if ((fd_out = dup(1)) == -1) {
    printf("fd_out dup failed\n");
  } else {
    printf("dup(1) = %d\n", fd_out);
  }
  int fds[2] = {fd_in, fd_out};
  pipe(fds);
  char buf[256] = {0};
  int n;
  n = write(fd_out, "test", 4);
  printf("@write, n = %d\n", n);
  printf("@write, buf = %s\n", buf);

  n = read(fd_in, buf, sizeof(buf));
  if (n == -1) {
    fprintf(stderr, "read error");
  } else if (n == 0) {
    fprintf(stderr, "read to the end of the file");
  } else {
    fprintf(stderr, "@read, n = %d\n", n);
  }
  //printf("@read, buf = %s\n", buf);
  return 0;
}

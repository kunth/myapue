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

// 记录用lseek踩的一个坑
// open了一个文件后，用off_t len = lseek(fd, 0, SEEK_END)拿到了该文件的总字符数，然后再去read文件，read出来的值总是0
// 是因为lseek(fd, 0, SEEK_END)已经把fd的文件位置设置成文件末尾了，需要用lseek(fd, 0, SEEK_SET)将文件指针设置回头部，
// 再read出来就ok了

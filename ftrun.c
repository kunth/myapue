#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int
main() {
	int fd = open("ftrun.txt", O_RDWR | O_CREAT);
	if (fd == -1) {
		perror("myread");
	}
	char buf[7] = "123456";
	buf[6] = '\0';
	ssize_t ret = write(fd, buf, sizeof(buf));
	if (ret == -1) {
		perror("mywrite");
	}
	int f = ftruncate(fd, 1000000);
	if (f == -1) {
		perror("myftruncate");
	}
	return 0;
}

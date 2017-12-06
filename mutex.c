#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

pthread_mutex_t lock;
int count;

void* task1() {
	pthread_mutex_lock(&lock);
	int i = 0;
	for (; i<100000; ++i) {
		++count;
	}
	printf("in task1, count=%d\n", count);
	sleep(1);
	printf("task1 sleep over\n");
	pthread_mutex_unlock(&lock);
	return NULL;
}

void* task2() {
	//pthread_mutex_lock(&lock);
	int i = 0;
	for (; i<100000; ++i) {
		++count;
	}
	printf("in task2, count=%d\n", count);
	sleep(1);
	printf("task2 sleep over\n");
	//pthread_mutex_unlock(&lock);
	return NULL;
}

int main(void)
{
	int ret=0;
	pthread_t t1;
	pthread_t t2;

	if (pthread_mutex_init(&lock, NULL) != 0) {
		printf("mutex init failed\n");
		return 1;
	}

	ret=pthread_create(&t1, NULL, task1, NULL); //创建子线程
	ret=pthread_create(&t2, NULL, task2, NULL);
	pthread_join(t1, NULL); //等待子线程结束
	pthread_join(t2, NULL);

	pthread_mutex_destroy(&lock);
	return 0;
}


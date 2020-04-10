#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>

void error(const char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(0);
}

void *do_stuff(void *param) {
    long thread_no = (long)param;
    printf("Thread №%ld\n", thread_no);
    return (void *)(thread_no + 1);
}

int main() {
    pthread_t threads[20];
    long i;
    for (i = 0; i < 3; ++i) {
	if (pthread_create(&threads[i], NULL, do_stuff, (void *)i) == -1)
	    error("Cann't create thread");
    }

    void *result;
    for (i = 0; i < 3; ++i) {
	if (pthread_join(threads[i], &result) == -1)
	    error("Cann't join to thread");

	printf("Thread №%ld returns %ld\n", i, (long)result);
    }

    return 0;
}

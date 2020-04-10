#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>

int beers = 2000000;

pthread_mutex_t a_lock = PTHREAD_MUTEX_INITIALIZER;

void error(const char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

void *drink_lots(void *a) {
    int i;
    for (i = 0; i < 100000; ++i) {
	pthread_mutex_lock(&a_lock);
	--beers;
	pthread_mutex_unlock(&a_lock);
    }
    return NULL;
}

int main() {
    printf("%i bottles of the beer\n", beers);
    pthread_t threads[20];
    int i;
    for (i = 0; i < 20; ++i) {
	if (pthread_create(&threads[i], NULL, drink_lots, NULL) == -1)
	    error("Cann't create thread");
    }

    void *result;
    for (i = 0; i < 20; ++i) {
	if (pthread_join(threads[i], &result) == -1)
	    error("Cann't join to thread");
    }

    printf("%i bottles of the beer\n", beers);

    return 0;
}

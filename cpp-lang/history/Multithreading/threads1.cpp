#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <pthread.h>
#include <unistd.h>

void *threadFunc(void *arg) {
    char *str = (char*)arg;

    for (size_t i = 0; i != 10; ++i) {
	usleep(1);
	cout << str << endl;
    }

    return nullptr;
}

void error(const char *msg) {
    cerr << msg << endl;
    exit(1);
}

int main() {
    pthread_t thread;
    if (pthread_create(&thread,
		       nullptr,
		       threadFunc,
		       (void*)"processing...") == -1) {
	error("Cann't create a thread");
    }

    if (pthread_join(thread, nullptr) == -1)
	error("Cann't join to thread");

    for (size_t i = 0; i != 10; ++i) {
	usleep(1);
	cout << "main() is running..." << endl;
    }

    return 0;
}

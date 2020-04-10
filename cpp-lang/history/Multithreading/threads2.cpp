#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <pthread.h>
#include <unistd.h>

void *threadFunc(void *) {
    for (size_t i = 0; i != 110; ++i) {
	usleep(1);
	cout << "processing..." << endl;
    }
    return nullptr;
}

void error(const char *msg) {
    cerr << msg << endl;
    exit(1);
}

int main() {
    pthread_t thread;
    if (pthread_create(&thread, nullptr, threadFunc, nullptr) == -1)
	error("Cann't create a thread");

    for (size_t i = 0; i != 100; ++i) {
	usleep(1);
	cout << "main() is running..." << endl;
    }

    cout << "main() waiting for thread to terminate..." << endl;
    pthread_join(thread, nullptr);

    return 0;
}

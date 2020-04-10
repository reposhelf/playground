#include <chrono>
#include <ctime>
#include <cstdlib>
#include <iostream>

template<typename T> void exch(T &A, T &B) {
    T t = A;
    A = B;
    B = t;
}

template<typename T> void compexch(T &A, T &B) {
    if (B < A)
        exch(A, B);
}

template<typename T> void sort(T a[], int l, int r) {
    for (int i = l + 1; i <= r; ++i) {
        for (int j = i; j > l; --j)
            compexch(a[j - 1], a[j]);
    }
}

int main(int argc, char **argv) {
    int fromSize = std::atoi(argv[1]);
    int toSize = std::atoi(argv[2]);
    int step = std::atoi(argv[3]);

	int iterations = 0;
	std::chrono::duration<double> elapsedSeconds;

	for (; fromSize <= toSize; fromSize += 10) {
		// create and fill an array by random values
		int *array = new int[fromSize];
		for (int j = 0; j < fromSize; ++j)
			array[j] = 1000 * (1.0 * rand() / RAND_MAX);

        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
		sort(array, 0, fromSize - 1);
		end = std::chrono::system_clock::now();
		elapsedSeconds += end - start;
		++iterations;

		delete[] array;
	}

    std::cout << "Average duration: "
              << elapsedSeconds.count() / iterations
              << "s\n";

	return 0;
}

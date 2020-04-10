#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    if (argc == 1) {
        cout << "Error: enter a number after the command" << endl;
        return -1;
    }

    const int N = atoi(argv[1]); 
    int count = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                ++count;
            }
        }
    }
    cout << count << endl;
    return 0;
}
#include <iostream>
#include <cmath>

typedef unsigned long long ull;

#define STD_INPUT_ERROR "error: standard input failed"
#define DIV_BY_ZERO_ERROR "error: division by zero"

inline void error(const char *msg) {
    std::cout << msg << std::endl;
    exit(1);
}

ull factorial(ull value) {
    return value == 0 ? 1 : factorial(value - 1) * value;
}

double get_expr_result(double k, double x) {
    double dividend = pow(-1, k) * pow(x, 4 * k + 1);
    double divisor = (factorial(2 * k) * (2 * k + 1));

    if (divisor == 0.0)
	error(DIV_BY_ZERO_ERROR);

    return dividend / divisor;
}

inline double get_input(const char *msg) {
    std::cout << msg;
    double input;
    std::cin >> input;
    if (!std::cin) {
	error(STD_INPUT_ERROR);
    }
    return input;
}

int main(int argc, char **argv) {
    double epsilon = get_input("enter epsilon: ");
    double x = get_input("enter x: ");

    double sum = 0.0;
    int k = 0;

    while (true) {
	double result = get_expr_result(k++, x);
	if (std::fabs(result) < epsilon)
	    break;
	sum += result;
    }

    std::cout << "the sum is: " << sum << std::endl;
    std::cout << "the number of terms: " << k - 1 << std::endl;

    return 0;
}

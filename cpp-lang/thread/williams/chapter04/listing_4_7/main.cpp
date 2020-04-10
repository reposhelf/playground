/*
 * Listing 4.7. Passing arguments to a function with std::async
 */
#include <future>
#include <string>

struct X
{
    void foo(int, const std::string&) {}
    std::string bar(const std::string&) { return std::string(); }
};

struct Y
{
    double operator()(double) { return 0.0; }
};

X baz(X&) { return X(); }

class move_only
{
public:
    move_only() {}
    move_only(move_only&&) {}
    move_only(const move_only&) = delete;
    move_only &operator=(move_only&&) { return *this; }
    move_only &operator=(const move_only&) = delete;

    void operator()() {}
};


int main()
{
    X x;
    auto f1 = std::async(&X::foo, &x, 42, "hello"); // calls p->foo(42, "hello") where p is &x
    auto f2 = std::async(&X::bar, x, "goodbye"); // calls tmpx.bar("goodbye") where tmpx is a copy of x

    Y y;
    auto f3 = std::async(Y(), 3.14); // calls tmpy(3.14) where tmpy is move-constructed from Y()
    auto f4 = std::async(std::ref(y), 3.14); // calls y(3.14)

    std::async(baz, std::ref(x)); // calls baz(x)

    auto f5 = std::async(move_only()); // calls tmp() where is constructed from std::move(move_only())

    return 0;
}

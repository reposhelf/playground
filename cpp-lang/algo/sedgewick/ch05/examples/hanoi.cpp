#include <iostream>
#include <string>

static const int INDENT = 4;

void error(const char *msg)
{
    std::cerr << msg << std::endl;
    exit(1);
}

void shift(int disk, int direction, std::string space)
{
    std::cout << space << "shift(" << disk << ", "
              << (direction > 0 ? "+" : "")
              << direction << ")" << std::endl;
}

void hanoi(int disk, int direction, std::string space = "")
{
    std::cout << space << "hanoi(" << disk << ", "
              << (direction > 0 ? "+" : "")
              << direction << ")" << std::endl;

    if (disk == 0)
        return;

    const std::string indent = std::string(INDENT, ' ');

    hanoi(disk - 1, -direction, space + indent);
    shift(disk, direction, space + indent);
    hanoi(disk - 1, -direction, space + indent);
}

int main(int argc, char **argv)
{
    if (argc < 2)
        error("Type: PRORGAM <DISKS_COUNT>");

    hanoi(std::atoi(argv[1]), 1);

    return 0;
}
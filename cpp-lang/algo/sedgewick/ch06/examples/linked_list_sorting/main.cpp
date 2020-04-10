#include "link.h"

int main(int /*argc*/, char **argv)
{
    showlist(sortlist(randlist(std::atoi(argv[1]))));
    return 0;
}

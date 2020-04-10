#include "traverseorder.h"

using namespace std;

TraverseOrder::TraverseOrder()
    : _data(new vector<int>())
{}

TraverseOrder::TraverseOrder(initializer_list<int> init)
    : _data(new vector<int>(init))
{}

void TraverseOrder::push_back(int i)
{
    _data->push_back(i);
}
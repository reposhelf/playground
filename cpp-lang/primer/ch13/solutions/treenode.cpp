#include "treenode.h"

using namespace std;

TreeNode::TreeNode(const std::string &v, int c, TreeNode *l, TreeNode *r)
    : _value(v), _count(c), _left(l), _right(r)
{
}

TreeNode::TreeNode(const TreeNode &other)
    : _value(other._value), _count(other._count), _left(nullptr), _right(nullptr)
{
    if (other._left)
        _left = new TreeNode(*other._left);
    if (other._right)
        _right = new TreeNode(*other._right);
}

TreeNode &TreeNode::operator=(const TreeNode &rhs)
{
    delete _left;
    _left = nullptr;
    
    delete _right;
    _right = nullptr;

    _value = rhs._value;
    _count = rhs._count;
    if (rhs._left)
        _left = new TreeNode(*rhs._left);
    if (rhs._right)
        _right = new TreeNode(*rhs._right);

    return *this;
}

TreeNode::~TreeNode()
{
    delete _left;
    delete _right;
}
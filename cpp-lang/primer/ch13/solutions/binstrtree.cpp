#include "binstrtree.h"
#include "treenode.h"

BinStrTree::BinStrTree(TreeNode *r)
    : _root(r)
{
}

BinStrTree::BinStrTree(const BinStrTree &other)
    : _root(new TreeNode(*other._root))
{
}

BinStrTree &BinStrTree::operator=(const BinStrTree &rhs)
{
    if (*this != rhs) {
        delete _root;
        _root = new TreeNode(*rhs._root);
    }
    return *this;
}

BinStrTree::~BinStrTree()
{
    delete _root;
}
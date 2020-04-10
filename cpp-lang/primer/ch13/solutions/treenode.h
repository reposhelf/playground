#ifndef TREENODE_H
#define TREENODE_H

#include <string>

class TreeNode
{
public:
    TreeNode(const std::string &v, int c, TreeNode *l, TreeNode *r);
    TreeNode(const TreeNode &other);
    TreeNode &operator=(const TreeNode &rhs);
    ~TreeNode();

    const std::string &value() const { return _value; }
    TreeNode *left() const { return _left; }
    TreeNode *right() const { return _right; }

private:
    std::string _value;
    int _count;
    TreeNode *_left;
    TreeNode *_right;

    friend bool operator==(const TreeNode &lhs, const TreeNode &rhs);
    friend bool operator!=(const TreeNode &lhs, const TreeNode &rhs);
};

inline bool operator==(const TreeNode &lhs, const TreeNode &rhs)
{
    return lhs._value == rhs._value && lhs._count == rhs._count
            && lhs._left == rhs._left && lhs._right == rhs._right
            && *lhs._left == *rhs._left && lhs._right == rhs._right;
}

inline bool operator!=(const TreeNode &lhs, const TreeNode &rhs)
{
    return !(lhs == rhs);
}

#endif
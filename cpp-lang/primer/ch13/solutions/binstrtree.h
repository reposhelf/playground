#ifndef BINSTRTREE_H
#define BINSTRTREE_H

class TreeNode;
class BinStrTree
{
public:
    explicit BinStrTree(TreeNode *r);
    BinStrTree(const BinStrTree &other);
    BinStrTree &operator=(const BinStrTree &rhs);
    ~BinStrTree();

    TreeNode *root() const { return _root; }

private:
    TreeNode *_root;

    friend bool operator==(const BinStrTree &lhs, const BinStrTree &rhs);
    friend bool operator!=(const BinStrTree &lhs, const BinStrTree &rhs);
};

inline bool operator==(const BinStrTree &lhs, const BinStrTree &rhs)
{
    return lhs._root == rhs._root;
}

inline bool operator!=(const BinStrTree &lhs, const BinStrTree &rhs)
{
    return !(lhs == rhs);
}

#endif
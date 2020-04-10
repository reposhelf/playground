#include <iostream>
using namespace std;

struct node
{
    char item;
    node *left;
    node *right;
    node(char i, node *l, node *r)
        : item(i), left(l), right(r) { }
};
typedef node *link;

link make_tree()
{
    link root = new node('E', nullptr, nullptr);
    // left subtree
    root->left = new node('D', nullptr, nullptr);
    root->left->left = new node('B', nullptr, nullptr);
    root->left->left->right = new node('C', nullptr, nullptr);
    root->left->left->left = new node('A', nullptr, nullptr);
    // right subtree
    root->right = new node('H', nullptr, nullptr);
    root->right->left = new node('F', nullptr, nullptr);
    root->right->left->right = new node('G', nullptr, nullptr);
    return root;
}

void destroy_tree(link l)
{
    if (!l)
        return;
    destroy_tree(l->left);
    destroy_tree(l->right);
    delete l;
}

void print_node(char c, int h)
{
    for (int i = 0; i < h; ++i)
        cout << ' ';
    cout << c << endl;
}

void show_tree(link l, int h)
{
    if (!l) {
        print_node('*', h);
        return;
    }
    print_node(l->item, h + 3); // uncomment to preorder traverse
    show_tree(l->right, h + 3);
//    print_node(l->item, h);  // comment to preorder traverse
    show_tree(l->left, h + 3);
}

int main()
{
    link l = make_tree();
    show_tree(l, 0);
    destroy_tree(l);
    return 0;
}

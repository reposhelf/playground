#include <iostream>

using namespace std;

struct node
{
    int item;
    node *l;
    node *r;
};
typedef node *link;

void visit(link h)
{
    if (h)
        cout << h->item << endl;
}

void traverse_preorder(link h, void visit(link))
{
    if (!h)
        return;

    visit(h);
    traverse_preorder(h->l, visit);
    traverse_preorder(h->r, visit);
}

void traverse_inorder(link h, void visit(link))
{
    if (!h)
        return;

    traverse_inorder(h->l, visit);
    visit(h);
    traverse_inorder(h->r, visit);
}

void traverse_postorder(link h, void visit(link))
{
    if (!h)
        return;

    traverse_postorder(h->l, visit);
    traverse_postorder(h->r, visit);
    visit(h);
}

int main()
{
    link h = 0;
    traverse_preorder(h, visit);
    traverse_inorder(h, visit);
    traverse_postorder(h, visit);
    return 0;
}

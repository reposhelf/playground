#include <iostream>
#include <stack>

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
    stack<link> s;
    s.push(h);

    while (!s.empty()) {
        visit(h = s.top());
        s.pop();
        if (h->r)
            s.push(h->r);
        if (h->l)
            s.push(h->l);
    }
}

void traverse_postorder(link h, void visit(link))
{
}

int main()
{
    link h = 0;
    traverse_preorder(h, visit);
    return 0;
}

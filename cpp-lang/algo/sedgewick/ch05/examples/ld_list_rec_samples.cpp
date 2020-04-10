struct node {
    int item;
    node *next;
};
typedef node *link;

int count(link x)
{
    return !x ? 0 : 1 + count(x->next);
}

void traverse(link x, void visit(link))
{
    if (x) {
	visit(x);
	traverse(x->next, visit);
    }
}

void traverseR(link x, void visit(link))
{
    if (x) {
	traverseR(x->next, visit);
	visit(x);
    }
}

void remove(link x, int v)
{
    while (x && x->item == v) {
	link t = x;
	x = x->next;
	delete t;
    }
    if (x)
	remove(x->next, v);
}

int main()
{
    return 0;
}

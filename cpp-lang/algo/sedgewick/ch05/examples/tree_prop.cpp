struct node
{
    int item;
    node *l;
    node *r;
};
typedef node *link;

int count(link h)
{
    return h ? count(h->l) + count(h->r) + 1 : 0;
}

int height(link h)
{
    if (!h)
        return -1;

    int l = height(h->l);
    int r = height(h->r);

    return l > r ? l + 1 : r + 1;
}

int main()
{
    return 0;
}

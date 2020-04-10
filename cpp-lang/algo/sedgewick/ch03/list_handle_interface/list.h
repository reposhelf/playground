#ifndef NODE_H
#define NODE_H

typedef int Item;
struct node { Item item; node *next; };
typedef node *link;
typedef link Node;

void construct(int);
link newNode(int);
void deleteNode(link);
void insert(link, link);
link remove(link);
link next(link);
Item item(link);

#endif 
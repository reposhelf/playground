/*
 * Exercise 12.14:
 * Write your own version of a function that uses a
 * shared_ptr to manage a connection.
 */

#include "chapter12.h"

connection connect(destination *dest)
{
    connection c;
    c.dest = dest;
    return c;
}

void disconnect(connection *c)
{
    c->dest = 0;
}

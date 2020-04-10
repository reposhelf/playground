#include "solutions.h"
#include "list.h"

#include <cstdlib>

void solve_3_33()
{
    // create a list
    auto list = createRandomList(10);
    // display list before handling
    display(list);
    // handle list
    moveLargestToEnd(list);
    // display list after handling
    display(list);
}

void solve_3_34()
{
    // create a list
    auto list = createRandomList(10);
    // display list before handling
    display(list);
    // handle list
    moveSmallestToBegin(list);
    // display list after handling
    display(list);
}

void solve_3_35()
{
    // create a list
    auto list = createSortedList(10);
    // display list before handling
    display(list);
    // handle list
    separateEvensAndOdds(list);
    // display list after handling
    display(list);
}

void solve_3_36()
{
    // create a list
    auto list = createRandomList(10);
    // display list before handling
    display(list);
    // get t link
    auto t = list;
    for (int i = 0; i < 2; ++i)
        t = t->next;
    // get u link
    auto u = list;
    for (int i = 0; i < 7; ++i)
        u = u->next;
    // handle list
    exchangeNext(t, u);
    // display list after handling
    display(list);
}

void solve_3_37()
{
    // create a list
    auto list = createRandomList(10);
    // make copy
    auto list_cp = listCopy(list);
    // display two lists
    display(list);
    display(list_cp);
}

void solve_3_38()
{
    // create a list
    auto list = createRandomList(10);
    // display list before handling
    display(list);
    // handle list
    clearByValues(list, nextValue);
    // display list after handling
    display(list);
}

void solve_3_39()
{
    // create a list
    auto list = createRandomList(10);
    // display before handling
    display(list);
    // make copy
    auto list_cp = listCopy(list, nextValue);
    // display two lists
    display(list);
    display(list_cp);
}

void solve_3_40()
{
    // create a list
    auto list = createRandomList(10);
    // display before handling
    display(list);
    // handle a list
    reverse(list);
    // display after handling
    display(list);
}
#include <iostream>
void solve_3_41()
{
    // create a list
    auto list = createRandomList(10);
    // display before handling
    display(list);
    // handle a list
    // remove head node
    auto tail = list->next;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = list;
    tail->next = tail->next->next;
    list = tail->next;
    // handle list
    list = sort(list);
    //display after handling
    auto head = list;
    do {
        std::cout << list->item << ' ';
        list = list->next;
    } while (list != head);
    std::cout << std::endl;
}

void solve_3_42()
{
    // create a list
    auto list = createSortedList(9);
    // display before handling
    display(list);
    // handling
    list = josephushElection(list);
    // display after handling
    display(list);
}
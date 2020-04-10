#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"

#include <vector>
#include <memory>

using namespace std;

double print_total(ostream &os, const Quote &quote, size_t n)
{
    double ret = quote.net_price(n);
    os << "ISBN: " << quote.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

int main()
{
    Quote quote("X02356-7845-25689", 2.99);
    Bulk_quote bulk("Y4567-56234-7889", 3.99, 5, 0.1);
    Limit_quote limit("Z789565-45612-235556", 1.89, 10, 0.1);

    print_total(cout, quote, 1);
    print_total(cout, bulk, 5);
    print_total(cout, limit, 10);

    quote.debug();
    bulk.debug();
    limit.debug();

    vector<Quote> wrongBasket;
    wrongBasket.push_back(Bulk_quote("Y4567-56234-7889", 3.99, 5, 0.1));
    cout << wrongBasket.back().net_price(15) << endl;

    vector<shared_ptr<Quote>> rightBasket;
    rightBasket.push_back(make_shared<Bulk_quote>("Y4567-56234-7889", 3.99, 5, 0.1));
    cout << rightBasket.back()->net_price(15) << endl;

    return 0;
}

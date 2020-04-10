#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"
#include "basket.h"

int main()
{
    Quote quote("X02356-7845-25689", 2.99);
    Bulk_quote bulk("Y4567-56234-7889", 3.99, 5, 0.1);
    Limit_quote limit("Z789565-45612-235556", 1.89, 10, 0.1);

    Basket bsk;
    bsk.addItem(quote);
    bsk.addItem(bulk);
    bsk.addItem(limit);
    bsk.total_receipt(std::cout);

    return 0;
}

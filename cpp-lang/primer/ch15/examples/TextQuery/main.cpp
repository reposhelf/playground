#include "Query.h"
#include "WordQuery.h"
#include "NotQuery.h"
#include "OrQuery.h"
#include "AndQuery.h"

int main(int, char **)
{
    std::ifstream file("story.txt");
    TextQuery textQuery(file);

    Query q = (Query("fiery") & Query("bird")) | Query("wind");
    std::cout << q << std::endl;
    std::cout << q.eval(textQuery) << std::endl;

    q = Query("Daddy");
    std::cout << q.eval(textQuery) << std::endl;

    q = ~(Query("Alice"));
    std::cout << q.eval(textQuery) << std::endl;

    q = Query("hair") | Query("Alice");
    std::cout << q.eval(textQuery) << std::endl;

    q = Query("hair") & Query("Alice");
    std::cout << q.eval(textQuery) << std::endl;

//    BinaryQuery a = Query("fiery") & Query("bird");
//    AndQuery b = Query("fiery") & Query("bird");
//    OrQuery c = Query("fiery") & Query("bird");

    return 0;
}

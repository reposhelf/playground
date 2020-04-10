#include "Query.h"
#include "WordQuery.h"
#include "NotQuery.h"
#include "OrQuery.h"
#include "AndQuery.h"

int main(int, char **)
{
    std::ifstream file("story.txt");
    TextQuery textQuery(file);

    Query q = Query("fiery");
    q.addToHistory();
    
    q = Query("bird");
    q.addToHistory();

    q = Query("wind");
    q.addToHistory();
    
    q = Query("Daddy");
    q.addToHistory();

    q = ~Query("Alice");
    q.addToHistory();

    q = Query("Alice");
    q.addToHistory();

    q = Query("hair");
    q.addToHistory();

    q = Query("wind", Query::PerOnceOutput);
    q.addToHistory();


    q = (Query::fromHistory(0) & Query::fromHistory(1)) | Query::fromHistory(2);
    std::cout << q.eval(textQuery) << std::endl;

    q = Query::fromHistory(3);
    std::cout << q.eval(textQuery) << std::endl;

    q = Query::fromHistory(4);
    std::cout << q.eval(textQuery) << std::endl;

    q = Query::fromHistory(6) | Query::fromHistory(5);
    std::cout << q.eval(textQuery) << std::endl;

    q = Query::fromHistory(6) & Query::fromHistory(5);
    std::cout << q.eval(textQuery) << std::endl;

    q = Query::fromHistory(7);
    std::cout << q.eval(textQuery) << std::endl;

    return 0;
}

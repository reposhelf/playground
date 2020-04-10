#include "CppUTest/TestHarness.h"
#include "chapter11.h"

using namespace std;

TEST_GROUP(test_sol_11_31)
{
    void setup()
    {
        MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
    }

    void teardown()
    {
        MemoryLeakWarningPlugin::turnOnNewDeleteOverloads();
    }
};

TEST(test_sol_11_31, test_01)
{
    multimap<string, string> authors;
    // Stephen King
    authors.insert({"King, Stephen", "Carrie"});
    authors.insert({"King, Stephen", "The Shining"});
    authors.insert({"King, Stephen", "Rage"});
    authors.insert({"King, Stephen", "The Stand"});
    authors.insert({"King, Stephen", "The Long Walk"});
    // Leo Tolstoy
    authors.insert({"Tolstoy, Leo", "Childhood"});
    authors.insert({"Tolstoy, Leo", "Boyhood"});
    authors.insert({"Tolstoy, Leo", "Youth"});
    // Nikolai Gogol
    authors.insert({"Gogol, Nikolai", "Taras Bulba"});
    authors.insert({"Gogol, Nikolai", "Viy"});
    // Fyodor Dostoyevsky
    authors.insert({"Dostoyevsky, Fyodor", "The Idiot"});
    authors.insert({"Dostoyevsky, Fyodor", "Demons"});
    authors.insert({"Dostoyevsky, Fyodor", "The Brothers Karamazov"});
    authors.insert({"Dostoyevsky, Fyodor", "Crime and Punishment"});

    LONGS_EQUAL(authors.size(), 14);

    // Remove Tolstoy
    string removal_author("Tolstoy, Leo");
    map<string, string>::iterator it;
    while ((it = authors.find(removal_author)) != authors.end())
	authors.erase(it);

    LONGS_EQUAL(authors.size(), 11);
}

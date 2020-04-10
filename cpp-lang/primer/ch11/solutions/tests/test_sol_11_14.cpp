#include "CppUTest/TestHarness.h"
#include "chapter11.h"

using namespace std;

TEST_GROUP(test_sol_11_14)
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

TEST(test_sol_11_14, test_01)
{
    map<string, vector<pair<string, string>>> family;

    vector<pair<string, string>> becks_children = {
	{"Alan", "Jan 12 1999"},
	{"Diana", "Feb 05 1997"},
	{"Bruce", "Jun 20 2000"}};
    vector<pair<string, string>> schmidts_children = {
	{"Oliver", "Mar 17 1999"}, 
	{"Michael", "Apr 22 2002"}};
    vector<pair<string, string>> jacksons_children = {
	{"Anna", "Jul 21 2000"}};
    vector<pair<string, string>> hodjsons_children = {
	{"Barbara", "May 01 1998"},
	{"Sarah", "Sep 07 2000"}};

    add_family("Becks", vector<pair<string, string>>(), family);
    add_child("Becks", "Alan", "Jan 12 1999", family);
    add_child("Becks", "Diana", "Feb 05 1997", family);
    add_child("Becks", "Bruce", "Jun 20 2000", family);

    add_family("Schmidt", vector<pair<string, string>>(), family);
    add_child("Schmidt", {"Oliver", "Mar 17 1999"}, family);
    add_child("Schmidt", {"Michael", "Apr 22 2002"}, family);

    add_family("Jackson", vector<pair<string, string>>(), family);
    add_child("Jackson", "Anna", "Jul 21 2000", family);

    add_family("Hodjson", hodjsons_children, family);

    CHECK(family["Becks"][0].first == becks_children[0].first);
    CHECK(family["Becks"][0].second == becks_children[0].second);
    CHECK(family["Becks"][1].first == becks_children[1].first);
    CHECK(family["Becks"][1].second == becks_children[1].second);
    CHECK(family["Becks"][2].first == becks_children[2].first);
    CHECK(family["Becks"][2].second == becks_children[2].second);

    CHECK(family["Schmidt"][0].first == schmidts_children[0].first);
    CHECK(family["Schmidt"][0].second == schmidts_children[0].second);
    CHECK(family["Schmidt"][1].first == schmidts_children[1].first);
    CHECK(family["Schmidt"][1].second == schmidts_children[1].second);

    CHECK(family["Jackson"][0].first == jacksons_children[0].first);
    CHECK(family["Jackson"][0].second == jacksons_children[0].second);

    CHECK(family["Hodjson"][0].first == hodjsons_children[0].first);
    CHECK(family["Hodjson"][0].second == hodjsons_children[0].second);
}

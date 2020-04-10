#include "chapter11.h"

using namespace std;

void add_family(const std::string &fln,
		const std::vector<std::pair<std::string, std::string>> &c,
		std::map<std::string,
		    std::vector<std::pair<std::string, std::string>>> &f)
{
    f[fln] = c;
}

void add_child(const std::string &fln,
	       const std::pair<std::string, std::string> &c,
	       std::map<std::string,
	           std::vector<std::pair<std::string, std::string>>> &f)
{
    f[fln].push_back(c);
}

void add_child(const std::string &fln,
	       const std::string &child_name,
	       const std::string &birthday,
	       std::map<std::string,
	           std::vector<std::pair<std::string, std::string>>> &f)
{
    f[fln].push_back({child_name, birthday});
}


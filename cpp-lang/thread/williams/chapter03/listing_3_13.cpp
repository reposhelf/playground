/*
 * Listing 3.13. Protecting a data structure with a boost::shared_mutex
 */

#include <map>
#include <string>
#include <mutex>
#include <boost/thread/shared_mutex.hpp>

class dns_entry {};
class dns_cache {
public:
	dns_entry find_entry(const std::string &domain) const {
		boost::shared_lock<boost::shared_mutex> lk(entry_mutex_);
		std::map<std::string, dns_entry>::const_iterator const it
		    = entries_.find(domain);
		return (it == entries_.end()) ? dns_entry() : it->second;
	}

	void update_or_add_entry(const std::string &domain,
	                         const dns_entry &dns_details) {
		std::lock_guard<boost::shared_mutex> lk(entry_mutex_);
		entries_[domain] = dns_details;
	}
private:
	std::map<std::string, dns_entry> entries_;
	mutable boost::shared_mutex entry_mutex_;
};

int main() {
	return 0;
}
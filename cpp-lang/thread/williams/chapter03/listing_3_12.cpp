/*
 * Listing 3.12. Thread-safe lazy initialization of a class member
 * using std::call_once 
 *
 */

#include <mutex>

struct connection_info {};
struct data_packet {};
struct connection_handle {
	void send_data(const data_packet&) {}
	void receive_data(const data_packet&) {}
};
struct connection_manager {
	static connection_handle open(const connection_info&) {
		return connection_handle();
	}
};

class X {
public:
	explicit X(const connection_info &connection_details)
	    : connection_details_(connection_details) {
	    // Empty
    }

    void send_data(const data_packet &data) {
    	std::call_once(connection_init_flag_, &X::open_connection, this);
    	connection_.send_data(data);
    }
    void receive_data(const data_packet &data) {
    	std::call_once(connection_init_flag_, &X::open_connection, this);
    	connection_.receive_data(data);
    }

private:
	void open_connection() {
		connection_ = connection_manager::open(connection_details_);
	}

	connection_info connection_details_;
	connection_handle connection_;
	std::once_flag connection_init_flag_;
};

int main() {
	return 0;
}
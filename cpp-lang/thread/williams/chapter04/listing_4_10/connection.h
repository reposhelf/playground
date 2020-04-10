#ifndef CONNECTION_H
#define CONNECTION_H

#include <future>
#include <map>
#include <memory>
#include <queue>
#include <vector>

// Type-Stub
struct PayloadType
{
    // Empty
};

struct DataPacket
{
    unsigned id;
    PayloadType payload;
};

struct OutgoingPacket
{
    PayloadType payload;
    std::promise<bool> promise;
};

class Connection;
using ConnectionSet = std::vector<std::shared_ptr<Connection>>;

class Connection
{
public:
    Connection() = default;
    ~Connection() = default;
    Connection(const Connection&) = delete;
    Connection& operator=(const Connection&) = delete;
    bool hasIncomingData() const;
    bool hasOutgoingData() const;
    DataPacket incoming();
    OutgoingPacket topOfOutgoingQueue();
    std::promise<PayloadType>& getPromise(unsigned id);
    void send(PayloadType payload) const;
private:
    std::queue<DataPacket> _incomingData;
    std::queue<OutgoingPacket> _outgoingData;
    std::map<unsigned, std::promise<PayloadType>> _promises;
};

#endif // CONNECTION_H

#include "connection.h"

bool Connection::hasIncomingData() const
{
    return !_incomingData.empty();
}

bool Connection::hasOutgoingData() const
{
    return !_outgoingData.empty();
}

DataPacket Connection::incoming()
{
    if (hasIncomingData()) {
        DataPacket data = _incomingData.front();
        _incomingData.pop();
        return data;
    }
    return DataPacket();
}

OutgoingPacket Connection::topOfOutgoingQueue()
{
    if (hasOutgoingData()) {
        OutgoingPacket data = std::move(_outgoingData.front());
        _outgoingData.pop();
        return data;
    }
    return OutgoingPacket();
}

std::promise<PayloadType>& Connection::getPromise(unsigned id)
{
    return _promises[id];
}

void Connection::send(PayloadType /*payload*/) const
{
    // Empty
}

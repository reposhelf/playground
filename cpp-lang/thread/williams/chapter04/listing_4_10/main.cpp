#include "connection.h"

int main()
{
    // for example, we have two connections
    ConnectionSet connectionSet = {
        std::make_shared<Connection>(),
        std::make_shared<Connection>()
    };

    bool doneConnections = false;

    while (!doneConnections) {
        for (auto connection : connectionSet) {
            if (connection->hasIncomingData()) {
                DataPacket data = connection->incoming();
                std::promise<PayloadType>& p = connection->getPromise(data.id);
                p.set_value(data.payload);
            }
            if (connection->hasOutgoingData()) {
                OutgoingPacket data = connection->topOfOutgoingQueue();
                connection->send(data.payload);
                data.promise.set_value(true);
            }
        }
        doneConnections = true;
    }

    return 0;
}

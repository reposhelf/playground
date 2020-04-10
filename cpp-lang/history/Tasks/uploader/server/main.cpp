#include "sslserver.h"

#include <QCoreApplication>

#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if (argc < 3)
    {
        std::cerr << "usage: server <port> <dir_to_save>" << std::endl;
        return -1;
    }

    SslServer server(std::atoi(argv[1]), argv[2]);
    server.startServer();

    return a.exec();
}

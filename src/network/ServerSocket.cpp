//
// Created by mletemple on 18/03/23.
//

#include "ServerSocket.h"
#include "ClientSocket.h"
#include "CacheManager.h"

ServerSocket::ServerSocket(QObject *parent) : QTcpServer(parent) {
}

void ServerSocket::incomingConnection(qintptr socketDescriptor) {
    cout << "ServerSocket::incomingConnection() called" << endl;

    ClientSocket *clientSocket = new ClientSocket(socketDescriptor, this);
    connect(clientSocket, SIGNAL(finished()), clientSocket, SLOT(deleteLater()));

    clientSocket->start();

    cacheManager = CacheManager();

    cout << "ServerSocket::incomingConnection() finished" << endl;
}

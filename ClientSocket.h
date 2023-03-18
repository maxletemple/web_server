//
// Created by mletemple on 18/03/23.
//

#ifndef WEB_SERVER_CLIENTSOCKET_H
#define WEB_SERVER_CLIENTSOCKET_H


#include <QTcpSocket>
#include <QThread>
#include <QtNetwork>
#include <QFile>
#include <QDir>
#include <iostream>
using namespace std;

class ClientSocket : public QThread{
    Q_OBJECT;

public:
    ClientSocket(int socketDescriptor, QObject *parent);

    void run();
signals:
    void error(QTcpSocket::SocketError socketError);

private:
    int socketDescriptor;
};


#endif //WEB_SERVER_CLIENTSOCKET_H

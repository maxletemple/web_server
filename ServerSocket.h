//
// Created by mletemple on 18/03/23.
//

#ifndef WEB_SERVER_SERVERSOCKET_H
#define WEB_SERVER_SERVERSOCKET_H

#include <QTcpServer>

class ServerSocket : public QTcpServer{
    Q_OBJECT;

public:
    ServerSocket(QObject *parent = 0);

protected:
    void incomingConnection(qintptr socketDescriptor);
};


#endif //WEB_SERVER_SERVERSOCKET_H

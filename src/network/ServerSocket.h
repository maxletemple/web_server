//
// Created by mletemple on 18/03/23.
//

#ifndef WEB_SERVER_SERVERSOCKET_H
#define WEB_SERVER_SERVERSOCKET_H

#include <QTcpServer>
#include "CacheManager.h"


class ServerSocket : public QTcpServer{
    Q_OBJECT;

public:

    static CacheManager cacheManager;
    ServerSocket(QObject *parent = 0);

protected:
    void incomingConnection(qintptr socketDescriptor);
};


#endif //WEB_SERVER_SERVERSOCKET_H

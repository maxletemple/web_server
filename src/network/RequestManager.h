//
// Created by mletemple on 21/03/23.
//

#ifndef WEB_SERVER_REQUESTMANAGER_H
#define WEB_SERVER_REQUESTMANAGER_H

#include <QtCore>
#include <QtNetwork>

class RequestManager {
private:


public:
    RequestManager();
    QByteArray getResponse(QString request, QHostAddress ip);
};


#endif //WEB_SERVER_REQUESTMANAGER_H

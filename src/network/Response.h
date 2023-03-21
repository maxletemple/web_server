//
// Created by mletemple on 21/03/23.
//

#ifndef WEB_SERVER_RESPONSE_H
#define WEB_SERVER_RESPONSE_H


#include <QtCore>

class Response {
protected:
    QByteArray content;
    QString mimeType;
    int lastUsed;

protected:
    Response(QString mimeType, QByteArray content);

public:
    virtual bool isCachable();

    Response();
};


#endif //WEB_SERVER_RESPONSE_H

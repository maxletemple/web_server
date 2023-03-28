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
    QString path;
    int lastUsed;

protected:
    Response(QString mimeType, QString path);

public:
    virtual bool isCachable();
    virtual bool isScript();
    QString getPath();
    QByteArray getContent();
    QString getMimeType();
    Response();
};


#endif //WEB_SERVER_RESPONSE_H

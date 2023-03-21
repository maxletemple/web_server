//
// Created by mletemple on 21/03/23.
//

#ifndef WEB_SERVER_CACHEMANAGER_H
#define WEB_SERVER_CACHEMANAGER_H

#include <QtCore>
#include "Response.h"
#define CACHE_SIZE 100

class CacheManager {
private:
    QMap<QString, Response> cache;
    QVector<QString> cacheOrder;
public:
    CacheManager();
    Response getFromCache(QString path);
    void addToCache(QString path, Response response);
};


#endif //WEB_SERVER_CACHEMANAGER_H

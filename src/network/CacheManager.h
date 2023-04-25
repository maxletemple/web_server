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
    QMap<QString, int> cacheHits;
public:
    CacheManager();
    Response getFromCache(QString path);
    void addToCache(Response response);
    bool isInCache(QString path);
    QString getHTMLCacheStats();

    static CacheManager& getInstance() {
        static CacheManager instance;
        return instance;
    }

    int getCacheSize();

    void clear();
};

#endif //WEB_SERVER_CACHEMANAGER_H

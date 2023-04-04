//
// Created by mletemple on 21/03/23.
//

#include "CacheManager.h"

CacheManager::CacheManager() {
    this->cache = QMap<QString, Response>();
    this->cacheOrder = QVector<QString>();
}

Response CacheManager::getFromCache(QString path) {
    return this->cache.value(path);
}

void CacheManager::addToCache(Response response) {
    if (this->cache.size() >= CACHE_SIZE) {
        this->cache.remove(this->cacheOrder.first());
        this->cacheOrder.removeFirst();
    }
    this->cache.insert(response.getPath(), response);
    this->cacheOrder.append(response.getPath());

}

bool CacheManager::isInCache(QString path) {
    return this->cache.contains(path);
}

//
// Created by mletemple on 21/03/23.
//

#include "CacheManager.h"

CacheManager::CacheManager() {
    this->cache = QMap<QString, Response>();
}

Response CacheManager::getFromCache(QString path) {
    return this->cache.value(path);
}

void CacheManager::addToCache(QString path, Response response) {
    if (this->cache.size() >= CACHE_SIZE) {
        // Remove oldest item
        this->cache.remove(this->cacheOrder.first());
        this->cacheOrder.removeFirst();
    }
    if (this->cacheOrder.contains(path)) {
        this->cacheOrder.removeOne(path);
    }
    this->cache.insert(path, response);
    this->cacheOrder.append(path);
}

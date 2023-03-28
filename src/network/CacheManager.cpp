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
        this->cache.remove(this->cacheOrder.first());
        this->cacheOrder.removeFirst();
    }

}

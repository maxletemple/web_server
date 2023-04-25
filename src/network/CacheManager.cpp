//
// Created by mletemple on 21/03/23.
//

#include <iostream>
#include "CacheManager.h"

CacheManager::CacheManager() {
    this->cache = QMap<QString, Response>();
    this->cacheOrder = QVector<QString>();
    this->cacheHits = QMap<QString, int>();
}

Response CacheManager::getFromCache(QString path) {
    cacheHits[path] += 1;
    return this->cache.value(path);
}

void CacheManager::addToCache(Response response) {
    if (this->cache.size() >= CACHE_SIZE) {
        this->cache.remove(this->cacheOrder.first());
        this->cacheOrder.removeFirst();
    }
    this->cache.insert(response.getPath().normalized(QString::NormalizationForm_D), response);
    this->cacheOrder.append(response.getPath());
    qDebug() << "Added " << response.getPath() << " to cache";
}

bool CacheManager::isInCache(QString path) {
    path = path.normalized(QString::NormalizationForm_D);
    qDebug() << path << " is in cache: " << this->cacheOrder.contains(path);
    return this->cacheOrder.contains(path);
}

int CacheManager::getCacheSize() {
    return this->cacheOrder.size();
}

void CacheManager::clear() {
    this->cacheOrder.clear();
    this->cache.clear();
    this->cacheHits.clear();
}

QString CacheManager::getHTMLCacheStats() {
    QString html = "<table><tr><th>File</th><th>Times Accessed</th><th>Size</th></tr>";
    for (QString path : this->cacheOrder) {
        html += "<tr><td>" + path + "</td><td>" + QString::number(this->cacheHits[path]) + "</td><td>" + QString::number(this->cache[path].getContent().size()) + "</td></tr>";
    }
    html += "</table>";
    return html;
}

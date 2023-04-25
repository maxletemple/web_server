//
// Created by mletemple on 11/04/23.
//

#include "RespStats.h"
#include "iostream"
#include "CacheManager.h"dex.html

RespStats::RespStats() : RespFile(QString("./private/statistics.html"))
{
    QString temp = QString(this->content);
    temp.replace("$date", __DATE__);
    temp.replace("$time", __TIME__);

    temp.replace("$cacheSize", QString::number(CacheManager::getInstance().getCacheSize()));

    temp.replace("$cacheFiles", CacheManager::getInstance().getHTMLCacheStats());

    temp.replace("$nbRequestsRx", QString::number(Statistics::getInstance().getNbRequestsRx()));
    temp.replace("$nbRequestsTx", QString::number(Statistics::getInstance().getNbRequestsTx()));
    temp.replace("$nb404", QString::number(Statistics::getInstance().getNb404()));
    temp.replace("$nb403", QString::number(Statistics::getInstance().getNb403()));
    temp.replace("$nbBytesRx", QString::number(Statistics::getInstance().getNbBytesRx()));
    temp.replace("$nbBytesTx", QString::number(Statistics::getInstance().getNbBytesTx()));

    QString filesDl = "";
    QMap<QString, int> files = Statistics::getInstance().getFilesDl();
    for (QMap<QString, int>::iterator it = files.begin(); it != files.end(); it++) {
        filesDl += "<tr><td>" + it.key() + ":      </td><td>" + QString::number(it.value()) + "</td></tr><br>";
    }
    temp.replace("$filesDl", filesDl);

    QString requests = "";
    QVector<QString> req = Statistics::getInstance().getRequests();
    for (QVector<QString>::iterator it = req.begin(); it != req.end(); it++) {
        requests += "<tr><td>" + *it + "</td></tr><br>";
    }
    temp.replace("$requests", requests);

    QString clients = "";
    QMap<QString, int> cl = Statistics::getInstance().getClients();
    for (QMap<QString, int>::iterator it = cl.begin(); it != cl.end(); it++) {
        clients += "<tr><td>" + it.key() + ":      </td><td>" + QString::number(it.value()) + "</td></tr><br>";
    }
    temp.replace("$clients", clients);


    this->content = temp.toUtf8();
    this->cachable = false;
}

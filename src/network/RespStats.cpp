//
// Created by mletemple on 11/04/23.
//

#include "RespStats.h"
#include "iostream"

RespStats::RespStats() : RespFile(QString("./private/statistics.html"))
{
    QString temp = QString(this->content);
    temp.replace("$nbRequestsRx", QString::number(Statistics::getInstance().getNbRequestsRx()));
    this->content = temp.toUtf8();
}

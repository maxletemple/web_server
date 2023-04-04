//
// Created by mletemple on 04/04/23.
//

#include "RespScript.h"

RespScript::RespScript(QString path) : Response("text/html", path) {
    QProcess process;
    process.start(path, QStringList(), QIODevice::ReadWrite);
    process.waitForFinished();
    this->content = process.readAllStandardOutput();
    process.close();
}

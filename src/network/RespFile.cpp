//
// Created by mletemple on 21/03/23.
//

#include "RespFile.h"


bool RespFile::isCachable() {
    return true;
}

RespFile::RespFile(QString mimeType, QString path) : Response(mimeType, path) {
    QFile* file = new QFile( path );
     if (!file->open(QIODevice::ReadOnly))
     {
             delete file;
             return;
     }
    this->content = file->readAll();
    file->close();
}

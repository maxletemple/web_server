//
// Created by mletemple on 21/03/23.
//

#include <iostream>
#include "RespFile.h"

RespFile::RespFile(QString path) : Response(path) {
    QFile* file = new QFile( path );
     if (!file->open(QIODevice::ReadOnly))
     {
             delete file;
             return;
     }
    this->content = file->readAll();
    file->close();
    std::cout << "Loaded " << path.toStdString() << " from disk" << std::endl;
    this->cachable = true;
}

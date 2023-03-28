//
// Created by mletemple on 21/03/23.
//

#include "RespDir.h"


RespDir::RespDir(QString path) : Response("text/html", path) {
    QString cont("<html><head><title>Content of ");
    cont += path;
    cont += "</title></head><body><ul>";

    QDir dir = QDir(path);
    QStringList files = dir.entryList();
    for (int i = 0; i < files.size(); i++){
        cont += "<li>";
        cont += files[i];
        cont += "</li>";
    }
    cont += "</ul></body></html>";

    this->content = cont.toUtf8();
}


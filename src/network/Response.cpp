//
// Created by mletemple on 21/03/23.
//

#include "Response.h"


bool Response::isCachable() {
    return false;
}

bool Response::isScript() {
    return false;
}

QString Response::getPath(){
    return this->path;
}

QString Response::getMimeType(){
    return this->mimeType;
}

QByteArray Response::getContent(){
    return this->content;
}

Response::Response() {
    this->mimeType = "text/plain";
    this->path = "none";
}

Response::Response(QString mimeType, QString path) {
    this->mimeType = mimeType;
    this->path = path;
}

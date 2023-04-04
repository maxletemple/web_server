//
// Created by mletemple on 21/03/23.
//

#include "Response.h"

inline QString findMimeType(QString path){
    if (path.endsWith(".html") || path.endsWith(".htm"))
        return "text/html";
    else if (path.endsWith(".css"))
        return "text/css";
    else if (path.endsWith(".js"))
        return "text/javascript";
    else if (path.endsWith(".png"))
        return "image/png";
    else if (path.endsWith(".jpg") || path.endsWith(".jpeg"))
        return "image/jpeg";
    return "text/plain";
}

bool Response::isCachable() {
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

Response::Response(QString path) {
    this->mimeType = findMimeType(path);
    this->path = path;
}

Response::Response(QString mimeType, QString path) {
    this->mimeType = mimeType;
    this->path = path;
}

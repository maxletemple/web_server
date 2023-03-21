//
// Created by mletemple on 21/03/23.
//

#include "Response.h"


bool Response::isCachable() {
    return false;
}

Response::Response() {
    this->mimeType = "text/plain";
    this->content = "none";
}

Response::Response(QString mimeType, QByteArray content) {
    this->mimeType = mimeType;
    this->content = content;
}
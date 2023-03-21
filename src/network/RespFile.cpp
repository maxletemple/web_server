//
// Created by mletemple on 21/03/23.
//

#include "RespFile.h"


bool RespFile::isCachable() {
    return true;
}

RespFile::RespFile(QString mimeType, QByteArray content) : Response(mimeType, content) {

}

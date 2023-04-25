//
// Created by mletemple on 25/04/23.
//

#include "Resp503.h"

Resp503::Resp503() : RespFile("./public_html/error/503.html") {
    this->cachable = false;
}

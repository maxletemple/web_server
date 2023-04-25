//
// Created by mletemple on 04/04/23.
//

#include "Resp404.h"
#include "Statistics.h"

Resp404::Resp404() : RespFile(QString("./public_html/error/404.html")) {
    Statistics::getInstance().new404();
    this->cachable = false;
}

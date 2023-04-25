//
// Created by mletemple on 11/04/23.
//

#include "Resp403.h"
#include "Statistics.h"

Resp403::Resp403() : RespFile(QString("./public_html/error/403.html")){
    Statistics::getInstance().new403();
}

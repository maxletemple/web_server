//
// Created by mletemple on 21/03/23.
//

#ifndef WEB_SERVER_RESPFILE_H
#define WEB_SERVER_RESPFILE_H


#include "Response.h"

class RespFile : public Response{
public:
    RespFile(QString path);
    virtual bool isCachable();
};


#endif //WEB_SERVER_RESPFILE_H

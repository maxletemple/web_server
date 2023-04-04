//
// Created by mletemple on 21/03/23.
//

#include "RequestManager.h"
#include  <iostream>
#include "Response.h"
#include "RespDir.h"
#include "RespFile.h"
#include "Resp404.h"
#include "CacheManager.h"
#include "RespScript.h"
#include "Statistics.h"

using namespace std;

RequestManager::RequestManager() {

}

inline bool isScript(QString path){
    QFileInfo fileInfo(path);
    return fileInfo.isExecutable();
}

QByteArray RequestManager::getResponse(QString request) {
    request = request.trimmed();
    QStringList requestParts = request.split(" ");

    cout << "Method : " << requestParts[0].toStdString() << endl;
    cout << "Path   : " << requestParts[1].toStdString() << endl;
    cout << "HTTP   : " << requestParts[2].toStdString() << endl;

    Response response;
    QString path = "./public_html" + requestParts[1];
    if (cacheManager.isInCache(path)){
        response = cacheManager.getFromCache(path);
        cout << path.toStdString() <<"is already in cache" << endl;
    } else{
        QFile f(path);
        QDir d(path);

        cout << " - Chemin du fichier : " << path.toStdString() << endl;
        cout << " - isFile :          : " << f.exists() << endl;
        cout << " - isDirectory       : " << d.exists() << endl;


        if (!f.exists() && !d.exists()){
            response = Resp404();
        } else if (d.exists()){
            response = RespDir(path);
        } else if (f.exists()){
            if (isScript(path)) {
                response = RespScript(path);
            } else {
                response = RespFile(path);
            }
        }
        if (response.isCachable()) {
            cacheManager.addToCache(response);
        }
    }

    QString head = "HTTP/1.1 200 OK\r\n"
                   "Content-Type: " + response.getMimeType() + ";charset=UTF-8\r\n"
                          "\r\n";

    QByteArray ret = QByteArray().append(head.toUtf8());
    ret.append(response.getContent());
    statistics.newRequestTx(ret);
    statistics.newFileDl(response);
    return ret;
}



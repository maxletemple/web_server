//
// Created by mletemple on 21/03/23.
//

#include "RequestManager.h"
#include  <iostream>
#include "Response.h"
#include "RespDir.h"
#include "RespFile.h"
#include "Resp404.h"
#include "RespStats.h"
#include "CacheManager.h"
#include "RespScript.h"
#include "Statistics.h"
#include "QHostAddress"
#include "Resp403.h"

using namespace std;

RequestManager::RequestManager() {

}

inline bool isScript(QString path){
    QFileInfo fileInfo(path);
    return fileInfo.isExecutable();
}

QByteArray RequestManager::getResponse(QString request, QHostAddress ip) {
    request = request.trimmed();
    QStringList requestParts = request.split(" ");

    cout << "Method : " << requestParts[0].toStdString() << endl;
    cout << "Path   : " << requestParts[1].toStdString() << endl;
    cout << "HTTP   : " << requestParts[2].toStdString() << endl;

    Response response;

    QString path;
    if (requestParts[1].startsWith("/private")) {
        if (ip == QHostAddress::LocalHostIPv6) {
            path = "." + requestParts[1];
        } else {
            response = Resp403();
        }
    } else {
        path = "./public_html" + requestParts[1];
    }
    if (CacheManager::getInstance().isInCache(path)) {
        response = CacheManager::getInstance().getFromCache(path);
        cout << path.toStdString() << "is already in cache" << endl;
    } else {
        if (typeid(response) != typeid(Resp403))
        {
            QFile f(path);
            QDir d(path);

            cout << " - Chemin du fichier : " << path.toStdString() << endl;
            cout << " - isFile :          : " << f.exists() << endl;
            cout << " - isDirectory       : " << d.exists() << endl;

            if (!f.exists() && !d.exists()) {
                response = Resp404();
            } else if (d.exists()) {
                response = RespDir(path);
            } else if (f.exists()) {
                if (isScript(path)) {
                    response = RespScript(path);
                } else if (path == "./private/statistics.html")
                {
                    response = RespStats();
                }
                else {
                    response = RespFile(path);
                }
            }
        }
    }
    if (response.isCachable()) {
        CacheManager::getInstance().addToCache(response);
    }
    QString head = "HTTP/1.1 200 OK\r\n"
                   "Content-Type: " + response.getMimeType() + ";charset=UTF-8\r\n"
                                                               "\r\n";
    QByteArray ret = QByteArray().append(head.toUtf8());
    ret.append(response.getContent());
    Statistics::getInstance().newRequestTx(ret);
    Statistics::getInstance().newFileDl(response);
    return ret;
}


//
// Created by mletemple on 21/03/23.
//

#include "RequestManager.h"
#include  <iostream>
#include "ServerSocket.h"
#include "Response.h"
#include "RespDir.h"
#include "RespFile.h"

using namespace std;

extern CacheManager ServerSocket::cacheManager;

RequestManager::RequestManager() {

}

inline QString findMimeType(QString path){
    return "text/html";
}

QByteArray RequestManager::getResponse(QString request) {
    request = request.trimmed();
    QStringList requestParts = request.split(" ");

    cout << "Method : " << requestParts[0].toStdString() << endl;
    cout << "Path   : " << requestParts[1].toStdString() << endl;
    cout << "HTTP   : " << requestParts[2].toStdString() << endl;

    Response response;
    QString path = "./public.html" + requestParts[1];
    if (cacheManager.isInCache(path)){
        response = cacheManager.getFromCache(path);
    } else{
        QFile f(path);
        QDir d(path);

        cout << " - Chemin du fichier : " << path.toStdString() << endl;
        cout << " - isFile :          : " << f.exists() << endl;
        cout << " - isDirectory       : " << d.exists() << endl;


        if (!f.exists() && !d.exists()){
            // CHARGER ERREUR 404
        } else if (d.exists()){
            response = RespDir(path);
        } else if (f.exists()){
            QString fileMimetype = findMimeType(path);
            response = RespFile(fileMimeType, path);
        }

        cacheManager.addToCache(response);
    }

    QString head = "HTTP/1.1 200 OK\r\n"
                   "Content-Type: " + response.getMimeType() + ";charset=UTF-8\r\n"
                          "\r\n";

    QByteArray ret = QByteArray(head);
    ret.append(response.getContent());

    return ret;
}



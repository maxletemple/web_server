//
// Created by mletemple on 21/03/23.
//

#include "RequestManager.h"
#include  <iostream>
using namespace std;

RequestManager::RequestManager() {

}

QByteArray RequestManager::getResponse(QString request) {
    request = request.trimmed();
    QStringList requestParts = request.split(" ");

    cout << "Method : " << requestParts[0].toStdString() << endl;
    cout << "Path   : " << requestParts[1].toStdString() << endl;
    cout << "HTTP   : " << requestParts[2].toStdString() << endl;

    QString response = "HTTP/1.1 200 OK\r\n"
                       "Content-Type: text/html\r\n"
                       "Content-Length: 12\r\n"
                       "\r\n"
                       "Hello World!";
    return response.toUtf8();
}

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



    return QByteArray();
}

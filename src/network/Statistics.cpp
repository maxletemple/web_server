//
// Created by mletemple on 04/04/23.
//

#include "Statistics.h"
#include "Resp404.h"
#include "RespDir.h"
#include "iostream"

int Statistics::getNbRequestsRx() {
    return nbRequestsRx;
}

int Statistics::getNbRequestsTx() {
    return nbRequestsTx;
}

int Statistics::getNb404() {
    return nb404;
}

int Statistics::getNbBytesRx() {
    return nbBytesRx;
}

int Statistics::getNbBytesTx() {

    return nbBytesTx;
}

void Statistics::newRequestRx(QString ip, QString buffer) {
    nbRequestsRx++;
    nbBytesRx += buffer.size()*sizeof(char);
    requests.append(buffer);
    if (clients.contains(ip)) {
        clients.insert(ip, clients.value(ip) + 1);
    } else {
        clients.insert(ip, 1);
    }

}

void Statistics::newRequestTx(QByteArray content) {
    nbRequestsTx++;
    nbBytesTx += content.size()*sizeof(char);
}

void Statistics::newFileDl(Response* response) {
    if (typeid(*response) != typeid(RespDir)) {
        if (filesDl.contains(response->getPath())) {
            filesDl.insert(response->getPath(), filesDl.value(response->getPath()) + 1);
        } else {
            filesDl.insert(response->getPath(), 1);
        }
    }
}

Statistics::Statistics() {
    std::cout << "Statistics created" << std::endl;
    nbRequestsRx = 0;
    nbRequestsTx = 0;
    nb404 = 0;
    nb403 = 0;
    nbBytesRx = 0;
    nbBytesTx = 0;
    filesDl = QMap<QString, int>();
    requests = QVector<QString>();
    clients = QMap<QString, int>();
    enableServ = true;
}

void Statistics::new404() {
    nb404++;
}

void Statistics::new403() {
    nb403++;
}

int Statistics::getNb403() {
    return nb403;
}

QMap<QString, int> Statistics::getFilesDl() {
    return filesDl;
}

QVector<QString> Statistics::getRequests() {
    return requests;
}

QMap<QString, int> Statistics::getClients() {
    return clients;
}

bool Statistics::isEnableServ() const {
    return enableServ;
}

void Statistics::setEnableServ(bool enableServ) {
    Statistics::enableServ = enableServ;
}

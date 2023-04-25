//
// Created by mletemple on 04/04/23.
//

#ifndef WEB_SERVER_STATISTICS_H
#define WEB_SERVER_STATISTICS_H


#include <QMap>
#include "Response.h"

class Statistics {
private:
    int nbRequestsRx;
    int nbRequestsTx;
    int nb404;
    int nb403;
    int nbBytesRx;
    int nbBytesTx;
    QMap<QString, int> filesDl;
    QVector<QString> requests;
    QMap<QString, int> clients;

    bool enableServ;
public:
    Statistics();
    int getNbRequestsRx();
    int getNbRequestsTx();
    int getNb404();
    int getNbBytesRx();
    int getNbBytesTx();
    QMap<QString, int> getFilesDl();
    bool isEnableServ() const;
    void setEnableServ(bool enableServ);

    void newRequestRx(QString ip, QString buffer);
    void newRequestTx(QByteArray content);
    void newFileDl(Response* response);
    void new404();
    void new403();
    static Statistics& getInstance() {
        static Statistics instance;
        return instance;
    }

    int getNb403();

    QVector<QString> getRequests();

    QMap<QString, int> getClients();
};


#endif //WEB_SERVER_STATISTICS_H

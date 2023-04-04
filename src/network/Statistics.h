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
    int nbBytesRx;
    int nbBytesTx;
    QMap<QString, int> filesDl;
    QVector<QString> requests;
    QMap<QString, int> clients;

public:
    Statistics();
    int getNbRequestsRx();
    int getNbRequestsTx();
    int getNb404();
    int getNbBytesRx();
    int getNbBytesTx();

    void newRequestRx(QString ip, QString buffer);
    void newRequestTx(QByteArray content);
    void newFileDl(Response response);

};

static Statistics statistics;

#endif //WEB_SERVER_STATISTICS_H

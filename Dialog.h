//
// Created by mletemple on 18/03/23.
//

#ifndef WEB_SERVER_DIALOG_H
#define WEB_SERVER_DIALOG_H


#include <QDialog>
#include <QLabel>
#include "ServerSocket.h"

class Dialog : public QDialog{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);

private:
    QLabel *statusLabel;
    QPushButton *quitButton;

    ServerSocket server;
};


#endif //WEB_SERVER_DIALOG_H

//
// Created by mletemple on 18/03/23.
//

#include <QTcpSocket>
#include <QtNetwork>
#include "ClientSocket.h"
#include "iostream"
ClientSocket::ClientSocket(int socketDescriptor, QObject *parent) : QThread(parent), socketDescriptor(socketDescriptor){
}

inline string removeEndLine(string s){
    while( s.at(s.length()-1) == '\r' ||
           s.at(s.length()-1) == '\n' ){
        s = s.substr(0, s.length()-1);
    }
    return s;
}

void ClientSocket::run(){
    cout << "ClientSocket::run() called" << endl;
    QTcpSocket tcpSocket;

    if(!tcpSocket.setSocketDescriptor(socketDescriptor)){
        emit error(tcpSocket.error());
        return;
    }

    while (tcpSocket.bytesAvailable() < (int)sizeof(quint16)) {
        if (!tcpSocket.waitForReadyRead(1000)) {
            cout << "Error: timeout" << endl;
            return;
        }
    }

    char buffer[65536];
    tcpSocket.readLine(buffer, sizeof(buffer));

    string line(buffer);
    line = removeEndLine(line);

    cout << "COMMAND: " << line << "<=" << endl;

    int pos1 = line.find(" ");
    string command = line.substr(0, pos1);
    line = line.substr(pos1+1, line.length()-pos1);

    cout << "1. : " << command << endl;
    cout << "2. : " << line << endl;

    int pos2 = line.find(" ");
    string path = line.substr(0, pos2);
    line = line.substr(pos2+1, line.length()-pos2);

    cout << "3. : " << path << endl;
    cout << "4. : " << line << endl;

    while( tcpSocket.bytesAvailable() > 0 ) {
        int lineLength = tcpSocket.readLine(buffer, 65536);
        if (lineLength != -1 && lineLength != 0) {
            //cout << "C" << lineLength << " :: " << tampon;
        } else if (lineLength != -1) {
            cout << "Nothing for the moment !" << endl;
        }
    }
    QString str = tr("./public_html") + tr(path.c_str());
    QFile file(str);
    QDir dir(str);

    cout << "Path  : " << str.toStdString() << endl;
    cout << "isFile: " << file.exists() << endl;
    cout << "isDir : " << dir.exists() << endl;

    if (!file.exists() && !dir.exists()) {
        tcpSocket.write("HTTP/1.1 404 Not Found\r\n");
        tcpSocket.write("Content-Type: text/html\r\n");
        tcpSocket.write("\r\n");
        tcpSocket.write("<html><body><h1>404 Not Found</h1></body></html>\r\n");
    } else if (dir.exists()){
        //List directory

    } else if (file.exists()){
        //Send file

        if (file.open(QIODevice::ReadOnly)) {
            tcpSocket.write("HTTP/1.1 200 OK\r\n");
            tcpSocket.write("Content-Type: text/html\r\n");
            tcpSocket.write("\r\n");
            tcpSocket.write(file.readAll());
        } else {
            tcpSocket.write("HTTP/1.1 500 Internal Server Error\r\n");
            tcpSocket.write("Content-Type: text/html\r\n");
            tcpSocket.write("\r\n");
            tcpSocket.write("<html><body><h1>500 Internal Server Error</h1></body></html>\r\n");
        }

        file.close();
    }

    tcpSocket.disconnectFromHost();
    tcpSocket.waitForDisconnected();
    cout << "ClientSocket::run() finished" << endl;
}
#include <QApplication>
#include <QPushButton>
#include "Dialog.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Dialog dialog;
    dialog.show();
    return dialog.exec();
}

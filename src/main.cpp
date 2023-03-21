#include <QApplication>
#include <QPushButton>
#include "Dialog.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Dialog dialog;
    dialog.show();

    return dialog.exec();
}

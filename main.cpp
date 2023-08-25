#include <QApplication>
#include "InterfacciaQt.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    InterfacciaQt interfaccia;
    interfaccia.show();

    return app.exec();
}

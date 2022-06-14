#include <QApplication>
#include <QPushButton>
#include "window.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}

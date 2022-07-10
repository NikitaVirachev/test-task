#include "mainwindow.h"
#include "tests.h"

#include <QApplication>
#include <QtTest/QTest>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QTest::qExec(new Tests, argc, argv);
    return a.exec();
}

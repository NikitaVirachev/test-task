#ifndef TESTS_H
#define TESTS_H

#include <QObject>
#include <QtTest/QTest>

#include "caesarcipher.h"
#include "diffiehellmanprotocol.h"

class Tests : public QObject
{
    Q_OBJECT
public:
    explicit Tests(QObject *parent = nullptr);

signals:

private slots:
    void testEncryption();
    void testDecryption();
    void testExponentiation();
};

#endif // TESTS_H

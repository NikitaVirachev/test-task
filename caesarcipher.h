#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include <QString>
#include <QDebug>

class caesarCipher
{
public:
    caesarCipher(QString, QString);
    QString encryption(QString, int);
    QString decryption(QString, int);
private:
    QString alphabet;
    QString alphabet_upper;
};

#endif // CAESARCIPHER_H

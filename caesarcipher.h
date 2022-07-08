#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include <QString>
#include <QDebug>

class caesarCipher
{
public:
    caesarCipher(QString, QString, int);
    QString encryption(QString);
    QString decryption(QString);
private:
    QString alphabet;
    QString alphabet_upper;
    int step;
};

#endif // CAESARCIPHER_H

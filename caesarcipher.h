#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include <QString>
#include <QDebug>

class caesarCipher
{
public:
    caesarCipher(QString alphabet, QString alphabet_upper);
    QString encryption(QString text, int key);
    QString decryption(QString text, int key);
private:
    QString alphabet;
    QString alphabet_upper;
};

#endif // CAESARCIPHER_H

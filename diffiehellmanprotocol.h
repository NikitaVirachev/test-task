#ifndef DIFFIEHELLMANPROTOCOL_H
#define DIFFIEHELLMANPROTOCOL_H

#include <QString>
#include <QDebug>
#include <cmath>

class DiffieHellmanProtocol
{
public:
    DiffieHellmanProtocol();
    QString exponentiation(int base, int degree, int divider);
};

#endif // DIFFIEHELLMANPROTOCOL_H

#include "diffiehellmanprotocol.h"

QString DiffieHellmanProtocol::exponentiation(int base, int degree, int divider)
{
    int n = 0;
    QList<int> *binary = new QList<int>;

    while(degree >= 1)
    {
        binary->insert(n, degree % 2);
        degree /= 2;
        n++;
    }

    QList<int> *arr = new QList<int>;
    arr->insert(0, base);
    for(int i = 1; i < n; i++ ) {
        arr->insert(i, (arr->at(i-1) * arr->at(i-1)) % divider);
    }

    unsigned long long multi = 1;
    for(int i = 0; i < n; i++) {
        if (binary->at(i) > 0){
            multi *= arr->at(i);
        }
    }

    delete binary;
    delete arr;

    return QString::number(multi % divider);
}

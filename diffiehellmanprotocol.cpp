#include "diffiehellmanprotocol.h"

DiffieHellmanProtocol::DiffieHellmanProtocol()
{

}

QString DiffieHellmanProtocol::exponentiation(int base, int degree, int divider)
{
    int i = 0;
    int *binary = new int[30];
    while(degree >= 1)
    {
        binary[i] = degree % 2;
        degree /= 2;
        i++;
    }
    int n = i;

    int *arr = new int[n];
    arr[0] = base;
    for(int i = 1; i < n; i++ ) {
        arr[i] = (arr[i-1] * arr[i-1]) % divider;
    }
    int multi = 1;
    for(int j = 0; j < n; j++) {
        if (binary[j] > 0){
            multi*= binary[j] * arr[j];
        }
    }

    delete [] binary;
    delete [] arr;

    return QString::number(multi % divider);
}

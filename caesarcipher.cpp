#include "caesarcipher.h"

caesarCipher::caesarCipher(QString alphabet, QString alphabet_upper)
{
    this->alphabet = alphabet;
    this->alphabet_upper = alphabet_upper;
}

QString caesarCipher::encryption(QString text, int key)
{
    QString result;

    foreach(QChar c, text)
    {
        if (alphabet.contains(c))
        {
            if (alphabet.indexOf(c) + key > alphabet.length() - 1)
            {
                result.append(alphabet[(alphabet.indexOf(c) + key) % alphabet.length()]);
            }
            else
            {
                result.append(alphabet[alphabet.indexOf(c) + key]);
            }
        }
        else if (alphabet_upper.contains(c))
        {
            if (alphabet_upper.indexOf(c) + key > alphabet.length() - 1)
            {
                result.append(alphabet_upper[(alphabet_upper.indexOf(c) + key) % alphabet_upper.length()]);
            }
            else
            {
                result.append(alphabet_upper[alphabet_upper.indexOf(c) + key]);
            }
        }
        else
        {
            result.append(c);
        }
    }

    return result;
}

QString caesarCipher::decryption(QString text, int key)
{
    QString result;

    foreach(QChar c, text)
    {
        if (alphabet.contains(c))
        {
            if (alphabet.indexOf(c) - key < 0)
            {
                result.append(alphabet[(alphabet.indexOf(c) - key) + alphabet.length()]);
            }
            else
            {
                result.append(alphabet[alphabet.indexOf(c) - key]);
            }
        }
        else if (alphabet_upper.contains(c))
        {
            if (alphabet_upper.indexOf(c) - key < 0)
            {
                result.append(alphabet_upper[(alphabet_upper.indexOf(c) - key) + alphabet_upper.length()]);
            }
            else
            {
                result.append(alphabet_upper[alphabet_upper.indexOf(c) - key]);
            }
        }
        else
        {
            result.append(c);
        }
    }

    return result;
}

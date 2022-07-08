#include "caesarcipher.h"

caesarCipher::caesarCipher(QString alphabet, QString alphabet_upper, int step)
{
    this->alphabet = alphabet;
    this->alphabet_upper = alphabet_upper;
    this->step = step;
}

QString caesarCipher::encryption(QString text)
{
    QString result;

    foreach(QChar c, text)
    {
        if (alphabet.contains(c))
        {
            if (alphabet.indexOf(c) + step > alphabet.length() - 1)
            {
                result.append(alphabet[(alphabet.indexOf(c) + step) % alphabet.length()]);
            }
            else
            {
                result.append(alphabet[alphabet.indexOf(c) + step]);
            }
        }
        else if (alphabet_upper.contains(c))
        {
            if (alphabet_upper.indexOf(c) + step > alphabet.length() - 1)
            {
                result.append(alphabet_upper[(alphabet_upper.indexOf(c) + step) % alphabet_upper.length()]);
            }
            else
            {
                result.append(alphabet_upper[alphabet_upper.indexOf(c) + step]);
            }
        }
        else
        {
            result.append(c);
        }
    }

    return result;
}

QString caesarCipher::decryption(QString text)
{
    QString result;

    foreach(QChar c, text)
    {
        if (alphabet.contains(c))
        {
            if (alphabet.indexOf(c) - step < 0)
            {
                result.append(alphabet[(alphabet.indexOf(c) - step) + alphabet.length()]);
            }
            else
            {
                result.append(alphabet[alphabet.indexOf(c) - step]);
            }
        }
        else if (alphabet_upper.contains(c))
        {
            if (alphabet_upper.indexOf(c) - step < 0)
            {
                result.append(alphabet_upper[(alphabet_upper.indexOf(c) - step) + alphabet_upper.length()]);
            }
            else
            {
                result.append(alphabet_upper[alphabet_upper.indexOf(c) - step]);
            }
        }
        else
        {
            result.append(c);
        }
    }

    return result;
}

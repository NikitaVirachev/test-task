#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include <QWidget>

namespace Ui {
class CaesarCipher;
}

class CaesarCipher : public QWidget
{
    Q_OBJECT

public:
    explicit CaesarCipher(QWidget *parent = nullptr);
    ~CaesarCipher();

private:
    Ui::CaesarCipher *ui;
};

#endif // CAESARCIPHER_H

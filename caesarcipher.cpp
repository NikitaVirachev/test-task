#include "caesarcipher.h"
#include "ui_caesarcipher.h"

CaesarCipher::CaesarCipher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaesarCipher)
{
    ui->setupUi(this);
}

CaesarCipher::~CaesarCipher()
{
    delete ui;
}

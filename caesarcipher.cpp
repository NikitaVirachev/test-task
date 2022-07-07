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

void CaesarCipher::readFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Выбрать файл"), "C:/Users/nikit/Desktop", tr("Текстовые файлы (*.txt)"));
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::warning(this, "Ошибка","Невозможно открыть файл");;

    QTextStream in(&file);

    data = QString(in.readAll().toLocal8Bit());
}

void CaesarCipher::on_pushButton_clicked()
{
    readFile();
    qDebug() << data;
}

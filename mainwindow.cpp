#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));

    ui->baseText->setEnabled(false);
    ui->encryption->setEnabled(false);
    ui->decryption->setEnabled(false);
    ui->lineEdit->setEnabled(false);
    ui->output_text->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::readFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Выбрать файл"), "C:/Users/nikit/Desktop", tr("Текстовые файлы (*.txt)"));
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::warning(this, "Ошибка","Невозможно открыть файл");

    QTextStream in(&file);

    return QString(in.readAll().toLocal8Bit());
}

bool MainWindow::isCyrillic(QString text)
{
    foreach(QChar c, text)
    {
        if (!(alphabet_upper.contains(c.toUpper()) || special_char.contains(c)))
        {
            return false;
        }
    }

    return true;
}

void MainWindow::on_pushButton_clicked()
{
    data = readFile();
    if (isCyrillic(data))
    {
        ui->baseText->setPlainText(data);
        ui->lineEdit->setEnabled(true);
        ui->encryption->setEnabled(true);
        ui->decryption->setEnabled(true);
    } else
    {
        data.clear();
        QMessageBox::warning(this, "Ошибка","В файле присутсвует не кириллический текст");
    }
}

void MainWindow::on_encryption_clicked()
{
    if (ui->lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Ошибка","Задайте сдвиг");
        return;
    }

    if (caesar == nullptr)
    {
        caesar = new caesarCipher(alphabet, alphabet_upper, ui->lineEdit->text().toInt());
    }

    ui->output_text->setPlainText(caesar->encryption(data));
}

void MainWindow::on_decryption_clicked()
{
    if (ui->lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Ошибка","Задайте сдвиг");
        return;
    }

    if (caesar == nullptr)
    {
        caesar = new caesarCipher(alphabet, alphabet_upper, ui->lineEdit->text().toInt());
    }

    ui->output_text->setPlainText(caesar->decryption(data));
}

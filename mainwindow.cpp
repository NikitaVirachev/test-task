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
    fileName = QFileDialog::getOpenFileName(this, tr("Выбрать файл"), "C:/Users/nikit/Desktop", tr("Текстовые файлы (*.txt)"));
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::warning(this, "Ошибка","Невозможно открыть файл");

    QString data = QString::fromUtf8(file.readAll());
    qDebug() << data;
    file.close();

    return data;
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

void MainWindow::writeInFile(QString text)
{
    QString directoryPath = fileName.mid(0, fileName.lastIndexOf('/'));
    directoryPath.append("/output.txt");

    QFile file(directoryPath);
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);

    QTextStream out(&file);
    out.setCodec("UTF-8");
    out << text;

    file.close();
}

void MainWindow::on_pushButton_clicked()
{
    data = readFile();
    if (isCyrillic(data))
    {
        ui->baseText->setPlainText(data);
        ui->lineEdit->setEnabled(true);
    } else
    {
        data.clear();
        QMessageBox::warning(this, "Ошибка","В файле присутсвует не кириллический текст");
    }
}

void MainWindow::on_encryption_clicked()
{
    if (caesar == nullptr)
    {
        caesar = new caesarCipher(alphabet, alphabet_upper);
    }

    writeInFile(caesar->encryption(data, ui->lineEdit->text().toInt()));

    ui->output_text->setPlainText(caesar->encryption(data, ui->lineEdit->text().toInt()));
}

void MainWindow::on_decryption_clicked()
{
    if (caesar == nullptr)
    {
        caesar = new caesarCipher(alphabet, alphabet_upper);
    }

    writeInFile(caesar->decryption(data, ui->lineEdit->text().toInt()));

    ui->output_text->setPlainText(caesar->decryption(data, ui->lineEdit->text().toInt()));
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    if (!ui->lineEdit->text().isEmpty())
    {
        ui->encryption->setEnabled(true);
        ui->decryption->setEnabled(true);
    }
    else
    {
        ui->encryption->setEnabled(false);
        ui->decryption->setEnabled(false);
    }
}

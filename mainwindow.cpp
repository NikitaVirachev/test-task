#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->lineEdit_3->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->lineEdit_5->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));

    ui->baseText->setEnabled(false);
    ui->encryption->setEnabled(false);
    ui->decryption->setEnabled(false);
    ui->lineEdit->setEnabled(false);
    ui->output_text->setEnabled(false);

    ui->lineEdit_2->setEnabled(false);
    ui->lineEdit_4->setEnabled(false);
    ui->lineEdit_6->setEnabled(false);
    ui->lineEdit_7->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::readFile()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Выбрать файл"), "C:/Users/nikit/Desktop", tr("Текстовые файлы (*.txt)"));
    QFile file(fileName);
    QString data = "";

    try {
        file.open(QIODevice::ReadOnly);
        data = QString::fromUtf8(file.readAll());
        file.close();
    } catch (const std::exception& ex) {
        qDebug() << ex.what();
        QMessageBox::warning(this, "Ошибка","Невозможно открыть файл");
    }

    return data;
}

bool MainWindow::isLatin(QString text)
{
    foreach(QChar c, text)
    {
        if (latin_upper.contains(c.toUpper()))
        {
            return true;
        }
    }

    return false;
}

void MainWindow::writeInFile(QString text)
{
    //файл вывода создаётся в той же директории, где и исходный файл
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
    ui->output_text->clear();

    data = readFile(); //читаем файл
    if (!isLatin(data)) //проверяем, не содержит ли он латиницу
    {
        //позволяем ввести шаг
        ui->baseText->setPlainText(data);
        ui->lineEdit->setEnabled(true);
    } else
    {
        data.clear();
        ui->baseText->clear();
        ui->lineEdit->clear();
        QMessageBox::warning(this, "Ошибка","В файле присутсвует латинский текст");
    }
}

void MainWindow::on_encryption_clicked()
{
    //создаём объект класса caesarCipher, если он ещё не существует
    if (caesar == nullptr)
    {
        caesar = new caesarCipher(alphabet, alphabet_upper);
    }

    //записываем в файл результаты шифрования
    writeInFile(caesar->encryption(data, ui->lineEdit->text().toInt()));

    ui->output_text->setPlainText(caesar->encryption(data, ui->lineEdit->text().toInt()));
}

void MainWindow::on_decryption_clicked()
{
    //создаём объект класса caesarCipher, если он ещё не существует
    if (caesar == nullptr)
    {
        caesar = new caesarCipher(alphabet, alphabet_upper);
    }

    //записываем в файл результаты шифрования
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

void MainWindow::on_pushButton_2_clicked()
{
    int g = ui->lineEdit_8->text().toInt();
    int p = ui->lineEdit_9->text().toInt();
    long int a = ui->lineEdit_3->text().toLong();
    long int b = ui->lineEdit_5->text().toLong();

    DiffieHellmanProtocol diffie_hellman;

    //метод exponentiation реализует формулу (a^b) mod c
    int A = diffie_hellman.exponentiation(g, a, p).toInt();
    int B = diffie_hellman.exponentiation(g, b, p).toInt();
    QString aliceK = diffie_hellman.exponentiation(B, a, p);
    QString bobK = diffie_hellman.exponentiation(A, b, p);

    ui->lineEdit_2->setEnabled(true);
    ui->lineEdit_4->setEnabled(true);
    ui->lineEdit_6->setEnabled(true);
    ui->lineEdit_7->setEnabled(true);

    ui->lineEdit_2->setText(QString::number(A));
    ui->lineEdit_6->setText(QString::number(B));
    ui->lineEdit_4->setText(aliceK);
    ui->lineEdit_7->setText(bobK);
}

void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
    if (!ui->lineEdit_3->text().isEmpty() && !ui->lineEdit_5->text().isEmpty())
    {
        ui->pushButton_2->setEnabled(true);
    }
    else
    {
        ui->pushButton_2->setEnabled(false);
    }
}

void MainWindow::on_lineEdit_5_textChanged(const QString &arg1)
{
    if (!ui->lineEdit_3->text().isEmpty() &&
        !ui->lineEdit_5->text().isEmpty() &&
        !ui->lineEdit_8->text().isEmpty() &&
        !ui->lineEdit_9->text().isEmpty())
    {
        ui->pushButton_2->setEnabled(true);
    }
    else
    {
        ui->pushButton_2->setEnabled(false);
    }
}

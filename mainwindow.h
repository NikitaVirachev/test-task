#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QString>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>

#include "caesarcipher.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString readFile();
    bool isCyrillic(QString);
    void writeInFile(QString);

    const QString alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    const QString alphabet_upper = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    const QString special_char = " ,.:;!?-+=/|\\`~'\"@#№$%^&*(){}[]0123456789";

    QString fileName;
    QString data;
    caesarCipher* caesar = nullptr;

private slots:
    void on_pushButton_clicked();

    void on_encryption_clicked();

    void on_decryption_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "caesarcipher.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    caesarCipher = new CaesarCipher();
    QHBoxLayout* caesarLayout = new QHBoxLayout();
    caesarLayout->addWidget(caesarCipher);
    ui->tabWidget->widget(0)->setLayout(caesarLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->tabWidget->setCurrentWidget(new CaesarCipher());
}

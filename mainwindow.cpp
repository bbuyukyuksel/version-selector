#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QProcess>
#include <stdio.h>
#include <stdlib.h>
#include <QKeyEvent>



static int line = 1;
static int selectedItem = -1;

void MainWindow::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_Escape)
        close();
    if(event->key() == Qt::Key_Return)
        ui->bt_create->click();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList<QString> options;
    options.append("Bash");
    options.append("Python - Test Program");

    ui->pool->addItems(options);

    int index = ui->pool->findText("");
    if ( index != -1 ) { // -1 for not found
       ui->pool->setCurrentIndex(index);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pool_currentIndexChanged(const QString &arg1)
{
    ui->label->setText(arg1);
    selectedItem = ui->pool->currentIndex();
}

void MainWindow::on_bt_create_clicked()
{
    QProcess inkex;
    QStringList args;
    QByteArray bytes;
    QString cmd = ui->cmd->text();

    inkex.setProcessChannelMode(QProcess::MergedChannels);
    inkex.start("/bin/bash",QIODevice::ReadWrite );
    inkex.waitForStarted();
    std::string x= ui->cmd->text().toStdString();

    const char *temp = x.c_str();


    inkex.write((const char*)temp);
    inkex.write("\n");
    inkex.write("exit\n");

    inkex.waitForFinished(100);
    inkex.waitForReadyRead();

    bytes.append(inkex.readAllStandardOutput());

    inkex.close();

    QString term_out = bytes.data();
//  qDebug() <<"SELAM" << term_out;
    QString __old = ui->output->text();
    QString __new = "#" + (QString::number(line++) + "<span style=color:red;> -> </span>" +
                          "<span style='color:silver;'>" + term_out + "</span>" +
                          "<br />" + __old);
    ui->output->setText(__new);
}

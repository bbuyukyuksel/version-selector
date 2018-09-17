#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QProcess>
#include <stdio.h>
#include <stdlib.h>
#include <QKeyEvent>
#include <QMessageBox>
#include <QDir>
#include <iostream>



static int line = 1;
static int selectedItem = -1;

void MainWindow::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_Escape)
        close();
    if(event->key() == Qt::Key_Return)
        ui->bt_create->click();
    if(event->key() == Qt::Key_F1)
        QMessageBox::information(this,"Info","Burak Büyükyüksel");


}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->info->setText("Selected Version : ");

    refreshPool();

}

MainWindow::~MainWindow()
{
    runCommand("rm -rf /tmp/jvs");
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
    term_out_global = term_out;
    term_out.replace("\n","<br />");

    QString __old = ui->output->text();
    QString __new__formatted = QString("CMD : <span style='color:yellow;'>%1</span><br/>"
                                       "#%2 <span style='color:red';> -> </span> <br/>"
                                       "<span style='color:lightblue';>%3</span> <br/>"
                                       "%4").arg(cmd,QString::number(line++),term_out,__old);

    ui->output->setText(__new__formatted);
}

void MainWindow::on_addFile_clicked()
{
    hide();
    myScreen = new screen();
    myScreen->setModal(true);
    myScreen->exec();
    show();

    if(myScreen->filepath.contains(".tar.gz")){
        QMessageBox myBox;
        myBox.setText("Başarılı");
        myBox.setIcon(QMessageBox::Icon::Information);
        myBox.exec();
        QFileInfo myFile(myScreen->filepath);
        qDebug() << "My File Path : " << myScreen->filepath;
        qDebug() << "My File Name : " << myFile.fileName();
        QString myFileName = myFile.fileName();
        myFileName.replace(".tar.gz",QString(""));
        //qDebug() << myFileName;

        runCommand("rm -rf /tmp/jvs");
        runCommand("mkdir /tmp/jvs");
        QString moveFile2Temp = QString("cp -r %1 %2").arg(myScreen->filepath,"/tmp/jvs/.");
        runCommand(moveFile2Temp);
        QString unzip = QString("cd /tmp/jvs && ls && tar -zxvf %1").arg(myFile.fileName());
        runCommand(unzip);
        QString delzip = QString("cd /tmp/jvs && rm -rf %1").arg(myFile.fileName());
        runCommand(delzip);

        QDir dr("/tmp/jvs");
        QString versionDir = dr.entryList().last();

        dr.cd("/opt/jvs");
        QStringList versionList = dr.entryList();

        if(versionList.contains(versionDir)){
            QMessageBox::critical(this,"Error !", versionDir + " Already Exists");
            QString delVersionDir = QString("cd /tmp/jvs && rm -rf /opt/jvs/%1").arg(versionDir);
            QMessageBox::information(this,"Bilgilendirme", versionDir + " Silindi, yeniden oluşturulacak.");
        }

            QString moveFile2JVS = QString("cd /tmp/jvs && mv %1 /opt/jvs/.").arg(versionDir);
            runCommand(moveFile2JVS);
            /*
            sudo update-alternatives --install '/usr/bin/java' 'java' '/opt/java/64/jre1.7.0_09/bin/java' 1
            */
            QString update_alternatives = QString("sudo update-alternatives --install "
                                                  "'/usr/bin/java' 'java' "
                                                  "'/opt/jvs/%1/bin/java' 1").arg(versionDir);
            qDebug() << update_alternatives;
            runCommand(update_alternatives);
            refreshPool();

    }
    else{
        QMessageBox myBox;
        myBox.setText("Başarısız");
        myBox.setIcon(QMessageBox::Icon::Information);
        myBox.exec();
    }

}

void MainWindow::runCommand(QString cmd){
    ui->cmd->setText(cmd);
    ui->bt_create->click();
}
void MainWindow::refreshPool(){

    QDir dr;
    if(!dr.cd("/opt/jvs")){
        qDebug() << dr.mkdir("/opt/jvs");
        qDebug() << dr.cd("/opt/jvs");
    }

    QStringList versionList = dr.entryList();
    versionList.removeAt(0);
    versionList.removeAt(0);
    ui->pool->addItems(versionList);
}



void MainWindow::on_bt_changeVersion_clicked()
{
    QString selectedVersion = ui->pool->currentText();
    QMessageBox::information(this,"Info","Version will change : " + selectedVersion);
    /*
    update-alternatives --set java /opt/jvs/%1/bin/java
    */
    QString set_alternative = QString("update-alternatives --set "
                                      "java /opt/jvs/%1/bin/java").arg(selectedVersion);
    runCommand(set_alternative);

}

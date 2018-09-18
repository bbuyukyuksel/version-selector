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
bool flag_firstChanged = true;
bool on_off_toggled = false;

void MainWindow::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_Escape)
        close();
    if(event->key() == Qt::Key_Return)
        ui->bt_create->click();
    if(event->key() == Qt::Key_F1){
        about();
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->info->setText("Selected Version : ");
    this->setWindowTitle("JVS");

    this->setWindowIcon(QIcon(":/resources/icon.png"));
    refreshPool();
    ui->on_off->click();
}

MainWindow::~MainWindow()
{
    runCommand("rm -rf /tmp/jvs");
    delete ui;
}

void MainWindow::on_pool_currentIndexChanged(const QString &arg1)
{
    if(!flag_firstChanged){
        ui->label->setText(arg1);
        ui->label->setStyleSheet("color:red;");
        selectedItem = ui->pool->currentIndex();
    }
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
    inkex.write("\n");
    inkex.write("exit\n");


    inkex.waitForFinished(300);
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

    /*
    QDir dr;
    if(!dr.cd("/opt/jvs")){
        qDebug() << dr.mkdir("/opt/jvs");
        qDebug() << dr.cd("/opt/jvs");
    }

    QStringList versionList = dr.entryList();
    versionList.removeAt(0);
    versionList.removeAt(0);
    ui->pool->addItems(versionList);

*/

/*
    QStringList lines;
    lines.append("java alternatifi için 2 seçenek var (/usr/bin/java sağlanıyor).");
    lines.append("  0            /usr/lib/jvm/java-8-openjdk-amd64/jre/bin/java   1081      otomatik kip");
    lines.append("  1            /opt/jvs/jre1.8.0_181/bin/java                   1         elle ayarlanmış kip");
    lines.append("  2            /usr/lib/jvm/java-8-openjdk-amd64/jre/bin/java   1081      elle ayarlanmış kip");
    lines.append("  2            /usr/lib/jvm/java-8-openjdk-amd64/jre/bin/java   1081      elle ayarlanmış kip");
    lines.append("  2            /usr/lib/jvm/java-8-openjdk-amd64/jre/bin/java   1081      elle ayarlanmış kip");
    lines.append("* 2            /usr/lib/jvm/java-9-openjdk-amd64/jre/bin/java   1081      elle ayarlanmış kip");
    lines.append("  2            /usr/lib/jvm/java-9-openjdk-amd64/jre/bin/java   1081      elle ayarlanmış kip");
    lines.append("  2            /usr/lib/jvm/java-10-openjdk-amd64/jre/bin/java   1081      elle ayarlanmış kip");
    lines.append("  2            /usr/lib/jvm/java-10-openjdk-amd64/jre/bin/java   1081      elle ayarlanmış kip");
*/

/*
    runCommand("sudo update-alternatives --config java");
    QStringList lines = term_out_global.split("\n");
*/
    runCommand("update-alternatives --list java");
    QStringList lines = term_out_global.split("\n");


    /// Update Versions
    QStringList versions;
    QListIterator<QString> itr (lines);
    while (itr.hasNext()) {
        QString current = itr.next();
        //qDebug() << "{" <<  current << "}";
        if(!current.contains("java")){
            lines.removeAt(lines.indexOf(current));
        }
        else{
            versions.append(current.mid(current.indexOf('/'),current.indexOf("java ") - 11));
        }
    }

    QListIterator<QString> i (versions);
    while (i.hasNext()) {
        QString current = i.next();
        QStringList tmp(versions);
        tmp.removeAt(tmp.indexOf(current));
        while(tmp.contains(current)){
            int index = tmp.indexOf(current);
            versions.removeAt(index+1);
            tmp.removeAt(index);
        }
        //qDebug() << "REAL : " << versions;
        //qDebug() << "TEMP : " << tmp;
        //qDebug() << "CuRR : " << current;
        //qDebug() << "#######################";
    }

    ///Find Active Version
    QString currentVersion;
    runCommand("update-alternatives --display java");
    lines = term_out_global.split("\n");
    QListIterator<QString> __itr (lines);
    while (__itr.hasNext()) {
        QString current = __itr.next();
        if(current.contains("mevcut bağ")){
            lines.removeAt(lines.indexOf(current));
            currentVersion = current.mid(current.indexOf('/'),current.indexOf("java ") - 9);
            break;
        }
    }
    ///Clear ComboBox
    for(int i = ui->pool->count(); i >= 0; i--){
        ui->pool->removeItem(i);
    }

    ui->pool->addItems(versions);
    ui->pool->setCurrentIndex(versions.indexOf(currentVersion));
    ui->label->setText(ui->pool->currentText());
    flag_firstChanged = false;

}



void MainWindow::on_bt_changeVersion_clicked()
{
    QString selectedVersion = ui->pool->currentText();
    QMessageBox::information(this,"Info","Version will change : " + selectedVersion);
    /*
    update-alternatives --set java /opt/jvs/%1/bin/java

    QString set_alternative = QString("update-alternatives --set "
                                      "java /opt/jvs/%1/bin/java").arg(selectedVersion);
    */
    QString set_alternative = QString("update-alternatives --set "
                                      "java %1").arg(selectedVersion);

    //qDebug() << set_alternative;
    ui->label->setStyleSheet("color:lightgreen;");
    runCommand(set_alternative);

}


void MainWindow::on_on_off_clicked()
{
    if(on_off_toggled){
        ui->cmd->setVisible(true);
        ui->bt_create->setVisible(true);
        ui->scrollArea_2->setVisible(true);
        this->setGeometry(300,300,580,298);
        on_off_toggled = false;
        ui->on_off->setStyleSheet("border-image:url(:/resources/on_16.png) 0 0 0 0 stretch stretch;");
    }
    else{
        ui->cmd->setVisible(false);
        ui->bt_create->setVisible(false);
        ui->scrollArea_2->setVisible(false);
        this->setGeometry(300,300,580,100);
        on_off_toggled = true;
        ui->on_off->setStyleSheet("border-image:url(:/resources/off_16.png) 0 0 0 0 stretch stretch;");
    }
}

void MainWindow::on_bt_info_clicked()
{
    about();
}
void MainWindow::about(){
    QString about = "<span style='color:#838383;font-weight:bold;'> <br/>İçer içer bilgisayar başına oturur </span><hr />"
                    "<span style=''><b>J</b>ava <b>V</b>ersion <b>S</b>elector</span><br/><br/>"
                    "<span style=color:red;>Version : 1.0</span><br/>"
                    "<span style=color:blue;>License : GPL</span><hr />"

                    "<b style='color:#40AA40;'>Burak BÜYÜKYÜKSEL</b> <br />"
                    "<b style='color:#40AA40;'><i>buyukyukselburak@gmail.com</i></b>";
    QMessageBox::about(this,"Hakkımda",about);
}

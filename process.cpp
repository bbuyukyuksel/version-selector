#include "process.h"

process::process()
{
    dr = new QDir();
}
process::~process(){
    delete this->dr;
}

void process::makedir(){
    dr->cd("/opt");
    dr->mkdir("/java");
}

QString process::tar(QString path){

}

void process::move(QString src, QString dst){

}
void process::deleteFile(QString path){

}

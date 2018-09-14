#ifndef PROCESS_H
#define PROCESS_H

#include <QString>
#include <QDir>
#include <QFileInfo>

class process
{
public:
    QDir *dr;
    process();
    ~process();
    void makedir();
    void deleteFile(QString path);
    QString tar(QString path);
    void move(QString src, QString dst);
};

#endif // PROCESS_H

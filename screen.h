#ifndef SCREEN_H
#define SCREEN_H

#include <QDialog>
#include <QDropEvent>
#include <QDebug>
#include <QList>

namespace Ui {
class screen;
}

class screen : public QDialog
{
    Q_OBJECT

public:
    QString filepath;
    explicit screen(QWidget *parent = 0);
    ~screen();
    int itemCounter = 0;
private:

    Ui::screen *ui;
    void dropEvent(QDropEvent *e);
    void dragEnterEvent(QDragEnterEvent *e);
    void addItem(QString text);
};

#endif // SCREEN_H

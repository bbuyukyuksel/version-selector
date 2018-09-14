#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "screen.h"
#include "process.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pool_currentIndexChanged(const QString &arg1);

    void on_bt_create_clicked();

    void on_addFile_clicked();

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent*);
    screen *myScreen;
    process *proc;
};

#endif // MAINWINDOW_H

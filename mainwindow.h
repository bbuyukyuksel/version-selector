#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "screen.h"


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

    void on_bt_changeVersion_clicked();


    void on_on_off_clicked();

    void on_bt_info_clicked();

private:
    QString term_out_global;
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent*);
    screen *myScreen;

    void about();
    void runCommand(QString cmd);
    void refreshPool();
};

#endif // MAINWINDOW_H

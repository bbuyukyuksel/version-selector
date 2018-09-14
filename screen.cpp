#include "screen.h"
#include "ui_screen.h"

#include <QMimeData>
#include <QPushButton>
#include <QLabel>
#include <QDir>
#include <QFileInfo>

static int tryAgain = 1;
screen::screen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::screen)
{
    ui->setupUi(this);
    this->setWindowTitle("Versiyon Ekle");
    setAcceptDrops(true);
}

void screen::addItem(QString text){
    QPushButton *button = new QPushButton("x");
    QLabel *label = new QLabel(text);
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(label, this->itemCounter, 0);
    layout->addWidget(button, this->itemCounter, 1);
    this->itemCounter++;
    ui->layout->addLayout(layout);
    qDebug() << this->itemCounter++ ;
}

void screen::dragEnterEvent(QDragEnterEvent *e)
{
    if (e->mimeData()->hasUrls()) {
        e->acceptProposedAction();
    }
}
void screen::dropEvent(QDropEvent *e)
{
    foreach (const QUrl &url, e->mimeData()->urls()) {
        QString fileName = url.toLocalFile();
        this->filepath = fileName;
        //qDebug() << "Dropped file:" << fileName;
    }

    if(filepath.contains(".tar.gz"))
        close();
    QFileInfo fi(filepath);
    ui->layout->addWidget(new QLabel(("#["+ QString::number(tryAgain++) +"].tar.gz değil\n" + fi.fileName())));
}
screen::~screen()
{
    delete ui;
}

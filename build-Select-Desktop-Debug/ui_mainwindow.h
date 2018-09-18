/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd;
    QAction *actionExit;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea;
    QWidget *contents;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *info;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *cmd;
    QPushButton *bt_create;
    QScrollArea *scrollArea_2;
    QWidget *scrolltextarea;
    QGridLayout *gridLayout;
    QLabel *output;
    QHBoxLayout *horizontalLayout;
    QComboBox *pool;
    QPushButton *bt_changeVersion;
    QPushButton *addFile;
    QPushButton *bt_info;
    QPushButton *on_off;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(580, 298);
        MainWindow->setStyleSheet(QLatin1String("QPushButton#bt_info:hover{\n"
"background-color:lightblue;\n"
"}\n"
"QPushButton#bt_info{\n"
"border:none;\n"
"border-image:url(:/resources/about.png) 0 0 0 0 stretch stretch;\n"
"background-color:none;\n"
"border-radius:8px;\n"
"}\n"
"QPushButton#on_off{\n"
"border:none;\n"
"border-image:url(:/resources/off_16.png) 0 0 0 0 stretch stretch;\n"
"border-radius:8px;\n"
"\n"
"}\n"
"QLabel#label{\n"
"	color:lightgreen;\n"
"}\n"
"QLabel#info{\n"
"	color:white;\n"
"}\n"
"\n"
"QPushButton#addFile{\n"
"	\n"
"}\n"
"QLabel#output{\n"
"	margin:0px;\n"
"	color:green;\n"
"	font-size:12px;\n"
"}\n"
"QWidget#scrolltextarea{\n"
"	background-color:black;\n"
"}\n"
"QWidget#contents{\n"
"background-color:gray;\n"
"}\n"
"QWidget#centralWidget{\n"
"background-color:silver;\n"
"}\n"
"QScrollArea#scrollArea{\n"
"background-color:gray;\n"
"padding:2px;\n"
"}\n"
"QPushButton{\n"
"color:gray;\n"
"background-color:white;\n"
"border-radius:5px;\n"
"\n"
"padding:2px;\n"
"border-bottom:2px solid silver;\n"
"border-right:2px solid silver;\n"
""
                        "}\n"
"QPushButton:hover, focused{\n"
"border:silver;\n"
"}\n"
"QPushButton#addFile{\n"
"color:green;\n"
"}\n"
"\n"
""));
        actionAdd = new QAction(MainWindow);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        contents = new QWidget();
        contents->setObjectName(QStringLiteral("contents"));
        contents->setGeometry(QRect(0, 0, 556, 274));
        gridLayout_2 = new QGridLayout(contents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        info = new QLabel(contents);
        info->setObjectName(QStringLiteral("info"));

        horizontalLayout_3->addWidget(info);

        label = new QLabel(contents);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        cmd = new QLineEdit(contents);
        cmd->setObjectName(QStringLiteral("cmd"));
        cmd->setEnabled(true);

        horizontalLayout_2->addWidget(cmd);

        bt_create = new QPushButton(contents);
        bt_create->setObjectName(QStringLiteral("bt_create"));
        bt_create->setCursor(QCursor(Qt::PointingHandCursor));
        bt_create->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(bt_create);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        scrollArea_2 = new QScrollArea(contents);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrolltextarea = new QWidget();
        scrolltextarea->setObjectName(QStringLiteral("scrolltextarea"));
        scrolltextarea->setGeometry(QRect(0, 0, 536, 172));
        gridLayout = new QGridLayout(scrolltextarea);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        output = new QLabel(scrolltextarea);
        output->setObjectName(QStringLiteral("output"));
        output->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(output, 0, 0, 1, 1);

        scrollArea_2->setWidget(scrolltextarea);

        gridLayout_2->addWidget(scrollArea_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        pool = new QComboBox(contents);
        pool->setObjectName(QStringLiteral("pool"));
        pool->setMinimumSize(QSize(128, 0));
        pool->setSizeIncrement(QSize(0, 0));

        horizontalLayout->addWidget(pool);

        bt_changeVersion = new QPushButton(contents);
        bt_changeVersion->setObjectName(QStringLiteral("bt_changeVersion"));
        bt_changeVersion->setMaximumSize(QSize(75, 50));
        bt_changeVersion->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(bt_changeVersion);

        addFile = new QPushButton(contents);
        addFile->setObjectName(QStringLiteral("addFile"));
        addFile->setMaximumSize(QSize(50, 50));
        addFile->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(addFile);

        bt_info = new QPushButton(contents);
        bt_info->setObjectName(QStringLiteral("bt_info"));
        bt_info->setMaximumSize(QSize(16, 16));
        bt_info->setCursor(QCursor(Qt::WhatsThisCursor));

        horizontalLayout->addWidget(bt_info);

        on_off = new QPushButton(contents);
        on_off->setObjectName(QStringLiteral("on_off"));
        on_off->setMaximumSize(QSize(16, 16));
        on_off->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(on_off);


        gridLayout_2->addLayout(horizontalLayout, 3, 0, 1, 1);

        scrollArea->setWidget(contents);

        gridLayout_3->addWidget(scrollArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionAdd->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        info->setText(QApplication::translate("MainWindow", "##", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "##", Q_NULLPTR));
        cmd->setText(QString());
        cmd->setPlaceholderText(QApplication::translate("MainWindow", "Command", Q_NULLPTR));
        bt_create->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        output->setText(QApplication::translate("MainWindow", "..", Q_NULLPTR));
        bt_changeVersion->setText(QApplication::translate("MainWindow", "Change", Q_NULLPTR));
        addFile->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        bt_info->setText(QString());
        on_off->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

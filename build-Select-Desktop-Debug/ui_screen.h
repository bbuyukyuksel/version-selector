/********************************************************************************
** Form generated from reading UI file 'screen.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREEN_H
#define UI_SCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_screen
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *icon;
    QScrollArea *scrollArea;
    QWidget *dropArea;
    QGridLayout *gridLayout;
    QVBoxLayout *layout;

    void setupUi(QDialog *screen)
    {
        if (screen->objectName().isEmpty())
            screen->setObjectName(QStringLiteral("screen"));
        screen->resize(230, 198);
        screen->setStyleSheet(QLatin1String("QLabel#icon{\n"
"border-image:url(:/resources/drag-drop.png) 0 0 0 0 stretch stretch;\n"
"}\n"
"QWidget#dropArea{\n"
"background-color:white;\n"
"}\n"
"#screen{\n"
"background-color:silver;\n"
"}"));
        gridLayout_2 = new QGridLayout(screen);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(screen);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        icon = new QLabel(screen);
        icon->setObjectName(QStringLiteral("icon"));
        icon->setEnabled(true);
        icon->setMaximumSize(QSize(25, 25));

        horizontalLayout->addWidget(icon);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        scrollArea = new QScrollArea(screen);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        dropArea = new QWidget();
        dropArea->setObjectName(QStringLiteral("dropArea"));
        dropArea->setGeometry(QRect(0, 0, 210, 156));
        gridLayout = new QGridLayout(dropArea);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        layout = new QVBoxLayout();
        layout->setObjectName(QStringLiteral("layout"));

        gridLayout->addLayout(layout, 0, 0, 1, 1);

        scrollArea->setWidget(dropArea);

        gridLayout_2->addWidget(scrollArea, 1, 0, 1, 1);


        retranslateUi(screen);

        QMetaObject::connectSlotsByName(screen);
    } // setupUi

    void retranslateUi(QDialog *screen)
    {
        screen->setWindowTitle(QApplication::translate("screen", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("screen", "Dosyalar\304\261n\304\261z\304\261 S\303\274r\303\274kleyiniz", Q_NULLPTR));
        icon->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class screen: public Ui_screen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREEN_H

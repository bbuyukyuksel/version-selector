/********************************************************************************
** Form generated from reading UI file 'contributors.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTRIBUTORS_H
#define UI_CONTRIBUTORS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Contributors
{
public:

    void setupUi(QDialog *Contributors)
    {
        if (Contributors->objectName().isEmpty())
            Contributors->setObjectName(QStringLiteral("Contributors"));
        Contributors->resize(321, 169);
        Contributors->setSizeGripEnabled(false);

        retranslateUi(Contributors);

        QMetaObject::connectSlotsByName(Contributors);
    } // setupUi

    void retranslateUi(QDialog *Contributors)
    {
        Contributors->setWindowTitle(QApplication::translate("Contributors", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Contributors: public Ui_Contributors {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTRIBUTORS_H

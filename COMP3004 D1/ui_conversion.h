/********************************************************************************
** Form generated from reading UI file 'conversion.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERSION_H
#define UI_CONVERSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_conversion
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *conversion)
    {
        if (conversion->objectName().isEmpty())
            conversion->setObjectName(QString::fromUtf8("conversion"));
        conversion->resize(400, 300);
        menuBar = new QMenuBar(conversion);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        conversion->setMenuBar(menuBar);
        mainToolBar = new QToolBar(conversion);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        conversion->addToolBar(mainToolBar);
        centralWidget = new QWidget(conversion);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        conversion->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(conversion);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        conversion->setStatusBar(statusBar);

        retranslateUi(conversion);

        QMetaObject::connectSlotsByName(conversion);
    } // setupUi

    void retranslateUi(QMainWindow *conversion)
    {
        conversion->setWindowTitle(QCoreApplication::translate("conversion", "conversion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class conversion: public Ui_conversion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERSION_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QSpinBox *spinBoxN;
    QLabel *label_2;
    QSpinBox *spinBoxG;
    QLabel *label_3;
    QSpinBox *spinBoxP;
    QLabel *label_4;
    QSpinBox *spinBoxE;
    QPushButton *countPushButton;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(254, 285);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 10, 71, 31));
        spinBoxN = new QSpinBox(centralwidget);
        spinBoxN->setObjectName(QString::fromUtf8("spinBoxN"));
        spinBoxN->setGeometry(QRect(130, 10, 81, 29));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 40, 71, 31));
        spinBoxG = new QSpinBox(centralwidget);
        spinBoxG->setObjectName(QString::fromUtf8("spinBoxG"));
        spinBoxG->setGeometry(QRect(130, 40, 81, 29));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 70, 71, 31));
        spinBoxP = new QSpinBox(centralwidget);
        spinBoxP->setObjectName(QString::fromUtf8("spinBoxP"));
        spinBoxP->setGeometry(QRect(130, 70, 81, 29));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 100, 91, 31));
        spinBoxE = new QSpinBox(centralwidget);
        spinBoxE->setObjectName(QString::fromUtf8("spinBoxE"));
        spinBoxE->setGeometry(QRect(130, 100, 81, 29));
        countPushButton = new QPushButton(centralwidget);
        countPushButton->setObjectName(QString::fromUtf8("countPushButton"));
        countPushButton->setGeometry(QRect(20, 160, 61, 28));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(90, 140, 141, 71));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 254, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "N points:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "G points:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "P points:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Exam grade:", nullptr));
        countPushButton->setText(QCoreApplication::translate("MainWindow", "Count", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

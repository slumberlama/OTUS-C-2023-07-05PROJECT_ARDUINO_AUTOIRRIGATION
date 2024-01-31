/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_monitoring;
    QLabel *label;
    QFrame *frame;
    QPushButton *pushButton_start_manual_irrigation;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_last_irrigation;
    QLineEdit *lineEdit_soil_humidity;
    QLabel *label_air_temp;
    QLineEdit *lineEdit_last_irrigation;
    QLineEdit *lineEdit_air_temp;
    QLabel *label_soil_humidity;
    QLabel *label_air_humidity;
    QLineEdit *lineEdit_light;
    QLabel *label_light;
    QLineEdit *lineEdit_air_humidity;
    QLabel *label_time_to_future_irrigation;
    QLineEdit *lineEdit_time_to_future_irrigation;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(575, 532);
        MainWindow->setStyleSheet(QLatin1String("div {\n"
"	background-image: url(:/img/background.png);\n"
"	opacity = 07.5;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_monitoring = new QPushButton(centralWidget);
        pushButton_monitoring->setObjectName(QStringLiteral("pushButton_monitoring"));
        pushButton_monitoring->setGeometry(QRect(300, 10, 211, 51));
        pushButton_monitoring->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(178, 130, 176);\n"
"	color: white;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"									stop: 0 #9b75f6, stop: 1 #b89cfc);\n"
"}"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 410, 551, 31));
        label->setStyleSheet(QStringLiteral("border-top-color: rgb(255, 255, 127);"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(30, 120, 221, 61));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_start_manual_irrigation = new QPushButton(centralWidget);
        pushButton_start_manual_irrigation->setObjectName(QStringLiteral("pushButton_start_manual_irrigation"));
        pushButton_start_manual_irrigation->setGeometry(QRect(20, 180, 211, 51));
        pushButton_start_manual_irrigation->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(178, 130, 176);\n"
"	color: white;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"									stop: 0 #9b75f6, stop: 1 #b89cfc);\n"
"}"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(250, 70, 301, 341));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_last_irrigation = new QLabel(layoutWidget);
        label_last_irrigation->setObjectName(QStringLiteral("label_last_irrigation"));

        gridLayout->addWidget(label_last_irrigation, 4, 0, 1, 1);

        lineEdit_soil_humidity = new QLineEdit(layoutWidget);
        lineEdit_soil_humidity->setObjectName(QStringLiteral("lineEdit_soil_humidity"));

        gridLayout->addWidget(lineEdit_soil_humidity, 0, 1, 1, 1);

        label_air_temp = new QLabel(layoutWidget);
        label_air_temp->setObjectName(QStringLiteral("label_air_temp"));

        gridLayout->addWidget(label_air_temp, 3, 0, 1, 1);

        lineEdit_last_irrigation = new QLineEdit(layoutWidget);
        lineEdit_last_irrigation->setObjectName(QStringLiteral("lineEdit_last_irrigation"));

        gridLayout->addWidget(lineEdit_last_irrigation, 4, 1, 1, 1);

        lineEdit_air_temp = new QLineEdit(layoutWidget);
        lineEdit_air_temp->setObjectName(QStringLiteral("lineEdit_air_temp"));

        gridLayout->addWidget(lineEdit_air_temp, 3, 1, 1, 1);

        label_soil_humidity = new QLabel(layoutWidget);
        label_soil_humidity->setObjectName(QStringLiteral("label_soil_humidity"));

        gridLayout->addWidget(label_soil_humidity, 0, 0, 1, 1);

        label_air_humidity = new QLabel(layoutWidget);
        label_air_humidity->setObjectName(QStringLiteral("label_air_humidity"));

        gridLayout->addWidget(label_air_humidity, 1, 0, 1, 1);

        lineEdit_light = new QLineEdit(layoutWidget);
        lineEdit_light->setObjectName(QStringLiteral("lineEdit_light"));

        gridLayout->addWidget(lineEdit_light, 2, 1, 1, 1);

        label_light = new QLabel(layoutWidget);
        label_light->setObjectName(QStringLiteral("label_light"));

        gridLayout->addWidget(label_light, 2, 0, 1, 1);

        lineEdit_air_humidity = new QLineEdit(layoutWidget);
        lineEdit_air_humidity->setObjectName(QStringLiteral("lineEdit_air_humidity"));

        gridLayout->addWidget(lineEdit_air_humidity, 1, 1, 1, 1);

        label_time_to_future_irrigation = new QLabel(layoutWidget);
        label_time_to_future_irrigation->setObjectName(QStringLiteral("label_time_to_future_irrigation"));

        gridLayout->addWidget(label_time_to_future_irrigation, 5, 0, 1, 1);

        lineEdit_time_to_future_irrigation = new QLineEdit(layoutWidget);
        lineEdit_time_to_future_irrigation->setObjectName(QStringLiteral("lineEdit_time_to_future_irrigation"));

        gridLayout->addWidget(lineEdit_time_to_future_irrigation, 5, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        pushButton_monitoring->raise();
        label->raise();
        frame->raise();
        layoutWidget->raise();
        pushButton_start_manual_irrigation->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 575, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton_monitoring->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\267\320\270\321\202\321\214 \321\202\320\265\320\272\321\203\321\211\320\270\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", 0));
        label->setText(QApplication::translate("MainWindow", "\320\247\321\202\320\276\320\261\321\213 \320\267\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214 \320\260\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\277\320\276\320\273\320\270\320\262,\320\276\321\202\320\272\320\273\321\216\321\207\320\270\321\202\320\265 \320\277\320\273\320\260\321\202\321\203 \320\276\321\202 USB \320\270 \320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\320\265 \320\272 \320\261\320\260\321\202\320\260\321\200\320\265\320\271\320\272\320\265", 0));
#ifndef QT_NO_WHATSTHIS
        pushButton_start_manual_irrigation->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>\320\237\321\200\320\276\320\262\320\265\321\200\320\272\320\260 \320\275\320\260\321\201\320\276\321\201\320\260</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        pushButton_start_manual_irrigation->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\277\320\276\320\273\320\270\320\262 \320\262\321\200\321\203\321\207\320\275\321\203\321\216, 2 \321\201\320\265\320\272", 0));
        label_last_irrigation->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \321\201 \320\277\320\276\321\201\320\273\320\265\320\264\320\275\320\265\320\263\320\276 \320\277\320\276\320\273\320\270\320\262\320\260, \321\207\320\260\321\201", 0));
        label_air_temp->setText(QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260 \320\262\320\276\320\267\320\264\321\203\321\205\320\260, \313\232C", 0));
        label_soil_humidity->setText(QApplication::translate("MainWindow", "\320\222\320\273\320\260\320\266\320\275\320\276\321\201\321\202\321\214 \320\277\320\276\321\207\320\262\321\213, %", 0));
        label_air_humidity->setText(QApplication::translate("MainWindow", "\320\222\320\273\320\260\320\266\320\275\320\276\321\201\321\202\321\214 \320\262\320\276\320\267\320\264\321\203\321\205\320\260, %", 0));
        lineEdit_light->setText(QString());
        label_light->setText(QApplication::translate("MainWindow", "\320\236\321\201\320\262\320\265\321\211\321\221\320\275\320\275\320\276\321\201\321\202\321\214, %", 0));
        label_time_to_future_irrigation->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \320\264\320\276 \320\261\320\273\320\270\320\266\320\260\320\271\321\210\320\265\320\263\320\276 \320\277\320\276\320\273\320\270\320\262\320\260, \321\207\320\260\321\201", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

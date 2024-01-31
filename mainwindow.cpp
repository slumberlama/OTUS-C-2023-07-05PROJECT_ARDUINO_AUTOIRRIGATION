#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "autoirrigation.h"
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QtWidgets>
#include <QRegExp>

//core5compat добавить в файл проекта

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    arduino_is_available = false;
    arduino_port_name = "";
    arduino = new QSerialPort;

    /*qDebug() << "Number of abvailable ports: " << QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        qDebug() << "Has vendor ID: " <<serialPortInfo.hasVendorIdentifier();
        if(serialPortInfo.hasVendorIdentifier()) {
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
        }
        qDebug() << "Has Product ID: " <<serialPortInfo.hasProductIdentifier();
        if(serialPortInfo.hasProductIdentifier()) {
            qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
        }
    }*/
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()) {
            if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id) {
                if(serialPortInfo.productIdentifier() == arduino_uno_product_id) {
                    arduino_port_name = serialPortInfo.portName();
                    //qDebug() << "arduino_port_name: " << arduino_port_name;
                    arduino_is_available = true;
                }
            }
        }
    }

    if(arduino_is_available) {
        //open and configure the serialport
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::ReadWrite);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(on_pushButton_monitoring_clicked()));
    }
    else {
        QMessageBox::warning(this, "Port error", "Couldn't find the Arduino!");
    }
    //qDebug() << "arduino_port_name: " << arduino_port_name;
}

MainWindow::~MainWindow()
{
    if(arduino->isOpen()) {
        arduino->close();
    }
    delete ui;
}

void MainWindow::updateRGB(QString command) {
    if(arduino->isWritable()) {
        arduino->write(command.toStdString().c_str());
    } else {
        qDebug() << "Couldn't write to serial!";
    }
}

void MainWindow::on_pushButton_monitoring_clicked()
{
    arduino->write("1"); // очень важно, что именно двойные кавычки
    arduino->waitForBytesWritten(10); // ждем пока дойдет
    while (arduino->waitForReadyRead(10)) {
        //QByteArray serialData = arduino->readAll();
    }

    QByteArray serialData = arduino->readAll();

    if((serialData.contains("Ошибка считывания датчиков")) == true) {
            //ui->lineEdit_last_irrigation->setText(last_irrigation);
            //ui->lineEdit_time_to_future_irrigation->setText(time_to_future_irrigation);
            ui->lineEdit_air_humidity->setText("Ошибка считывания датчиков");
            ui->lineEdit_air_temp->setText("Ошибка считывания датчиков");
            ui->lineEdit_soil_humidity->setText("Ошибка считывания датчиков");
            ui->lineEdit_light->setText("Ошибка считывания датчиков");
            return;
    }

    QString data = QString::fromStdString(serialData.toStdString());

    QStringList temp = data.split(' ');
    //qDebug() << temp;
    //qDebug() << temp.size();
    QString last_irrigation, air_humidity, air_temp, soil_humidity, light;
    if(temp.size() > 1) {
        last_irrigation = temp.at(0);
        air_humidity = temp.at(1);
        air_temp = temp.at(2);
        soil_humidity = temp.at(3);
        light = temp.at(4);
    }
    ui->lineEdit_last_irrigation->setText(last_irrigation);
    //ui->lineEdit_time_to_future_irrigation->setText(time_to_future_irrigation);
    ui->lineEdit_air_humidity->setText(air_humidity);
    ui->lineEdit_air_temp->setText(air_temp);
    ui->lineEdit_soil_humidity->setText(soil_humidity);
    ui->lineEdit_light->setText(light);
}

void MainWindow::on_pushButton_start_manual_irrigation_clicked()
{
    arduino->write("2"); // очень важно, что именно двойные кавычки
    arduino->waitForBytesWritten(10); // ждем пока дойдет
    //включаем помпу
    ui->statusBar->showMessage("Идёт полив ^_^");
}

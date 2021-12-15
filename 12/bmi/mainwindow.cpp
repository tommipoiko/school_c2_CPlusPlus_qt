#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_countButton_clicked()
{
    ui->resultLabel->clear();
    ui->infoTextBrowser->clear();
    int w  = ui->weightLineEdit->text().toInt();
    float h = ui->heightLineEdit->text().toInt();
    h /= 100;

    if (h > 0) {
        float bmi = 20.0832;
        bmi = w/(h*h);

        ui->resultLabel->setText(QString::number(bmi));

        if (bmi < 18.5) {
            ui->infoTextBrowser->setText("You are underweight.");
        } else if (bmi > 25) {
            ui->infoTextBrowser->setText("You are overweight.");
        } else {
            ui->infoTextBrowser->setText("Your weight is normal.");
        }
    }
}


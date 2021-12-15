#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "gradecounter.hh"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->spinBoxN->setRange(0, MAX_N_POINTS);

    ui->spinBoxG->setRange(0, MAX_G_POINTS);

    ui->spinBoxP->setRange(0, MAX_P_POINTS);

    ui->spinBoxE->setRange(0, 5);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_spinBoxN_valueChanged(int n)
{
    n_ = n;
}


void MainWindow::on_spinBoxG_valueChanged(int g)
{
    g_ = g;
}


void MainWindow::on_spinBoxP_valueChanged(int p)
{
    p_ = p;
}


void MainWindow::on_spinBoxE_valueChanged(int e)
{
    e_ = e;
}

void MainWindow::on_countPushButton_clicked()
{
    unsigned int grade = count_final_grade(n_, g_, p_, e_);
    QString graba = "Total grade: ";
    graba += QString::number(grade);
    qDebug() << graba;
    ui->textBrowser->setText(graba);
}


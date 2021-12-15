#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QDebug>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

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

void MainWindow::on_findPushButton_clicked()
{
    QString filename = ui->fileLineEdit->text();
    QString text = ui->keyLineEdit->text();

    std::string file_from = filename.toStdString();
    std::string find_text = text.toStdString();

    std::ifstream from(file_from);

    if (not from) {
        ui->textBrowser->setText("File not found");
        return;
    }

    if (text.size() < 1) {
        ui->textBrowser->setText("File found");
        return;
    }

    if (ui->matchCheckBox->isChecked()) {
        std::string row;
        while (getline(from, row)) {
            if (row.find(find_text) != std::string::npos) {
                ui->textBrowser->setText("Word found");
                return;
            }
        }

        ui->textBrowser->setText("Word not found");
        return;
    } else {
        std::string row;
        while (getline(from, row)) {
            std::transform(row.begin(), row.end(), row.begin(), ::toupper);
            std::transform(find_text.begin(), find_text.end(), find_text.begin(), ::toupper);
            if (row.find(find_text) != std::string::npos) {
                ui->textBrowser->setText("Word found");
                return;
            }
        }

        ui->textBrowser->setText("Word not found");
        return;
    }
}

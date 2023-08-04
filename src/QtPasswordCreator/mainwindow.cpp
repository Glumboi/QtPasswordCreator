#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include "passwordsettings.h"

PasswordSettings* settings;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    settings = new PasswordSettings(ui->checkBox_UseSpecialSigns->checkState(), ui->checkBox_UseNumbers->checkState(), ui->doubleSpinBox_PasswordLength->value());
}

MainWindow::~MainWindow()
{
    delete settings;
    delete ui;
}


void MainWindow::on_pushButton_Clear_clicked()
{
    ui->plainTextEdit_GeneratedPassword->clear();
}


void MainWindow::on_pushButton_Export_clicked()
{
    QString pwText = ui->plainTextEdit_GeneratedPassword->toPlainText();
    QString filePath = QFileDialog::getSaveFileName(this,
                                                    "Save password file as...",
                                                    "./Saved_Password",
                                                    tr("Text files (*.txt);;All Files(*.*);;"));
    if(filePath == "") return;
    QFile file(filePath);
    file.open(QIODevice::WriteOnly);

    file.write(pwText.toLocal8Bit());

    file.close();
}


void MainWindow::on_pushButton_Generate_clicked()
{
    ui->plainTextEdit_GeneratedPassword->setPlainText(settings->Generate());
}


void MainWindow::on_doubleSpinBox_PasswordLength_valueChanged(double arg1)
{
    settings->pwLength = (uint8_t)arg1;
}


void MainWindow::on_checkBox_UseNumbers_stateChanged(int arg1)
{
    settings->useNumbers = (bool)arg1;
}


void MainWindow::on_checkBox_UseSpecialSigns_stateChanged(int arg1)
{
    settings->useSpecialSigns = (bool)arg1;
}


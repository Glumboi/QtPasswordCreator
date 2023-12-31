#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Clear_clicked();

    void on_pushButton_Export_clicked();

    void on_pushButton_Generate_clicked();

    void on_doubleSpinBox_PasswordLength_valueChanged(double arg1);

    void on_checkBox_UseNumbers_stateChanged(int arg1);

    void on_checkBox_UseSpecialSigns_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

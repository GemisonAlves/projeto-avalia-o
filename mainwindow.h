#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Calculo_clicked();

    void on_calculo2_clicked();

    void on_calculo3_clicked();

    void on_calculo4_clicked();

    void on_calculo5_clicked();

    void on_calculo6_clicked();

    void on_calculo7_clicked();

    void on_calculo8_clicked();

    void on_gravar_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

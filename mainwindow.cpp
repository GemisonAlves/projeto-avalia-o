#include "mainwindow.h"
#include "ui_mainwindow.h"


QString local= "C:/Users/genilson/Documents/projeto/valores_txt";
QString nome="valoresSalvos";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->resultado1->setText("");
    ui->resultado2->setText("");
    ui->resultado3->setText("");
    ui->resultado4->setText("");
    ui->resultado5->setText("");
    ui->resultado6->setText("");
    ui->resultado7->setText("");
    ui->resultado8->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Calculo_clicked()
{
    ui->resultado1->setText(QString::number(ui->valor1->value() * 0.62137119223733));
}

void MainWindow::on_calculo2_clicked()
{
    ui->resultado2->setText(QString::number(ui->valor2->value() / 0.6213711922373));
}

void MainWindow::on_calculo3_clicked()
{
    ui->resultado3->setText(QString::number(ui->valor3->value() / 60/60));
}


void MainWindow::on_calculo4_clicked()
{
    ui->resultado4->setText(QString::number(ui->valor4->value() * 60*60));
}

void MainWindow::on_calculo5_clicked()
{
    ui->resultado5->setText(QString::number(ui->valor5->value() * 3.6));
}

void MainWindow::on_calculo6_clicked()
{
   ui->resultado6->setText(QString::number(ui->valor6->value() / 3.6));
}

void MainWindow::on_calculo7_clicked()
{
  ui->resultado7->setText(QString::number(ui->valor7->value() /1000));
}

void MainWindow::on_calculo8_clicked()
{
    ui->resultado8->setText(QString::number(ui->valor8->value() *1000));
}

void MainWindow::on_gravar_clicked()
{
    QFile arquivo(local+nome);
    if(arquivo.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox :: warning(this,"ERRO","Erro ao abrir arquivo");
    }
    QTextStream Saida(&arquivo);
    QString valores=ui->plainTextEdit->toPlainText();

    Saida << valores;
    arquivo.flush();
    arquivo.close();


}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton resposta=QMessageBox::question(this,"","Deseja encerrar programa?",QMessageBox::Yes|QMessageBox::No);
    if(resposta==QMessageBox::Yes){
        close();
    }
    else{
        QMessageBox::about(this,"","Programa não encerrado");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
   QString filtro="Todos Arquivos(*.*) ;; Arquivos de texto (*.txt)";
   QString abrirArquivo=QFileDialog::getOpenFileName(this,"Gerar Arquivos","C://",filtro);
   QFile arquivo(abrirArquivo);
   if (!arquivo.open(QFile::ReadOnly|QFile::Text)){
       QMessageBox::warning(this, "", "Erro ao gerar arquivo");
   }
   QTextStream entrada(&arquivo);
   QString texto=entrada.readAll();
   ui->plainTextEdit->setPlainText(texto);
   arquivo.close();
}

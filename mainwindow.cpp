#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QDebug"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Dave237/Documents/Database/first.db");
    if(!db.open()){
        ui->label->setText("Lost connection...");

    }
    else {
        ui->label->setText("connected...");

    }
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loginButton_clicked()
{
    QString name = ui->enterUser->text();
    QString pass = ui->enterPass->text();
    if(db.isOpen()){

        QSqlQuery query;
        if(query.exec("SELECT * FROM users where name='"+name+"' and matricule='"+pass+"'"))
        {
           int count;
           while(query.next()){
               count++;
           }
           if(count == 1){
               ui->label->setText("login successful");
               hide();
               w = new Welcome();
               w->show();
           }
           if(count >1 ){
               ui->label->setText("duplicate credentials");
           }
           if(count < 1){
               ui->label->setText("incorrect credentials");
           }

        }

    }
    }







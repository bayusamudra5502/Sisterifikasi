//
// Created by bayus on 14/06/22.
//

#include "window.hpp"
#include "ui_window.h"
#include <QMessageBox>
#include "Process.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->connect();
}

void MainWindow::connect() {
    QObject::connect(ui->actionExit, SIGNAL(triggered(bool)), this, SLOT(onExit()));
    QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(onSubmit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSubmit() {
    try{
        if(!this->is_valid()){
            QMessageBox::critical(this, "Validation", "Please insert valid pid!");
            return;
        }

        auto str_pid = ui->process_id->text();

        int pid = str_pid.toInt();

        Process p(pid);
        QMessageBox msg;
        msg.addButton(QMessageBox::Yes);
        msg.addButton(QMessageBox::No);
        msg.setIcon(QMessageBox::Warning);

        msg.setText("Are you sure to edit this process?");

        std::string detail_msg = "Process Id : "+ str_pid.toStdString()
                                 + "\nProcess Name : "+ p.get_name()
                                 + "Process Path : " + p.get_path();

        msg.setDetailedText(QString(detail_msg.c_str()));
        int res = msg.exec();

        if(res == QMessageBox::No){
            QMessageBox::information(this, "Information", "Action canceled");
            return;
        }

    }catch (std::exception e){
        QMessageBox msg;
        msg.setIcon(QMessageBox::Critical);
        msg.addButton(QMessageBox::Yes);
        msg.setText("Some expected error happened");

        msg.setDetailedText(QString(e.what()));
        msg.exec();
    }


}

bool MainWindow::is_valid() {
    QRegExp number("\\d*");

    if(!number.exactMatch(ui->process_id->text())){
        return false;
    }

    return true;
}

void MainWindow::onExit(){
    QApplication::quit();
}

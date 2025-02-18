#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lisaa,QPushButton::clicked,this,MainWindow::lisaa);
    connect(ui->nollaa,QPushButton::clicked,this,MainWindow::nollaa);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lisaa()
{
    painallukset++;
    ui->painallukset->setText(QString::number(painallukset));
}

void MainWindow::nollaa()
{
    painallukset = 0;
    ui->painallukset->setText(QString::number(painallukset));
}



#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->n0,&QPushButton::clicked,this,&MainWindow::numeroKasittelija);
    connect(ui->n1,&QPushButton::clicked,this,&MainWindow::numeroKasittelija);
    connect(ui->n2,&QPushButton::clicked,this,&MainWindow::numeroKasittelija);
    connect(ui->n3,&QPushButton::clicked,this,&MainWindow::numeroKasittelija);
    connect(ui->n4,&QPushButton::clicked,this,&MainWindow::numeroKasittelija);
    connect(ui->n5,&QPushButton::clicked,this,&MainWindow::numeroKasittelija);
    connect(ui->n6,&QPushButton::clicked,this,&MainWindow::numeroKasittelija);
    connect(ui->n7,&QPushButton::clicked,this,&MainWindow::numeroKasittelija);
    connect(ui->n8,&QPushButton::clicked,this,&MainWindow::numeroKasittelija);
    connect(ui->n9,&QPushButton::clicked,this,&MainWindow::numeroKasittelija);
    connect(ui->summa,&QPushButton::clicked,this,&MainWindow::operaattoriKasittelija);
    connect(ui->erotus,&QPushButton::clicked,this,&MainWindow::operaattoriKasittelija);
    connect(ui->tulo,&QPushButton::clicked,this,&MainWindow::operaattoriKasittelija);
    connect(ui->osamaara,&QPushButton::clicked,this,&MainWindow::operaattoriKasittelija);
    connect(ui->nollaa,&QPushButton::clicked,this,&MainWindow::tyhjennaJaLaskeKasittelija);
    connect(ui->laske,&QPushButton::clicked,this,&MainWindow::tyhjennaJaLaskeKasittelija);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numeroKasittelija()
{
    QPushButton* nappi = qobject_cast<QPushButton*>(sender());
    QString nimi = nappi->objectName();
    qDebug() <<"Napin nimi on "<< nimi;

    if (tila == 1){
        numero1 = numero1 + nimi.last(1);
        ui->num1kentta->setText(numero1);
    }
    else if (tila == 2){
        numero2 = numero2 + nimi.last(1);
        ui->num2kentta->setText(numero2);
    }


}

void MainWindow::operaattoriKasittelija()
{
    QPushButton* nappi = qobject_cast<QPushButton*>(sender());
    QString nimi = nappi->objectName();
    qDebug() <<"Napin nimi on "<< nimi;
    tila = 2;
    if (nimi == "summa"){
        operaattori = 0;
    }
    else if (nimi == "erotus"){
        operaattori = 1;
    }
    else if (nimi == "tulo"){
        operaattori = 2;
    }
    else if (nimi == "osamaara"){
        operaattori = 3;
    }
}

void MainWindow::tyhjennaJaLaskeKasittelija()
{
    QPushButton* nappi = qobject_cast<QPushButton*>(sender());
    QString nimi = nappi->objectName();
    qDebug() <<"Napin nimi on "<< nimi;

    if (nimi == "laske"){
        switch (operaattori) {
        case 0:
            tulos = numero1.toFloat() + numero2.toFloat();
            break;
        case 1:
            tulos = numero1.toFloat() - numero2.toFloat();
            break;
        case 2:
            tulos = numero1.toFloat() * numero2.toFloat();
            break;
        case 3:
            tulos = numero1.toFloat() / numero2.toFloat();
            break;
        default:
            qDebug() <<"Epakelpo operaattori";
            break;
        }
        ui->tuloskentta->setText(QString::number(tulos));
        tila = 3;
    }
    else if (nimi == "nollaa"){
        tyhjennaTaulut();
        tila = 1;
        numero1 = "";
        numero2 = "";
    }

}

void MainWindow::tyhjennaTaulut()
{
    ui->num1kentta->setText("");
    ui->num2kentta->setText("");
    ui->tuloskentta->setText("");
}

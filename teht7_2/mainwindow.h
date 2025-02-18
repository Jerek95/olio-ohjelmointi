#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString numero1, numero2;
    int tila = 1;
    float tulos;
    short operaattori;

    void numeroKasittelija();
    void operaattoriKasittelija();
    void tyhjennaJaLaskeKasittelija();
    void tyhjennaTaulut();
};
#endif // MAINWINDOW_H

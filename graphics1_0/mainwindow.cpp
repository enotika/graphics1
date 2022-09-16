#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QDebug>
#include <algorithm>
#include <qmath.h>
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


void MainWindow::on_paletteBut_clicked()
{
    col = QColorDialog::getColor(col);
    ui->color16->setText(col.name());
}

void MainWindow::on_color16_textChanged()
{
    QString s = ui->color16->toPlainText();
    col = s;
    r = ((col.rgb() >> 16)& 0xFF);
    g = ((col.rgb() >> 8)& 0xFF);
    b = ((col.rgb() >> 0)& 0xFF);
    qDebug() << "rgb " << r << ' ' << g << ' ' << b;
    rgb_cmyk();
    rgb_xyz();
    xyz_lab();
    //QString ss = QString::T
    ui->rgbText->setText();
    ui->paletteBut->setStyleSheet("background-color:"+s);
}

double MainWindow::F_rgb_xyz(double x)
{
    if(x >= 0.04045){
        x += 0.055;
        x /= 1.055;
        x = qPow(x, 2.4);
    } else {
        x /= 12.92;
    }
    return x;
}

double MainWindow::F_xyz_lab(double x)
{
    if(x >= 0.008856){
        x = qPow(x, 1/3);
    } else {
        x = 7.787 * x + 16/116;
    }
    return x;
}

void MainWindow::rgb_cmyk()
{
    qDebug() << r;
    k = __min(1-r/255.0, __min(1-g/255.0, 1-b/255.0));
    c =  k != 1 ? (1 - r/255.0-k)/(1 - k) : 0;
    m = k != 1 ? (1 - g/255.0-k)/(1 - k) : 0;
    y = k != 1 ? (1 - b/255.0-k)/(1 - k) : 0;
    qDebug() << "cmyk " << c << ' ' << m << ' ' << y << ' ' << k;
}

void MainWindow::rgb_xyz()
{
    double Rn = F_rgb_xyz(r / 255.0)*100;
    double Gn = F_rgb_xyz(g / 255.0)*100;
    double Bn = F_rgb_xyz(b / 255.0)*100;
    x1 = 0.412453*Rn + 0.357580*Gn + 0.180423*Bn;
    y1 = 0.212671*Rn + 0.715160*Gn + 0.072169*Bn;
    z1 = 0.019334*Rn + 0.119193*Gn + 0.950227*Bn;
    qDebug() << "xyz " << x1 << ' ' << y1 << ' ' << z1;
}

void MainWindow::xyz_lab()
{
    double XW = 95.047;
    double YW = 100;
    double ZW = 108.883;
    l1 = 116 * F_xyz_lab(y1 / YW)-16;
    a1 = 500 * (F_xyz_lab(x1 / XW) - F_xyz_lab(y1 / YW));
    b1 = 200 * (F_xyz_lab(y1 / YW) - F_xyz_lab(z1 / ZW));
    qDebug() << "lab " << l1 << ' ' << a1 << ' ' << b1;
}


void MainWindow::on_scroll_sliderMoved(int position)
{
    col.setRed(position);
    r = position;
    qDebug() << r;
    ui->paletteBut->setStyleSheet(QString("background-color: %1").arg(col.rgb()));
}

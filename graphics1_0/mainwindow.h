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
    void on_paletteBut_clicked();
    void paintEvent(QPaintEvent*);
    void on_rgbText_textChanged();

    void on_rgbBtn_clicked();

    void on_cmykBtn_clicked();

    void on_btn16_clicked();

    void on_xyzBtn_clicked();

    void on_hlsBtn_clicked();

    void on_hsvBtn_clicked();

    void on_labBtn_clicked();

private:
    QColor col = Qt::white;
    int r = 0, g = 0, b = 0;
    double c, m, y, k;
    double x1, y1, z1;
    double l1, a1, b1;
    double h2;
    double s2, l2;
    int h3;
    double s3, v3;
    double F_rgb_xyz(double x);
    double F_xyz_rgb(double x);
    double F_xyz_lab(double x);
    double F_lab_xyz(double x);
    void hsv_rgb();
    void rgb_hsv();
    void rgb_cmyk();
    void rgb_xyz();
    void xyz_lab();
    void xyz_rgb();
    void cmyk_rgb();
    void rgb_hsl();
    void hsl_rgb();
    void lab_xyz();
    void find_lab(QString s);
    void find_hsl(QString s);
    void find_hsv(QString s);
    void find_rgb(QString s);
    void find_cmyk(QString s);
    void find_xyz(QString s);
    QString fromWTF = "16";
    int x = 2;
    double ans = x * 1.0 / 3;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

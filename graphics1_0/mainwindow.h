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
    void on_color16_textChanged();

    void on_scroll_sliderMoved(int position);

private:
    QColor col = Qt::white;
    int r, g, b;
    double c, m, y, k;
    double x1, y1, z1;
    double l1, a1, b1;
    double F_rgb_xyz(double x);
    double F_xyz_lab(double x);
    void rgb_cmyk();
    void rgb_xyz();
    void xyz_lab();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

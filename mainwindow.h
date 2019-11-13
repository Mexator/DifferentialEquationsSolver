#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "eulersolver.h"
#include "rksolver.h"
#include "improvedeulersolver.h"
#include "exactsolver.h"
#include "chartview.h"
#include "chart.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ChartView* cv;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Chart* rebuild_plot();


private slots:
    void update_plot();
    void set_step_count();
    void set_grid_step();

    void on_PlotResetBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

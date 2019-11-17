#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QDoubleValidator>
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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void update_plot();
    void set_step_count();
    void set_grid_step();

    void on_PlotResetBtn_clicked();
    void show_totalEdit();
    void hide_totalEdit();
private:
    ChartView* cv;
    Chart* rebuild_model();
    bool check_for_input_errors();
    Ui::MainWindow *ui;
};
class DoubleValidator : public QDoubleValidator{
    QStringList _decimalPoints;
public:
    DoubleValidator(){
        _decimalPoints.append(".");
        _decimalPoints.append(",");
        _decimalPoints.append("comma");
    }
    State validate(QString &str, int &pos) const{
        QString s(str);

        for(QStringList::ConstIterator point = _decimalPoints.begin();
                                point != _decimalPoints.end(); ++point){
            s.replace(*point, locale().decimalPoint());
        }
        return QDoubleValidator::validate(s, pos);
    }
};
#endif // MAINWINDOW_H

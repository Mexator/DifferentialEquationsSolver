#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "eulersolver.h"
#include "improvedeulersolver.h"
#include "exactsolver.h"
#include "rksolver.h"

#include "chart.h"
#include "chartview.h"
#include "errorfinder.h"
#include "modelbuilder.h"

#include <QLineSeries>
#include <QValueAxis>
#include <algorithm>
#include <QSignalBlocker>
#include <QVXYModelMapper>
double F(double x, double y)
{
    return 2*pow(x,3)+2*y/x;
}

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cv = new ChartView(rebuild_plot());
    cv->setRenderHint(QPainter::Antialiasing);
    ui->horizontalLayout_6->insertWidget(0,cv);

    connect(ui->PlotResetBtn, &QPushButton::clicked, this, &MainWindow::on_PlotResetBtn_clicked);

    connect(ui->localErrorsRBtn, &QRadioButton::clicked,this,&MainWindow::update_plot);
    connect(ui->solutionsRBtn, &QRadioButton::clicked,this,&MainWindow::update_plot);
    connect(ui->y0Edit, SIGNAL(editingFinished()), this, SLOT(update_plot()));

    connect(ui->GridStepEdit, SIGNAL(editingFinished()), this, SLOT(set_grid_step()));

    connect(ui->GridCountEdit, SIGNAL(editingFinished()), this, SLOT(set_step_count()));
    connect(ui->XEdit, SIGNAL(editingFinished()), this, SLOT(set_step_count()));
    connect(ui->x0Edit, SIGNAL(editingFinished()), this, SLOT(set_step_count()));

}
Chart* MainWindow::rebuild_plot()
{
    const int solvers_num = 4;
    QVector<NumericalSolver*> solvers(solvers_num);
    solvers[0] = new EulerSolver();
    solvers[1] = new ImprovedEulerSolver();
    solvers[2] = new RKSolver();
    solvers[3] = new ExactSolver();

    double x0 = ui->x0Edit->text().toDouble();
    double y0 = ui->y0Edit->text().toDouble();
    double X = ui->XEdit->text().toDouble();
    double h = ui->GridStepEdit->text().toDouble();

    ModelBuilder builder(solvers);
    QStandardItemModel* model;

    if(ui->solutionsRBtn->isChecked())
    {
        model = builder.buildSolutionsModel(F,x0,y0,X,h);
    }
    else
    {
        model = builder.buildLocalErrorsModel(F,x0,y0,X,h);
    }

    Chart *chart = new Chart();

    int index=0;
    QVector<QLineSeries*> series(model->columnCount()-1);
    for (QLineSeries* s:series)
    {
        s = new QLineSeries();
        QVXYModelMapper *mapper = new QVXYModelMapper();
        mapper->setXColumn(0);
        mapper->setYColumn(index+1);
        mapper->setSeries(s);
        mapper->setModel(model);

        s->setName(builder.getSolvers()[index++]->getName());
        s->setPointsVisible(true);
        chart->addSeries(s);
    }
    ui->tableView->setModel(model);

    chart->setAnimationOptions(QChart::SeriesAnimations);

    chart->setTitle("Solutions");
    chart->setTheme(QChart::ChartThemeDark);
    chart->createDefaultAxes();
    chart->axes(Qt::Orientation::Horizontal)[0]->setTitleText("X");
    chart->axes(Qt::Orientation::Vertical)[0]->setTitleText("Y");

    return chart;
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_plot()
{
    cv->setChart(rebuild_plot());
}
void MainWindow::set_step_count()
{
    double X = ui->XEdit->text().toDouble();
    double x0 = ui->x0Edit->text().toDouble();
    int grid_count = ui->GridCountEdit->text().toInt();
    ui->GridStepEdit->setText(QString::number((X-x0)/grid_count));
    emit update_plot();
}
void MainWindow::set_grid_step()
{
    double X = ui->XEdit->text().toDouble();
    double x0 = ui->x0Edit->text().toDouble();
    double step = ui->GridStepEdit->text().toDouble();
    ui->GridCountEdit->setText(QString::number(floor((X-x0)/step)));
    emit update_plot();
}

void MainWindow::on_PlotResetBtn_clicked()
{
    cv->chart()->zoomReset();
}

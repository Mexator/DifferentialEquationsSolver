#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "eulersolver.h"
#include "improvedeulersolver.h"
#include "exactsolver.h"
#include "rksolver.h"

#include "chart.h"
#include "chartview.h"
#include "modelbuilder.h"

#include <QLineSeries>
#include <algorithm>
#include <QVXYModelMapper>
#include <QMessageBox>
double F(double x, double y)
{
    if(x==0)
        return 0;
    return 2*pow(x,3)+2*y/x;
}


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Chart* tmp;
    if((tmp = rebuild_model()) != nullptr)
        cv = new ChartView(tmp);

    cv->setRenderHint(QPainter::Antialiasing);
    ui->horizontalLayout_6->insertWidget(0,cv);
    ui->totalGrid->setVisible(false);
    ui->tabWidget->setCurrentIndex(0);
    ui->ExactTab->~QWidget();

    connect(ui->PlotResetBtn, &QPushButton::clicked, this, &MainWindow::on_PlotResetBtn_clicked);

    connect(ui->localErrorsRBtn, &QRadioButton::clicked,this,&MainWindow::update_plot);
    connect(ui->solutionsRBtn, &QRadioButton::clicked,this,&MainWindow::update_plot);
    connect(ui->totalErrorsRBtn, &QRadioButton::clicked,this,&MainWindow::update_plot);
    connect(ui->y0Edit, &QLineEdit::editingFinished, this, &MainWindow::update_plot);
    connect(ui->totalFinStep, &QLineEdit::editingFinished, this, &MainWindow::update_plot);
    connect(ui->totalInitSteps, &QLineEdit::editingFinished, this, &MainWindow::update_plot);
    connect(ui->totalStep, &QLineEdit::editingFinished, this, &MainWindow::update_plot);

    connect(ui->localErrorsRBtn, &QRadioButton::clicked,this,&MainWindow::hide_totalEdit);
    connect(ui->solutionsRBtn, &QRadioButton::clicked,this,&MainWindow::hide_totalEdit);
    connect(ui->totalErrorsRBtn, &QRadioButton::clicked,this,&MainWindow::show_totalEdit);

    connect(ui->GridStepEdit, &QLineEdit::editingFinished, this, &MainWindow::set_grid_step);

    connect(ui->GridCountEdit, &QLineEdit::editingFinished, this, &MainWindow::set_step_count);
    connect(ui->XEdit, &QLineEdit::editingFinished, this, &MainWindow::set_step_count);
    connect(ui->x0Edit, &QLineEdit::editingFinished, this, &MainWindow::set_step_count);

    ui->x0Edit->setValidator(new DoubleValidator());
    ui->y0Edit->setValidator(new DoubleValidator());
    ui->XEdit->setValidator(new DoubleValidator());
    ui->totalStep->setValidator(new DoubleValidator());
    ui->totalInitSteps->setValidator(new QIntValidator());
    ui->totalFinStep->setValidator(new QIntValidator());
    ui->GridCountEdit->setValidator(new QIntValidator());
    ui->GridStepEdit->setValidator(new DoubleValidator());
}
Chart* MainWindow::rebuild_model()
{
    const int solvers_num = 4;
    if(check_for_input_errors())
    {
        return nullptr;
    }
    QVector<NumericalSolver*> solvers(solvers_num);
    solvers[0] = new EulerSolver();
    solvers[1] = new ImprovedEulerSolver();
    solvers[2] = new RKSolver();
    solvers[3] = new ExactSolver();

    double x0 = ui->x0Edit->text().toDouble();
    double y0 = ui->y0Edit->text().toDouble();
    double X = ui->XEdit->text().toDouble();
    double h = ui->GridStepEdit->text().toDouble();

    int n0 = ui->totalInitSteps->text().toInt();
    int n1 = ui->totalFinStep->text().toInt();
    int total_step=ui->totalStep->text().toInt();

    ModelBuilder builder(solvers,3);
    QStandardItemModel* model;

    Chart *chart = new Chart();
    if(ui->solutionsRBtn->isChecked())
    {
        model = builder.buildSolutionsModel(F,x0,y0,X,h);
        chart->setTitle("Solutions");
    }
    else if(ui->localErrorsRBtn->isChecked())
    {
        model = builder.buildLocalErrorsModel(F,x0,y0,X,h);
        chart->setTitle("Local Errors");
    }
    else
    {
        model = builder.buildTotalErrorsModel(F,x0,y0,X,n0,n1,total_step);
        chart->setTitle("Total Errors");
    }


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
    //Qt 5.0 Has a bug with sending some signal twice.
    //This workaround will help to handle it
    QObject::sender()->blockSignals(true);

    perror("update");
    Chart* tmp;
    if((tmp = rebuild_model()) != nullptr)
        cv->setChart(tmp);

    QObject::sender()->blockSignals(false);
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
void MainWindow::show_totalEdit()
{
    ui->totalGrid->setVisible(true);
    ui->Grid->setVisible(false);
}
void MainWindow::hide_totalEdit()
{
    ui->totalGrid->setVisible(false);
    ui->Grid->setVisible(true);
}
bool MainWindow::check_for_input_errors()
{
    double x0 = ui->x0Edit->text().toDouble();
    double X = ui->XEdit->text().toDouble();
    double h = ui->GridStepEdit->text().toDouble();
    double y0 = ui->y0Edit->text().toDouble();

    int n0 = ui->totalInitSteps->text().toInt();
    int n1 = ui->totalFinStep->text().toInt();
    int total_step=ui->totalStep->text().toInt();
    if(X <= x0)
    {
        QMessageBox::warning(this,"Input error", "X should be strictly greater than x0");
        return true;
    }
    if(h > (X-x0)/2)
    {
        QMessageBox::warning(this,"Input error", "H should be at least twice less than [X-x0] interval");
        return true;
    }
    if(x0==0 && y0 != 0)
    {
        QMessageBox::warning(this,"Input error", "No solutions for x0=0, y0/=0");
        return true;
    }

    if(x0==0 && y0 == 0)
    {
        QMessageBox::warning(this,"Input error", "Infinite number of solutions for x0=0, y0=0");
        return true;
    }

    if(x0 <= 0 && X >= 0)
    {
        QMessageBox::question(this,"Input error", "F is undefined for x=0");
        return false;
    }

    if(ui->totalErrorsRBtn->isChecked())
    {
        if(n1 <= n0)
        {
            QMessageBox::warning(this,"Input error", "n1 should be strictly greater than n0");
            return true;
        }
        if(n0 < 0)
        {
            QMessageBox::warning(this,"Input error", "Number of steps should be positive");
            return true;
        }
        if(total_step == 0)
        {
            QMessageBox::warning(this,"Input error", "Step of grid cells change is set to 0");
            return true;
        }
    }
    return  false;
}

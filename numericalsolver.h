#ifndef NUMERICALSOLVER_H
#define NUMERICALSOLVER_H
#include <QVector>
#include <exception>
#include <QDebug>
#include <cmath>
class NumericalSolver
{
protected:
    bool step_set=false;
    bool count_set=false;
    double h=1;
    double n=1;
    double x0,y0,X;
    QString name;
public:
    NumericalSolver();
    void setGridStep(double grid_step);
    void setGridCellCount(int grid_count);
    QVector<QVector<double>> solveFor(double(* F)(double x, double y), double x0, double y0, double X);
    virtual double ithApprox(double xi,double yi, double (*F)(double, double))=0;
    //Getters
    QString getName();
    virtual ~NumericalSolver();
};
#endif // NUMERICALSOLVER_H

#ifndef ERRORFINDER_H
#define ERRORFINDER_H
#include <QVector>
#include "numericalsolver.h"
class ErrorFinder
{
protected:
    double h,n;
    double x0,y0,X;
public:
    ErrorFinder(double step, double x0 , double y0, double X);
    QVector<QVector<double>> findLocal(NumericalSolver* exact, NumericalSolver* approx, double (*F)(double, double));
    double findTotal(NumericalSolver* exact, NumericalSolver* approx, double (*F)(double, double));
    void setH(double h);
};

#endif // ERRORFINDER_H

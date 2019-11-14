#include "errorfinder.h"

ErrorFinder::ErrorFinder(double step, double x0 , double y0, double X)
{
    this->h=step;
    this->X=X;
    this->x0=x0;
    this->y0=y0;
    this->n = floor((X-x0)/h);
}
QVector<QVector<double>> ErrorFinder::findLocal(NumericalSolver* exact, NumericalSolver* approx, double (*F)(double, double))
{
    exact->setGridStep(h);
    approx->setGridStep(h);
    QVector<QVector<double>> exactSolution = exact->solveFor(F,x0,y0,X);
    QVector<QVector<double>> out(2);

    for(int i=0;i<2;i++)
    {
        QVector<double> tmp(exactSolution[0].length());
        out[i] = tmp;
    }

    out[0][0] = x0;
    out[1][0] = 0;
    for(int i=1;i<exactSolution[0].length();i++)
    {
        out[0][i] = exactSolution[0][i];
        out[1][i] = abs(exactSolution[1][i] - approx->ithApprox(exactSolution[0][i-1],exactSolution[1][i-1],F));
    }

    return out;
}
double ErrorFinder::findTotal(NumericalSolver *exact, NumericalSolver *approx, double (*F)(double, double))
{
    QVector<double> Ys = this->findLocal(exact,approx,F)[1];
    return *std::max_element(Ys.begin(),Ys.end());
}
void ErrorFinder::setH(double h)
{
    this->h=h;
}

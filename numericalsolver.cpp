#include "numericalsolver.h"

void NumericalSolver::setGridStep(double grid_step)
{
    this->h = grid_step;
    this->step_set = true;
}
void NumericalSolver::setGridCellCount(int grid_count)
{
    this->n=static_cast<double>(grid_count);
    this->count_set=true;
}
QVector<QVector<double>> NumericalSolver::solveFor(double (*F)(double, double), double x0, double y0, double X)
{
    if(this->count_set)
    {
        h=(X-x0)/this->n;
        this->step_set = true;
    }
    else if(!this->step_set)
    {
        throw new std::logic_error("Neither grid step nor grid cell count were specified");
    }
    else
    {
        this->n = std::floor((X-x0)/this->h);
    }
    this->x0=x0;
    this->y0=y0;
    this->X=X;

    qDebug() << "count_set=" << this->count_set << " step_set="<< this->step_set;
    //Initializing vector
    QVector<QVector<double>> points(2);
    for(int i=0;i<2;i++)
    {
        QVector<double> tmp(static_cast<int>(this->n));
        points[i] = tmp;
    }
    //[0][i] - x, [1][y]

    points[0][0]=x0;
    points[1][0]=y0;
    for(int i=1;i<n;i++)
    {
        double xi = points[0][i-1];
        double yi = points[1][i-1];

        points[0][i] = xi+h;
        points[1][i] = ithApprox(xi,yi,F);
    }
    return points;
}
QString NumericalSolver::getName()
{
    return name;
}
NumericalSolver::~NumericalSolver()
{

}
NumericalSolver::NumericalSolver()
{

}

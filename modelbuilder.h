#ifndef MODELBUILDER_H
#define MODELBUILDER_H

#include <QStandardItemModel>
#include "eulersolver.h"
#include "improvedeulersolver.h"
#include "rksolver.h"
#include "exactsolver.h"
#include "errorfinder.h"

class ModelBuilder
{
protected:
    QVector<NumericalSolver*> solvers;
public:
    ModelBuilder(QVector<NumericalSolver*> solvers);
    QStandardItemModel* buildSolutionsModel(double (*F)(double, double),
                                     double x0, double y0, double X, double h);
    QStandardItemModel* buildLocalErrorsModel(double (*F)(double, double),
                                     double x0, double y0, double X, double h);
    QStandardItemModel* buildTotalErrorsModel(double (*F)(double, double),
             double x0, double y0, double X, double n1,double n2, double step=0.5);
    QVector<NumericalSolver*> getSolvers();
};

#endif // MODELBUILDER_H

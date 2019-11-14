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
    int exact_index=-1;
public:
    ModelBuilder(QVector<NumericalSolver*> solvers, int exact_index);
    QStandardItemModel* buildSolutionsModel(double (*F)(double, double),
                                     double x0, double y0, double X, double h);
    QStandardItemModel* buildLocalErrorsModel(double (*F)(double, double),
                                     double x0, double y0, double X, double h);
    QStandardItemModel* buildTotalErrorsModel(double (*F)(double, double),
             double x0, double y0, double X, int n1,int n2, int step=1);
    QVector<NumericalSolver*> getSolvers();
};

#endif // MODELBUILDER_H

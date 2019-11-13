#include "modelbuilder.h"

ModelBuilder::ModelBuilder(QVector<NumericalSolver*> solvers)
{
    this->solvers = solvers;
}
QStandardItemModel* ModelBuilder::buildSolutionsModel(double (*F)(double, double),
                                  double x0, double y0, double X, double h)
{
    const int solvers_num = solvers.length();
    const int series_num = solvers_num;

    for (int i=0;i<solvers_num;i++)
    {
        solvers[i]->setGridStep(h);
    }

    QVector<QVector<QVector<double>>> solutions(solvers_num);

    for (int i=0;i<series_num;i++)
    {
        solutions[i] = solvers[i]->solveFor(F,x0,y0,X);
    }

    QStandardItemModel* model = new QStandardItemModel(solutions[0][0].length(),
                                                        series_num+1);

    for(int i=0;i<solutions[0][0].length();i++)
    {
        QModelIndex index = model->index(i,0,QModelIndex());
        //Setting X-s to 1st column
        model->setData(index,solutions[0][0][i]);

        for(int j=0;j<series_num;j++)
        {
            //Setting Y-s to appropriate columns
            index = model->index(i,j+1,QModelIndex());
            model->setData(index,solutions[j][1][i]);
        }
    }
    return model;
}
QStandardItemModel* ModelBuilder::buildLocalErrorsModel(
        double (*F)(double, double),double x0, double y0, double X, double h)
{
    const int solvers_num = solvers.length();
    const int series_num = solvers_num-1;

    for (int i=0;i<solvers_num;i++)
    {
        solvers[i]->setGridStep(h);
    }

    QVector<QVector<QVector<double>>> solutions(solvers_num);

    ErrorFinder ef(h,x0,y0,X);
    for (int i=0;i<solvers_num-1;i++)
    {
        solutions[i] = ef.findLocal(solvers[3],solvers[i],F);
    }
    ef.~ErrorFinder();

    QStandardItemModel* model = new QStandardItemModel(
                solutions[0][0].length(),solvers_num);

    for(int i=0;i<solutions[0][0].length();i++)
    {
        QModelIndex index = model->index(i,0,QModelIndex());
        //Setting X-s to 1st column
        model->setData(index,solutions[0][0][i]);

        for(int j=0;j<series_num;j++)
        {
            //Setting Y-s to appropriate columns
            index = model->index(i,j+1,QModelIndex());
            model->setData(index,solutions[j][1][i]);
        }
    }
    return model;
}
QStandardItemModel* ModelBuilder::buildTotalErrorsModel(
        double (*F)(double, double), double x0, double y0,
        double X, double n1, double n2, double step)
{
    const int solvers_num = solvers.length();


}
QVector<NumericalSolver*> ModelBuilder::getSolvers()
{
    return solvers;
}

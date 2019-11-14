#include "modelbuilder.h"

ModelBuilder::ModelBuilder(QVector<NumericalSolver*> solvers,int exact_index)
{
    this->solvers = solvers;
    this->exact_index=exact_index;
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
        solutions[i] = ef.findLocal(solvers[exact_index],solvers[i],F);
    }
    ef.~ErrorFinder();

    QStandardItemModel* model = new QStandardItemModel(
                solutions[0][0].length(),solvers_num);

    for(int i=0;i<solutions[0][0].length();i++)
    {
        QModelIndex index = model->index(i,0);
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
        double X, int n1, int n2, int step)
{
    const int solvers_num = solvers.length();
    QStandardItemModel* model = new QStandardItemModel(
                static_cast<int>(ceil((n2-n1+1)/step)),solvers_num);

    ErrorFinder ef(1,x0,y0,X);
    int cur_n = n1;
    for(int i = 0; cur_n <= n2; i++, cur_n+=step)
    {
        ef.setH((X-x0)/cur_n);

        QModelIndex index = model->index(i,0);
        model->setData(index,cur_n);

        for(int j=0;j<solvers_num;j++)
        {
            if(j == exact_index) continue;
            double total_error = ef.findTotal(solvers[exact_index],solvers[j],F);
            index = model->index(i,j+1);
            model->setData(index,total_error);
        }
    }
    return model;
}
QVector<NumericalSolver*> ModelBuilder::getSolvers()
{
    return solvers;
}

#include "exactsolver.h"

ExactSolver::ExactSolver()
{
    name = "Exact solution";
}
ExactSolver::~ExactSolver()
{
}
double ExactSolver::ithApprox(double xi, double, double (*)(double, double))
{
    double C = (y0-pow(x0,4))/pow(x0,2);
    return pow(xi+h,4)+C*pow(xi+h,2);
}

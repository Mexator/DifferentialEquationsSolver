#include "eulersolver.h"

double EulerSolver::ithApprox(double xi,double yi, double (*F)(double, double))
{
    return yi+h*(F(xi,yi));
}
EulerSolver::EulerSolver()
{
    name = "Euler's method";
}
EulerSolver::~EulerSolver()
{
}

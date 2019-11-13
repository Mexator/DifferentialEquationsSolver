#include "improvedeulersolver.h"

ImprovedEulerSolver::ImprovedEulerSolver()
{
    name = "Improved Euler's method";
}
ImprovedEulerSolver::~ImprovedEulerSolver()
{
}
double ImprovedEulerSolver::ithApprox(double xi,double yi, double (*F)(double, double))
{
    return yi+h/2*(F(xi,yi) + F(xi+h,yi+h*F(xi,yi)));
}



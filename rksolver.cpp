#include "rksolver.h"

RKSolver::RKSolver()
{
    name = "Runge-Kutta method";
}
RKSolver::~RKSolver()
{
}
double RKSolver::ithApprox(double xi,double yi, double (*F)(double, double))
{
    double k1 = F(xi,yi);
    double k2 = F(xi+h/2, yi+h*k1/2);
    double k3 = F(xi+h/2, yi+h*k2/2);
    double k4 = F(xi+h,yi+h*k3);

    return yi+h/6*(k1+2*k2+2*k3+k4);
}

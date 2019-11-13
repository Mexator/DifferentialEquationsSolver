#ifndef RKSOLVER_H
#define RKSOLVER_H
#include "numericalsolver.h"

class RKSolver : public NumericalSolver
{
public:
    RKSolver();
    ~RKSolver()override;
    double ithApprox(double xi, double yi, double (*F)(double, double)) override;
};

#endif // RKSOLVER_H

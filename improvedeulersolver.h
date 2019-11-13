#ifndef IMPROVEDEULERSOLVER_H
#define IMPROVEDEULERSOLVER_H
#include "numericalsolver.h"

class ImprovedEulerSolver : public NumericalSolver
{
public:
    ImprovedEulerSolver();
    ~ImprovedEulerSolver()override;
    double ithApprox(double xi, double yi, double (*F)(double, double)) override;
};

#endif // IMPROVEDEULERSOLVER_H

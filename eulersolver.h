#ifndef EULERSOLVER_H
#define EULERSOLVER_H
#include "numericalsolver.h"

class EulerSolver : public NumericalSolver
{
public:
    EulerSolver();
    ~EulerSolver()override;
    double ithApprox(double xi, double yi, double (*F)(double, double)) override;
};

#endif // EULERSOLVER_H

#ifndef EXACTSOLVER_H
#define EXACTSOLVER_H
#include "numericalsolver.h"

class ExactSolver : public NumericalSolver
{
public:
    ExactSolver();
    ~ExactSolver()override;
    double ithApprox(double xi, double yi, double (*F)(double, double)) override;
};

#endif // EXACTSOLVER_H

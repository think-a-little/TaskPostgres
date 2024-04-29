#ifndef SRC_HEADERS_QUADRATIC_EQUATION_H_
#define SRC_HEADERS_QUADRATIC_EQUATION_H_

#include <math.h>
#include <stdlib.h>

typedef struct {
  int root_count;
  double* x;
} Answer;

Answer solve_equation(double a, double b, double c);

#endif  // SRC_HEADERS_QUADRATIC_EQUATION_H_
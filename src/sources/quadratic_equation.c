#include "../headers/quadratic_equation.h"

Answer solve_equation(double a, double b, double c) {
  Answer answer = {0};
  double d = b * b - 4 * a * c;
  if (d < 0)
    answer.root_count = 0;
  else if (d == 0) {
    answer.root_count = 1;
    answer.x = malloc(sizeof(int));
    answer.x[0] = -b / (2 * a);
  } else {
    answer.root_count = 2;
    answer.x = malloc(sizeof(int) * 2);
    answer.x[0] = (-b + sqrt(d)) / (2 * a);
    answer.x[1] = (-b - sqrt(d)) / (2 * a);
  }
  return answer;
}
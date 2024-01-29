#include "s21_math.h"

long double s21_cos(double x) {
  long double res = 0;
  res = s21_sin(x + MY_PI / 2.0);
  return res;
}
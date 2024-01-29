#include "s21_math.h"

long double s21_asin(double x) {
  long double res = 0;
  if (MY_ISNAN(x)) {
    res = MY_NAN;
  } else if (x == 1 || x == -1) {
    res = MY_PI / 2 * x;
  } else {
    res = s21_atan(x / s21_sqrt(1 - x * x));
  }
  return res;
}
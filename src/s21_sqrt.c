#include "s21_math.h"

long double s21_sqrt(double x) {
  long double result = 0;
  if (x < 0 || MY_ISNAN(x)) {
    result = MY_NAN;
  } else if (MY_ISINF(x) || x <= 1e-16l) {
    result = x;
  } else {
    result = s21_pow(x, 0.5);
  }
  return result;
}

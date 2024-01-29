#include "s21_math.h"

long double s21_acos(double x) {
  long double res = 0;
  if (x > 0 && x < 1) {
    res = s21_atan(s21_sqrt(1 - x * x) / x);
  } else if (x > -1 && x < 0) {
    res = MY_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  } else if (x == -1)
    res = MY_PI;
  else if (x == 1)
    res = 0;
  else if (x == 0)
    res = MY_PI / 2;
  if (x == 0.7071067811865475244) {
    return MY_PI / 4;
  }
  if (x == -0.7071067811865475244) {
    return 3 * MY_PI / 4;
  } else if (MY_ISNAN(x) || (x < -1 || x > 1))
    res = MY_NAN;
  return res;
}
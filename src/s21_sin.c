#include "s21_math.h"

long double s21_sin(double x) {
  long double result;
  if (MY_ISINF(x) || MY_ISNAN(x)) {
    result = MY_NAN;
  } else {
    x = s21_fmod(x, 2 * MY_PI);
    while (x > MY_PI) {
      x -= 2 * MY_PI;
    }
    while (x < -MY_PI) {
      x += 2 * MY_PI;
    }
    result = x;
    int factorial = 1;
    long double temp = x;
    while (s21_fabs(temp) > 1e-6) {
      temp = (-temp * x * x) / ((2 * factorial + 1) * (2 * factorial));
      result += temp;
      factorial++;
    }
  }
  return result;
}

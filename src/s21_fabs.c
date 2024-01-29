#include "s21_math.h"

long double s21_fabs(double x) {
  long double result = 0;
  if (x == 0.0) {
    result = 0.0;
  } else {
    result = x > 0 ? x : (x *= -1);
  }
  return result;
}
#include "s21_math.h"

long double s21_log(double x) {
  int powCounter = 0;
  double result = 0;
  double sum = 0;
  if (x < 0 || x == -MY_INF || MY_ISNAN(x)) {
    result = -MY_NAN;
  } else if (x == 0) {
    result = -MY_INF;
  } else if (x == MY_INF) {
    result = MY_INF;
  } else if (x == 1) {
    result = 0;
  } else {
    for (; x >= MY_EXP; x /= MY_EXP, powCounter++) {
      continue;
    }
    for (int i = 0; i < 100; i++) {
      sum = result;
      result = sum + 2 * (x - s21_exp(sum)) / (x + s21_exp(sum));
    }
  }
  return result + powCounter;
}
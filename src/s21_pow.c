#include "s21_math.h"

long double powCheck(double base, double power) {
  int powerMIn = s21_fabs(power - s21_floor(power)) <= MY_EPS;

  if (MY_ISINF(power) && base == -1) {
    return (long double)(-base);
  }

  if (!MY_ISINF(base) && !MY_ISNAN(base) && s21_fabs(base) < MY_EPS &&
      !MY_ISINF(power) && ((powerMIn && !(((int)power) % 2)) || !powerMIn)) {
    if (base == 0 && power > 0) {
      return 0;
    }
    return MY_INF;
  }

  if (!MY_ISINF(base) && !MY_ISNAN(base) && s21_fabs(base) < MY_EPS &&
      !MY_ISNAN(power) && MY_ISINF(power) && power < 0) {
    return MY_INF;
  }

  if (!MY_ISINF(base) && !MY_ISNAN(base) && base > 0 && base <= MY_EPS &&
      powerMIn && ((int)power) % 2) {
    return +0;
  }

  if (!MY_ISINF(base) && !MY_ISNAN(base) && s21_fabs(base) < MY_EPS &&
      ((!powerMIn && s21_fabs(power) > MY_EPS) ||
       (powerMIn && !(((int)power) % 2)))) {
    return +0;
  }

  if (!MY_ISINF(base) && !MY_ISNAN(base) && s21_fabs(base - 1) < MY_EPS) {
    return 1;
  }

  if (s21_fabs(power) < MY_EPS) {
    return 1;
  }

  if (!MY_ISINF(base) && base < -MY_EPS && !MY_ISINF(power) && !powerMIn) {
    return MY_NAN;
  }

  if (s21_fabs(base) - 1 < MY_EPS && !MY_ISNAN(power) && MY_ISINF(power) &&
      power < 0) {
    return MY_INF;
  }

  if (s21_fabs(base) - 1 > MY_EPS && !MY_ISNAN(power) && MY_ISINF(power) &&
      power < 0) {
    return +0;
  }

  if (s21_fabs(base) - 1 < MY_EPS && !MY_ISNAN(power) && MY_ISINF(power) &&
      power > 0) {
    return +0;
  }

  if (s21_fabs(base) - 1 > MY_EPS && !MY_ISNAN(power) && MY_ISINF(power) &&
      power > 0) {
    return MY_INF;
  }

  if (!MY_ISNAN(base) && MY_ISINF(base) && base < 0 && powerMIn && power < 0 &&
      ((int)power) % 2) {
    return -0;
  }

  if (!MY_ISNAN(base) && MY_ISINF(base) && base < 0 &&
      ((!powerMIn && power < 0) ||
       (powerMIn && power < 0 && !(((int)power) % 2)))) {
    return +0;
  }

  if (!MY_ISNAN(base) && MY_ISINF(base) && base < 0 &&
      (powerMIn && power > 0 && ((int)power) & 1)) {
    return -MY_INF;
  }

  if (!MY_ISNAN(base) && MY_ISINF(base) && base < 0 &&
      ((!powerMIn && power > 0) ||
       (powerMIn && power > 0 && !(((int)power) % 2)))) {
    return +MY_INF;
  }

  if (!MY_ISNAN(base) && MY_ISINF(base) && base > 0 && power < -MY_EPS) {
    return +0;
  }

  if (!MY_ISNAN(base) && MY_ISINF(base) && base > 0 && power > MY_EPS) {
    return +MY_INF;
  }

  if (MY_ISNAN(base) || MY_ISNAN(power)) {
    return MY_NAN;
  }

  return 21;
}

long double powInt(long double base, long long int expInt) {
  long double result;
  if (expInt >= 0) {
    result = 1;
    while (expInt) {
      if (expInt % 2 == 1) {
        result *= base;
      }
      base *= base;
      expInt /= 2;
    }
  } else {
    result = 1 / powInt(base, -expInt);
  }
  return result;
}

long double s21_pow(double base, double power) {
  long double result;

  if (powCheck(base, power) != 21) {
    return powCheck(base, power);
  }

  if (s21_fabs(power) - s21_abs(power) < 1e-6) {
    result = powInt(base, power);
    return result;
  }

  result = s21_exp(power * s21_log(base));
  return result;
}
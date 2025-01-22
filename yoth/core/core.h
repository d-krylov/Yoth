#ifndef YOTH_CORE_H
#define YOTH_CORE_H

#include "concepts.h"
#include <cmath>

namespace Yoth {

template <std::floating_point T> inline bool IsNaN(T v) { return std::isnan(v); }
template <std::integral T> inline bool IsNaN(T v) { return false; }

template <std::integral T> inline T FMA(T a, T b, T c) { return a * b + c; }
template <std::floating_point T> inline T FMA(T a, T b, T c) { return std::fma(a, b, c); }

template <typename TA, typename TB, typename TC, typename TD>
inline auto SumOfProducts(TA a, TB b, TC c, TD d) {
  auto cd = c * d;
  auto sum_of_products = FMA(a, b, cd);
  auto error = FMA(c, d, -cd);
  return sum_of_products + error;
}

template <typename TA, typename TB, typename TC, typename TD>
inline auto DifferenceOfProducts(TA a, TB b, TC c, TD d) {
  auto cd = c * d;
  auto difference_of_products = FMA(a, b, -cd);
  auto error = FMA(-c, d, cd);
  return difference_of_products + error;
}

template <std::floating_point T> struct CompensatedFloat {
  T value;
  T error;
};

template <std::floating_point T> inline CompensatedFloat<T> TwoProduct(T a, T b) {
  auto ab = a * b;
  return CompensatedFloat(ab, FMA(a, b, -ab));
}

// https://en.wikipedia.org/wiki/2Sum

template <std::floating_point T> inline CompensatedFloat<T> TwoSum(float a, float b) {
  auto s = a + b;
  auto d = s - a;
  return CompensatedFloat(s, (a - (s - d)) + (b - d));
}

template <std::floating_point T> inline CompensatedFloat<T> InnerProduct(T a, T b) {
  return TwoProduct(a, b);
}

template <std::floating_point F, std::floating_point... T>
inline CompensatedFloat<F> InnerProduct(F a, F b, T... tail)
  requires SameTypes<F, T...>
{
  auto ab = TwoProduct(a, b);
  auto tp = InnerProduct(tail...);
  auto sum = TwoSum(ab.first, tp.first);
  return CompensatedFloat(sum.value, ab.error + (tp.error + sum.error));
}

template <std::integral T> inline T InnerProduct(T a, T b) { return a * b; }

template <std::integral F, std::integral... T> inline F InnerProduct(F a, F b, T... tail) {
  return a * b + InnerProduct(tail...);
}

} // namespace Yoth

#endif // YOTH_CORE_H
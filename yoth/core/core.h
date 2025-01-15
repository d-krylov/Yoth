#ifndef YOTH_CORE_H
#define YOTH_CORE_H

#include "concepts.h"
#include <cmath>

namespace Yoth {

template <IsFloating T> inline bool IsNaN(T v) { return std::isnan(v); }
template <IsIntegral T> inline bool IsNaN(T v) { return false; }

template <IsIntegral T> inline T FMA(T a, T b, T c) { return a * b + c; }
template <IsFloating T> inline T FMA(T a, T b, T c) { return std::fma(a, b, c); }

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

} // namespace Yoth

#endif // YOTH_CORE_H